#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

typedef enum {
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NUM_MOVE_TYPES
} MoveType;

void deltaCalc(vector<MoveType> &moves, int delta, MoveType up, MoveType down, int &jumpNum) {
	if (delta > 0) {
		while (delta - jumpNum >= 0) {
			moves.push_back(up);
			delta -= jumpNum;
			++jumpNum;
		}

		if (2 * delta < jumpNum) {
			for (int i = 0; i < delta; ++i) {
				moves.push_back(down);
				moves.push_back(up);
			}

			jumpNum += delta * 2;
		}
		else {
			moves.push_back(up);
			delta = jumpNum - delta;

			for (int i = 0; i < delta; ++i) {
				moves.push_back(up);
				moves.push_back(down);
			}

			jumpNum += delta * 2 + 1;
		}
	}
}

int main(int argc, const char *argv[])
{
	int numCases = 0;
	string temp;
	int deltaX = 0;
	int deltaY = 0;

	vector<MoveType> moves;
	moves.reserve(500);

	cin >> numCases;
	getline(cin, temp);

	for (int i = 0; i < numCases; ++i) {
		cin >> deltaX >> deltaY;
		getline(cin, temp);
		int jumpNum = 1;
		moves.clear();

		if (deltaX > 0) {
			deltaCalc(moves, deltaX, EAST, WEST, jumpNum);
		}
		else if (deltaX < 0) {
			deltaCalc(moves, -deltaX, WEST, EAST, jumpNum);
		}

		if (deltaY > 0) {
			deltaCalc(moves, deltaY, NORTH, SOUTH, jumpNum);
		}
		else if (deltaY < 0) {
			deltaCalc(moves, -deltaY, SOUTH, NORTH, jumpNum);
		}

		cout << "Case #" << (i + 1) << ": ";
		for (MoveType mt : moves) {
			switch (mt) {
				case NORTH:
					cout << 'N';
					break;
				case SOUTH:
					cout << 'S';
					break;
				case EAST:
					cout << 'E';
					break;
				case WEST:
					cout << 'W';
					break;
			}
		}
		cout << endl;
	}

	return 0;
}
