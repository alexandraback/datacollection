//
//  main.cpp
//  Google Code Jam 2013
//
//  Created by Kristopher Giesing on 4/12/13.
//  Copyright (c) 2013 Kristopher Giesing. All rights reserved.
//

#include <iostream>
#include <fstream>

enum Outcome {
	DRAW,
	INCOMPLETE,
	X_WON,
	O_WON
};

#define DIMENSION 4
typedef char GameState[DIMENSION][DIMENSION];

class Game {
public:
	Game() {}

	Outcome analyze();
	
	void checkSequence(char sequence[DIMENSION], Outcome &ioOutcome);

	GameState mGameState;
};

void
Game::checkSequence(char sequence[DIMENSION], Outcome &ioOutcome)
{
	char winner = 0;
	for (int i = 0; i < DIMENSION; i++) {
		char move = sequence[i];
		if (move == '.') {
			// No winner, unfilled space
			winner = 0;
			if (ioOutcome == DRAW) {
				ioOutcome = INCOMPLETE;
			}
			break;
		} else if (winner == 0 && move != 'T') {
			// We have a candidate winner
			winner = move;
		} else if (winner != move && move != 'T') {
			// No winner, competing moves
			winner = 0;
			break;
		}
	}
	if (winner != 0) {
		ioOutcome = (winner == 'X') ? X_WON : O_WON;
	}
}

Outcome
Game::analyze()
{
	Outcome result = DRAW;
	// Check for winning rows
	for (int row = 0; row < DIMENSION; row++) {
		char sequence[DIMENSION];
		for (int i = 0; i < DIMENSION; i++) {
			sequence[i] = mGameState[row][i];
		}
		checkSequence(sequence, result);
		if (result > INCOMPLETE) return result;
	}
	// Check for winning columns
	for (int col = 0; col < DIMENSION; col++) {
		char sequence[DIMENSION];
		for (int i = 0; i < DIMENSION; i++) {
			sequence[i] = mGameState[i][col];
		}
		checkSequence(sequence, result);
		if (result > INCOMPLETE) return result;
	}
	// Check for winning diagonal, top-left to bottom-right
	{
		char sequence[DIMENSION];
		for (int i = 0; i < DIMENSION; i++) {
			sequence[i] = mGameState[i][i];
		}
		checkSequence(sequence, result);
		if (result > INCOMPLETE) return result;
	}
	// Check for winning diagonal, top-right to bottom-left
	{
		char sequence[DIMENSION];
		for (int i = 0; i < DIMENSION; i++) {
			sequence[i] = mGameState[i][DIMENSION-(i+1)];
		}
		checkSequence(sequence, result);
	}
	return result;
}

int main(int argc, const char * argv[])
{
	std::ifstream input(argv[1]);
	int nTests;
	input >> nTests;
	for (int i = 0; i < nTests; i++) {
		Game g;
		for (int row = 0; row < DIMENSION; row++) {
			for (int col = 0; col < DIMENSION; col++) {
				input >> g.mGameState[row][col];
			}
		}
		std::cout << "Case #" << (i+1) << ": ";
		Outcome outcome = g.analyze();
		switch (outcome) {
			case DRAW:
				std::cout << "Draw";
				break;
			case INCOMPLETE:
				std::cout << "Game has not completed";
				break;
			case X_WON:
				std::cout << "X won";
				break;
			case O_WON:
				std::cout << "O won";
				break;
		}
		std::cout << "\n";
	}

    return 0;
}
