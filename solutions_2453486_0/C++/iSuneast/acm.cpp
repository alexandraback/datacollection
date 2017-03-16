#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

#define LOWBIT(v) ((v)&(-(v)))
#define KTH_BIT(v, k) ((v) & (1<<(k)))
#define MERGE_BIT(v, k) ((v) | (1<<(k)))

#define MAXN 4
#define MOD 
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

char g[4][5];
const char *key[] = {
	"X won",
	"O won",
	"Draw",
	"Game has not completed"
};
bool full;

bool chk_char(char a, char b) {
	return a == b || a == 'T';
}

bool chk(char c) {
	bool dia[2] = {true, true};
	for(int i=0; i<4; ++i) {
		bool dir[2] = {true, true};
		for(int j=0; j<4; ++j) {
			if(!chk_char(g[i][j], c)) {
				dir[0] = false;
			}
			if(!chk_char(g[j][i], c)) {
				dir[1] = false;
			}
		}
		if(dir[0] || dir[1]) {
			return true;
		}

		if(!chk_char(g[i][i], c)) {
			dia[0] = false;
		}
		if(!chk_char(g[i][3-i], c)) {
			dia[1] = false;
		}
	}
	return dia[0] || dia[1];
}

int solve() {
	if(chk('X')) {
		return 0;
	} else if(chk('O')) {
		return 1;
	} else {
		return full? 2: 3;
	}
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\A-small-attempt0.in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\A-small-attempt0.out", "w", stdout);
#endif
	
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		full = true;
		for(int i=0; i<4; ++i) {
			scanf("%s", g[i]);
			for(int j=0; j<4; ++j) {
				if(g[i][j] == '.') {
					full = false;
				}
			}
		}
		printf("Case #%d: %s\n", cas, key[solve()]);
	}

	return 0;
}
