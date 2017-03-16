#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define LL long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
string s[4];
void solve() {
	for (int i = 0; i < 4; i++) {
		int cntX = 0,cntO = 0;
		for (int j = 0; j < 4; j++) {
			if (s[i][j] == 'T') {
				cntX++;
				cntO++;
			} else if (s[i][j] == 'X') {
				cntX++;
			} else if (s[i][j] == 'O') {
				cntO++;
			}
		}
		if (cntX == 4) {
			cout << "X won" << endl;
			return;
		}
		if (cntO == 4) {
			cout << "O won" << endl;
			return;
		}
	}
	for (int j = 0; j < 4; j++) {
		int cntX = 0,cntO = 0;
		for (int i = 0; i < 4; i++) {
			if (s[i][j] == 'T') {
				cntX++;
				cntO++;
			} else if (s[i][j] == 'X') {
				cntX++;
			} else if (s[i][j] == 'O') {
				cntO++;
			}
		}
		if (cntX == 4) {
			cout << "X won" << endl;
			return;
		}
		if (cntO == 4) {
			cout << "O won" << endl;
			return;
		}
	}
	int cntX = 0,cntO = 0;
	for (int i = 0; i < 4; i++) {
		if (s[i][i] == 'T') {
			cntX++;
			cntO++;
		} else if (s[i][i] == 'X') {
			cntX++;
		} else if (s[i][i] == 'O') {
			cntO++;
		}
	}
	if (cntX == 4) {
		cout << "X won" << endl;
		return;
	}
	if (cntO == 4) {
		cout << "O won" << endl;
		return;
	}
	cntX = 0;
	cntO = 0;
	for (int i = 0; i < 4; i++) {
		if (s[i][3 - i] == 'T') {
			cntX++;
			cntO++;
		} else if (s[i][3 - i] == 'X') {
			cntX++;
		} else if (s[i][3 - i] == 'O') {
			cntO++;
		}
	}
	if (cntX == 4) {
		cout << "X won" << endl;
		return;
	}
	if (cntO == 4) {
		cout << "O won" << endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (s[i][j] == '.') {
				cout << "Game has not completed" << endl;
				return;
			}
		}
	}
	cout << "Draw" << endl;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++) {
			cin >> s[i];
		}
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
