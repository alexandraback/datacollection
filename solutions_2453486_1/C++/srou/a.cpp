#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define rtrav(it, v) for(typeof((v).rbegin()) it = (v).rbegin(); it != (v).rend(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(int argc, char const *argv[]) {
	int T;
	scanf("%d", &T);
	rep(t,0,T) {
		char board[4][4];
		bool xwin = false, owin = false, ongoing = false;
		rep(i,0,4)
			rep(j,0,4) {
				scanf(" %c", &(board[i][j]));
				assert(board[i][j] == '.' || board[i][j] == 'X' || board[i][j] == 'O' || board[i][j] == 'T');
				if (board[i][j]=='.')
					ongoing = true;
			}
		rep(i,0,4) {
			bool tx1 = true, to1 = true, tx2 = true, to2 = true;
			rep(j,0,4) {
				tx1 = tx1 && (board[i][j] == 'X' || board[i][j] == 'T');
				to1 = to1 && (board[i][j] == 'O' || board[i][j] == 'T');
				tx2 = tx2 && (board[j][i] == 'X' || board[i][j] == 'T');
				to2 = to2 && (board[j][i] == 'O' || board[i][j] == 'T');
			}
			xwin = xwin || tx1 || tx2;
			owin = owin || to1 || to2;
		}

		//fprintf(stderr, "%d\n",t);
		//assert(!(xwin && owin));
		bool tx1 = true, to1 = true, tx2 = true, to2 = true;
		rep(i,0,4) {
			tx1 = tx1 && (board[i][i] == 'X' || board[i][i] == 'T');
			tx2 = tx2 && (board[3-i][i] == 'X' || board[3-i][i] == 'T');
			to1 = to1 && (board[i][i] == 'O' || board[i][i] == 'T');
			to2 = to2 && (board[3-i][i] == 'O' || board[3-i][i] == 'T');
		}
		xwin = xwin || tx1 || tx2;
		owin = owin || to1 || to2;
		//assert(!(xwin && owin));
		printf("Case #%d: ", t+1);

		if (xwin)
			printf("X won\n");
		else if(owin)
			printf("O won\n");
		else if(ongoing)
			printf("Game has not completed\n");
		else
			printf("Draw\n");
	}
	return 0;
}