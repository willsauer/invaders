/*
 *  PlayState.h
 *  Normal "play" state
 *
 *  Created by Marcelo Cohen on 04/11.
 *  Copyright 2011 PUCRS. All rights reserved.
 *
 */

#ifndef PLAY_STATE_H_
#define PLAY_STATE_H_

#include <SDL.h>
#include <vector>
#include <algorithm>
#include "CGameState.h"
#include "CSprite.h"
#include "CSound.h"
#include "maploader/TMXLoader.h"

#define ENEMIES_LIMIT 13

using namespace std;

class PlayState : public CGameState
{
    public:

    void init();
    void cleanup();

    void pause();
    void resume();

    void handleEvents(CGame* game);
    void update(CGame* game);
    void draw(CGame* game);

    // Implement Singleton Pattern
    static PlayState* instance()
    {
        return &m_PlayState;
    }

    protected:

    PlayState() {}

    private:

    static PlayState m_PlayState; // singleton

    int count,next,vertical,bug_speed;
    float dirx, diry; // movement direction

    bool won,defeated;
    vector<int> destroyed;
    CSound *snd;
    CImage *background;
    CSprite *enemies[12];
    CSprite *player;  // player image
	CSprite *bullet;
    Uint8 *keyState;  // array to store keyboard state
};

#endif
