#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
using namespace std;

#define REP(i,a) for(int i=0;i<(a);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define SZ(x) ((int)x.size())

string l; // line of input
#define STR(s) getline(cin,l,'\n');s=l;
#define PAR(...) getline(cin,l,'\n');sscanf(l.c_str(),__VA_ARGS__);

void computeCase(int);

int main() {
	freopen("C-large.in", "rt", stdin);
	freopen("C-large.out", "wt", stdout);
	// freopen("C-test.in", "rt", stdin);

	int ncases;
	PAR("%d",&ncases);

	FORE(i,1,ncases)
		computeCase(i);

	return 0;
}

void computeCase(int casen) {
	int R, C, M;
	PAR("%d %d %d",&R,&C,&M);

	cout << "Case #" << casen << ":" << endl;

	// free spaces left
	int F = R * C - M;

	if (R == 1) {
		if (F)
			cout << 'c';
		while(--F > 0)
			cout << '.';
		while(M--)
			cout << '*';
		cout << endl;
	} else if (C == 1) {
		if (F)
			cout << 'c' << endl;
		while(--F > 0)
			cout << '.' << endl;
		while(M--)
			cout << '*' << endl;
	} else {
		string boardrow(C, '*');
		vector<string> board(R, boardrow);
		// always click in corner, if free space
		if (F--)
			board[0][0] = 'c';

		// exactly 1 free space
		if (!F) {
			REP(i,SZ(board))
				cout << board[i] << endl;
			return;
		}

		// min 3 free spaces to be possible
		if (F < 3) {
			cout << "Impossible" << endl;
			return;
		}
		board[0][1] = '.';
		board[1][0] = '.';
		board[1][1] = '.';
		F -= 3;

		int row = 2;
		int col = 2;
		while (row < R || col < C) {
			if (F - 2 >= 0 && col < C) {
				board[0][col] = '.';
				board[1][col] = '.';
				F -= 2;
			}
			if (F - 2 >= 0 && row < R) {
				board[row][0] = '.';
				board[row][1] = '.';
				F -= 2;
			}
			row++;
			col++;
		}
		if ((R == 2 || C == 2) && F == 1) {
			cout << "Impossible" << endl;
			return;
		}
		FOR(i,2,R) {
			FOR(j,2,C) {
				if (board[i][0] == '*' && F) {
					cout << "Impossible" << endl;
					return;
				}
				if (board[0][j] == '*' && F) {
					cout << "Impossible" << endl;
					return;
				}
				if (!F)
					break;
				board[i][j] = '.';
				F--;
			}
			if (!F)
				break;
		}


		REP(i,SZ(board))
			cout << board[i] << endl;
	}

}
