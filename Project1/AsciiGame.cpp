﻿#include "AsciiGame.h"

//! Ctor
/*
 * init the game window properties
 * init gameObject pools
 */
AsciiGame::AsciiGame() : m_isRunning(false)
{
	/* game window */
	m_hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	m_dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	m_dwBufferCoord = { 0, 0 };
	m_rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	SetConsoleWindowInfo(m_hOutput, true, p_rcRegion);

	/* GameObject pools */
	m_mobs = new GameObject* [MOBS_COUNT];
	m_bullets = new GameObject* [BULLETS_COUNT];
	//m_player = new 
}

//! Dtor
AsciiGame::~AsciiGame()
{
	for (int i = 0; i < MOBS_COUNT; ++i)
	{
		delete[] m_mobs[i];
	}
	for (int i = 0; i < BULLETS_COUNT; ++i)
	{
		delete[] m_bullets[i];
	}
	delete p_rcRegion;
	delete m_player;
}

//! start the game
/*
 * launch the game instance
 */
void AsciiGame::start()
{
	m_isRunning = true;
	m_timer.start();
	while (m_isRunning){
		handleInputs();
		update(m_timer.getElapsedMs());
		render(m_timer.getElapsedMs());
	}
}

//! render the window
/*
* clear the portion of the game window that aren't up-to-date and draw on top the new context
*/
void AsciiGame::render(unsigned long timeElapsed)
{
	clear();
	ReadConsoleOutput(m_hOutput, (CHAR_INFO *)m_buffer, m_dwBufferSize,
		m_dwBufferCoord, &m_rcRegion);

	for (size_t i = 0; i < SCREEN_WIDTH; i++)
	{
		for (size_t j = 0; j < SCREEN_HEIGHT; j++)
		{
			m_buffer[j][i].Char.AsciiChar = '.';
			m_buffer[j][i].Attributes = 0x0E;
		}
	}

	WriteConsoleOutput(m_hOutput, (CHAR_INFO *)m_buffer, m_dwBufferSize, m_dwBufferCoord, &m_rcRegion);
}

//! clear
/*
* clear a portion of the game Window
*/
void AsciiGame::clear()
{

}

//! handle inputs
/*
* command pattern tied to the player game object
*/
void AsciiGame::handleInputs()
{

}

//! update game objects
/*
* run through all game object and update there components (AI, position)
*/
void AsciiGame::update(unsigned long timeElapsed){
	
}