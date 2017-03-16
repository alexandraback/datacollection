#include <iostream>

using namespace std;

int main() {
	int t;
	char tab[4][4];
	cin >> t;

	int tx, ty, dotCounter=0;
	for (int it=0; it<t; ++it) {
		dotCounter=0; tx=ty=-1;
		for (int i=0; i<16; ++i) {
			cin >> tab[i/4][i%4];
			if (tab[i/4][i%4] == 'T') {
				tx = i/4;
				ty = i%4;
			} else if (tab[i/4][i%4] == '.') ++dotCounter;
		}

		bool xWon = false;
		if (tx != -1) tab[tx][ty] = 'X';

		//Pion
		for (int i=0; i<4 && !xWon; ++i) {
			int j;
			for (j=1; j<4; ++j)
				if (tab[i][j]!=tab[i][j-1]) break;
			if (j==4 && tab[i][j-1]=='X') xWon=true;
		}
		//Poziom
		for (int i=0; i<4 && !xWon; ++i) {
			int j;
			for (j=1; j<4; ++j)
				if (tab[j][i]!=tab[j-1][i]) break;
			if (j==4 && tab[j-1][i]=='X') xWon=true;
		}
		//Skosy
		int i;
		for (i=1; i<4 && !xWon; ++i)
			if (tab[i][i] != tab[i-1][i-1]) break;
		if (i==4 && tab[i-1][i-1]=='X') xWon=true;
		if (tab[3][0] == tab[2][1] && tab[2][1] == tab[1][2] && tab[1][2] == tab[0][3] && tab[0][3] == 'X') xWon=true;

		bool oWon = false;
		if (tx != -1) tab[tx][ty] = 'O';

		//Pion
		for (int i=0; i<4 && !oWon; ++i) {
			int j;
			for (j=1; j<4; ++j)
				if (tab[i][j]!=tab[i][j-1]) break;
			if (j==4 && tab[i][j-1]=='O') oWon=true;
		}
		//Poziom
		for (int i=0; i<4 && !oWon; ++i) {
			int j;
			for (j=1; j<4; ++j)
				if (tab[j][i]!=tab[j-1][i]) break;
			if (j==4 && tab[j-1][i]=='O') oWon=true;
		}
		//Skosy
		for (i=1; i<4 && !oWon; ++i)
			if (tab[i][i] != tab[i-1][i-1]) break;
		if (i==4 && tab[i-1][i-1]=='O') oWon=true;
		if (tab[3][0] == tab[2][1] && tab[2][1] == tab[1][2] && tab[1][2] == tab[0][3] && tab[0][3] == 'O') oWon=true;

		if (xWon) cout << "Case #" << it+1 << ": X won" << endl;
		if (oWon) cout << "Case #" << it+1 << ": O won" << endl;
		if (!xWon && !oWon && dotCounter!=0) cout << "Case #" << it+1 << ": Game has not completed" << endl;
		if (!xWon && !oWon && dotCounter==0) cout << "Case #" << it+1 << ": Draw" << endl;
	}

	//system("PAUSE");
	return 0;
}
