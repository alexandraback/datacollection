#include <iostream>

using namespace std;

void solve(int tc) {
	int lnx[4];
	int lno[4];
	int cnx[4];
	int cno[4];
	int d1x = 0;
	int d1o = 0;
	int d2x = 0;
	int d2o = 0;
	for (int i = 0; i < 4; i++) {lnx[i] = 0;lno[i] = 0;}
	for (int i = 0; i < 4; i++) {cnx[i] = 0;cno[i] = 0;}

	bool finished = true;
	bool xwon = false;
	bool owon = false;

	char p;
    for (int l = 0; l < 4; l++)
	    for (int c = 0; c < 4; c++) {
			cin >> p;
			if (p == 'X' || p == 'T') {
				lnx[l]++; cnx[c]++;
				if (c == l) d1x++;
				if (c + l == 3) d2x++;
			}
			if (p == 'O' || p == 'T') {
				lno[l]++; cno[c]++;
				if (c == l) d1o++;
				if (c + l == 3) d2o++;
			}

			if (p == '.') finished = false;
			if (d1x == 4 || d2x == 4 || lnx[l] == 4 || cnx[c] == 4) xwon = true;
			if (d1o == 4 || d2o == 4 || lno[l] == 4 || cno[c] == 4) owon = true;
		}
			
	cout << "Case #" << tc << ": ";
	if (xwon) cout << "X won";
	else if (owon) cout << "O won";
	else if (!finished) cout << "Game has not completed";
	else cout << "Draw";
	cout << endl ;
}

int main() {
	int tc; cin >> tc;
	for (int i = 0; i < tc;  i++)
		solve(i+1);
	return 0;
}
