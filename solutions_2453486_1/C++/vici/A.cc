#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
char mp[10][10];
int main() {
#if 1
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
#endif
	int T, ca = 1;
	for (scanf("%d", &T); T--; ) {
		for (int i = 0; i < 4; ++i) scanf(" %s", mp[i]);
		bool end = true, xw = 0, ow = 0;
		for (int i = 0; i < 4; ++i) 
			for (int j = 0; j < 4; ++j) 
		   		if (mp[i][j] == '.') end = false;
		int xc, oc, tc;
		for (int i = 0; i < 4; ++i) {
			xc = 0, oc = 0, tc = 0;
			for (int j = 0; j < 4; ++j) {
				xc += mp[i][j] == 'X';
				oc += mp[i][j] == 'O';
				tc += mp[i][j] == 'T';
			}
			if (xc == 4 || (xc == 3 && tc >= 1)) xw = true;
			if (oc == 4 || (oc == 3 && tc >= 1)) ow = true;
			xc = oc = tc = 0;
			for (int j = 0; j < 4; ++j) {
				xc += mp[j][i] == 'X';
				oc += mp[j][i] == 'O';
				tc += mp[j][i] == 'T';
			}
			if (xc == 4 || (xc == 3 && tc >= 1)) xw = true;
			if (oc == 4 || (oc == 3 && tc >= 1)) ow = true;
		}	
		xc = oc = tc = 0;
		for (int i = 0; i < 4; ++i) {
			xc += mp[i][i] == 'X';
			oc += mp[i][i] == 'O';
			tc += mp[i][i] == 'T';
		}
		if (xc == 4 || (xc == 3 && tc >= 1)) xw = true;
		if (oc == 4 || (oc == 3 && tc >= 1)) ow = true;
		xc = oc = tc = 0;
		for (int i = 0; i < 4; ++i) {
			xc += mp[i][3-i] == 'X';
			oc += mp[i][3-i] == 'O';
			tc += mp[i][3-i] == 'T';
		}
		if (xc == 4 || (xc == 3 && tc >= 1)) xw = true;
		if (oc == 4 || (oc == 3 && tc >= 1)) ow = true;
	
		printf("Case #%d: ", ca++);
		if (xw && ow) puts("Draw");
		else if (!xw && !ow && !end) puts("Game has not completed");
		else if (!xw && !ow && end) puts("Draw");
		else if (xw) puts("X won");
		else if (ow) puts("O won");
	}
	
	return 0;
}

