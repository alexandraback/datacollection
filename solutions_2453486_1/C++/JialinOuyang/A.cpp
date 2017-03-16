#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define SIZE(v) ((int)(v).size())

#define BEGIN(v) ((v).begin())
#define END(v) ((v).end())
#define ALL(v) BEGIN(v),END(v)
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v);(v).erase(unique(ALL(v)),END(v))

#define FOR(i,l,r) for(int i=(l);i<(r);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)

map< map<char, int>, char > winState;

void init(char c) {
	map<char, int> win;
	win[c] = 4;
	winState[win] = c;
	win[c] = 3; win['T'] = 1;
	winState[win] = c;
}

char mat[10][5];

void solve() {
	bool complete = true;
	FOR(o, 0, 10) {
		map<char, int> win;
		FOR(i, 0, 4) {
			win[mat[o][i]]++;
			if (mat[o][i] == '.') {
				complete = false;
			}
		}
		if (winState.find(win) != winState.end()) {
			printf("%c won\n", winState[win]);
			return ;
		}
	}
	puts(complete ? "Draw" : "Game has not completed");
}

int main() {
	init('X');
	init('O');
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 1; taskIdx <= taskNumber; taskIdx++) {
		FOR(i, 0, 4) {
			scanf("%s", mat[i]);
		}
		FOR(i, 0, 4) {
			FOR(j, 0, 4) {
				mat[i + 4][j] = mat[j][i];
			}
		}
		mat[8][0] = mat[0][0]; mat[8][1] = mat[1][1]; mat[8][2] = mat[2][2]; mat[8][3] = mat[3][3];
		mat[9][0] = mat[0][3]; mat[9][1] = mat[1][2]; mat[9][2] = mat[2][1]; mat[9][3] = mat[3][0];
		printf("Case #%d: ", taskIdx);
		solve();
	}
	return 0;
}
