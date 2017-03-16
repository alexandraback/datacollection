
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <list>
#include <memory>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Game {
public:
	vector<vector<char>> board;
	bool possible = true;
	Game(int R, int C) : board(R, vector<char>(C, '?')) {}
};

void fill(int R, int C) {
	ofstream input("C:/users/sebastien/Downloads/example.in");
	input << R*C - 1 << "\n";
	for (int M = 0; M < R*C; ++M) {
		input << R << " " << C << " " << M << "\n";
	}
}

int main(int argc, char* argv[])
{
//	fill(5, 7);
	ifstream input("C:/users/sebastien/Downloads/C-large.in");
//	ifstream input("C:/users/sebastien/Downloads/example.in");
	ofstream output("C:/users/sebastien/Downloads/output.txt");

	output.precision(16);

	int T;
	input >> T;

	for (int test = 1; test <= T; ++test) {
		cout << "test " << test << "\n";
		output << "Case #" << test << ":\n";

		int R, C, M;
		input >> R;
		input >> C;
		input >> M;
		Game game(R, C);
		const int S = R*C;
		if (C == 1) {
			for (int i = 0; i < R; ++i) {
				if(i < M) game.board[i][0] = '*';
				else game.board[i][0] = '.';
			}
			game.board[R - 1][C - 1] = 'c';
		}
		else if (R == 1) {
			for (int j = 0; j < C; ++j) {
				if (j < M) game.board[0][j] = '*';
				else game.board[0][j] = '.';
			}
			game.board[R-1][C - 1] = 'c';
		}
		else if (C == 2) {
			if (M == R * 2 - 1) {
				for (int i = 0; i < R; ++i) {
					game.board[i][0] = '*';
					game.board[i][1] = '*';
				}
				game.board[0][0] = 'c';
			}
			else if (M % 2 == 1 || M == R*2-2) {
				game.possible = false;
			}
			else {
				for (int i = 0; i < R; ++i) {
					if (i < M / 2) {
						game.board[i][0] = '*';
						game.board[i][1] = '*';
					}
					else {
						game.board[i][0] = '.';
						game.board[i][1] = '.';
					}
				}
				game.board[R - 1][C - 1] = 'c';
			}
		}
		else if (R == 2) {
			if (M == C * 2 - 1) {
				for (int i = 0; i < C; ++i) {
					game.board[0][i] = '*';
					game.board[1][i] = '*';
				}
				game.board[0][0] = 'c';
			}
			else if (M % 2 == 1 || M == C * 2 - 2) {
				game.possible = false;
			}
			else {
				for (int i = 0; i < C; ++i) {
					if (i < M / 2) {
						game.board[0][i] = '*';
						game.board[1][i] = '*';
					}
					else {
						game.board[0][i] = '.';
						game.board[1][i] = '.';
					}
				}
				game.board[R - 1][C - 1] = 'c';
			}
		}
		else if (M <= (C - 2)*(R - 2)) {
			// POSSIBLE
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					if (i < R - 2 && j < C - 2 && 
						(i < (M / (C - 2)) || (i == (M / (C - 2))  && j < M % (C - 2)))) {
						game.board[i][j] = '*';
					}
					else {
						game.board[i][j] = '.';
					}
				}
			}
			game.board[R - 1][C - 1] = 'c';
		}
		else {
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					if (i < R - 2 && j < (C - 2)) {
						game.board[i][j] = '*';
					}
					else {
						game.board[i][j] = '.';
					}
				}
			}
			int rem = M - (C - 2)*(R - 2);  // remainder number of bombs to put down
			if (rem <= 2 * (C - 2 + R - 2)) {
				if (rem % 2 == 0) {
					int c = 0, r = 0;
					while (rem > 0) {
						if (c < C - 2) {
							game.board[R - 2][c] = '*';
							game.board[R - 1][c] = '*';
							++c;
						}
						else {
							game.board[r][C - 2] = '*';
							game.board[r][C - 1] = '*';
							++r;
						}
						rem -= 2;
					}
					game.board[R - 1][C - 1] = 'c';
				}
				else {
					game.board[R - 3][C - 3] = '.';
					++rem;
					int c = 0, r = 0;
					while (rem > 0 && (c < C-3 || r < R-3)) {
						if (c < C - 3) {
							game.board[R - 2][c] = '*';
							game.board[R - 1][c] = '*';
							++c;
						}
						else {
							game.board[r][C - 2] = '*';
							game.board[r][C - 1] = '*';
							++r;
						}
						rem -= 2;
					}
					if (rem == 0) {
						game.board[R - 1][C - 1] = 'c';
					}
					else {
						switch (rem) {
						case 2:
							game.possible = false;
							break;
						case 4:
							game.possible = false;
							break;
						default:
							cout << "\t !!! unhandled case rem = " << rem << "\n";
							break;
						}
					}
				}
			}
			else {
				int N = R*C - M;
				if (N == 1) {
					for (int i = 0; i < R; ++i) {
						for (int j = 0; j < C; ++j) {
							game.board[i][j] = '*';
						}
					}
					game.board[R - 1][C - 1] = 'c';
				}
				else {
					game.possible = false;
				}
			}
		}
		if (game.possible) {
			int mines = 0;
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					output << game.board[i][j];
					if (game.board[i][j] == '*') ++mines;
				}
				output << "\n";
			}
			if (M != mines) cout << "\t !!! ERROR\n";
			cout << "\t" << "M:" << M << " mines:" << mines << "\n";
		}
		else {
			output << "Impossible\n";
		}

	}

	output.close();

	{
		cout << "DONE\n";
		int _;
		cin >> _;
	}

	return 0;
}
