#include <bits/stdc++.h> 

using namespace std;

int T;

int res[5][5][5];
string ans[] = {"RICHARD", "GABRIEL"};
void init () {
	res[1][1][1] = 1;
	res[1][1][2] = 1;
	res[1][1][3] = 1;
	res[1][1][4] = 1;
	res[1][2][1] = 1;
	res[1][2][2] = 1;
	res[1][2][3] = 1;
	res[1][2][4] = 1;
	res[1][3][1] = 1;
	res[1][3][2] = 1;
	res[1][3][3] = 1;
	res[1][3][4] = 1;
	res[1][4][1] = 1;
	res[1][4][2] = 1;
	res[1][4][3] = 1;
	res[1][4][4] = 1;
	res[2][1][1] = 0;
	res[2][1][2] = 1;
	res[2][1][3] = 0;
	res[2][1][4] = 1;
	res[2][2][1] = 1;
	res[2][2][2] = 1;
	res[2][2][3] = 1;
	res[2][2][4] = 1;
	res[2][3][1] = 0;
	res[2][3][2] = 1;
	res[2][3][3] = 0;
	res[2][3][4] = 1;
	res[2][4][1] = 1;
	res[2][4][2] = 1;
	res[2][4][3] = 1;
	res[2][4][4] = 1;
	res[3][1][1] = 0;
	res[3][1][2] = 0;
	res[3][1][3] = 0;
	res[3][1][4] = 0;
	res[3][2][1] = 0;
	res[3][2][2] = 0;
	res[3][2][3] = 1;
	res[3][2][4] = 0;
	res[3][3][1] = 0;
	res[3][3][2] = 1;
	res[3][3][3] = 1;
	res[3][3][4] = 1;
	res[3][4][1] = 0;
	res[3][4][2] = 0;
	res[3][4][3] = 1;
	res[3][4][4] = 0;
	res[4][1][1] = 0;
	res[4][1][2] = 0;
	res[4][1][3] = 0;
	res[4][1][4] = 0;
	res[4][2][1] = 0;
	res[4][2][2] = 0;
	res[4][2][3] = 0;
	res[4][2][4] = 0;
	res[4][3][1] = 0;
	res[4][3][2] = 0;
	res[4][3][3] = 0;
	res[4][3][4] = 1;
	res[4][4][1] = 0;
	res[4][4][2] = 0;
	res[4][4][3] = 1;
	res[4][4][4] = 1;
}


int main () {
#ifdef LOCAL
	freopen ("file.in", "r", stdin);
	freopen ("file.out", "w", stdout);
#endif                                
	//freopen (".in", "r", stdin);
	//freopen (".out", "w", stdout);

	cin >> T;

	init ();

	for (int t = 1; t <= T; t++) {
		int x, r, c;
		cin >> x >> r >> c;
		printf ("Case #%d: %s\n", t, ans[res[x][r][c]].c_str ());    	   	
    }

	return 0;
}