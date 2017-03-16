#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstdint>
#include <cmath>
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <string.h>

using namespace std;

#define REP(i, p, n) for (int i=p; i<n; ++i)
#define FOR(i, c) for (__typeof ((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

bool is_empty_ (vector<string> &board, int x, int y)
{
	REP (i, -1, 2) REP (j, -1, 2) {
		if (x+i<0 || x+i>=board.size()) continue;
		if (y+j<0 || y+j>=board[0].size()) continue;
		if (board[x+i][y+j] == '*') {
			return false;
		}
	}
	return true;
}

bool see_empty (vector<string> &board, int x, int y)
{
//	cout << x << y << " " ;
	REP (i, -1, 2) REP (j, -1, 2) {
		if (x+i<0 || x+i>=board.size()) continue;
		if (y+j<0 || y+j>=board[0].size()) continue;
		if (board[x+i][y+j] == '1') {
//			cout << board[x+i];
			return true;
		}
	}
//	cout << "fafewafew" ;
	return false;
}


int main (int argc, char **argv)
{
	FILE *fin = fopen(argv[1], "r");
	FILE *fout = fopen (argv[2], "w");
	if (fin==NULL || fout==NULL) exit(1);

	int num_cases;
	fscanf (fin, "%d", &num_cases);

	REP (i, 0, num_cases) {
		int R, C, M;
		bool reverse=false;
		fscanf (fin, "%d%d%d", &R, &C, &M);
		if (R<C) {swap(R, C); reverse=true;}

		vector<string> board(R, string(C, '*'));
		int num_left = R*C-M;

		int root = sqrt(num_left);
		int c = min(C, root);
		int r; // static_cast<int>(ceil(((double)num_left)/c));
		if (  num_left % c != 0 )
			r = num_left/c + 1;
		else
			r = num_left/c;

		if (root*root < num_left && root+1<=R && root+1<=C) {
			c = root+1;
			r = root+1;
		}

		cout << "case " << i << " " << root << " " << c << " " << r << " " << endl;

		REP (j, 0, r) {
			bool break_=false;
			REP (k, 0, c) {
				if (num_left == 0) {
					if (k==1 && c!=1) {
						board[j][k]='.';
						board[j-1][c-1] = '*';
					}
					break_ = true;
					break;
				}
				board[j][k] = '.';
				num_left--;
			}

			if (break_) {
				break;
			}
		}

		bool set_empty=false;
		bool see_empty_cell=false;
		bool valid=true;
		vector<string> tmp(board.begin(), board.end());

		REP (j, 0, R) REP (k, 0, C) {
			if (board[j][k]=='.' && (is_empty_(board, j, k) || R*C-M==1)) {
				tmp[j][k] = '1';
				if (!set_empty)	{ board[j][k] = 'c'; set_empty=true; }
				see_empty_cell = true;
				continue;
			}
		}

		REP (j, 0, R) {
			REP (k, 0, C) {
				cout << tmp[j][k];
			}
			cout << endl;
		}

		REP (j, 0, R) REP (k, 0, C) {
			if (board[j][k]=='.' && !see_empty(tmp, j, k)) {
				valid = false;
				break;
			}
		}

		cout << see_empty_cell << valid << endl;

		fprintf (fout, "Case #%d:\n", i+1);

		if (!valid || (!see_empty_cell && R*C-M>1)) {
			fprintf (fout, "Impossible\n");
		} else {
			if (!reverse) {
				REP (j, 0, R) {
					REP (k, 0, C) fprintf (fout, "%c", board[j][k]);
					fprintf (fout, "\n");
				}
			} else {
				REP (k, 0, C) {
					REP (j, 0, R) fprintf (fout, "%c", board[j][k]);
					fprintf (fout, "\n");
				}
			}
		}
	}

	return 0;
}






