#define _CRT_SECURE_NO_DEPRECATE
//#define _CRT_RAND_S

//#include <windows.h>
//#include <tchar.h>
//#include <atlbase.h>
//#include <winerror.h>

#include <stdint.h>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

char a[4][8];

int check(char c) {
	// horizontal
	for (int i = 0; i < 4; i++) {
		int w = 1;
		for (int j = 0; j < 4; j++)
			if (a[i][j] != c && a[i][j] != 'T') w = 0;
		if (w) return 1;
	}
	// vertical
	for (int i = 0; i < 4; i++) {
		int w = 1;
		for (int j = 0; j < 4; j++)
			if (a[j][i] != c && a[j][i] != 'T') w = 0;
		if (w) return 1;
	}
	// diagonal 1
	{
		int w = 1;
		for (int j = 0; j < 4; j++)
			if (a[j][j] != c && a[j][j] != 'T') w = 0;
		if (w) return 1;
	}
	// diagonal 2
	{
		int w = 1;
		for (int j = 0; j < 4; j++)
			if (a[j][3-j] != c && a[j][3-j] != 'T') w = 0;
		if (w) return 1;
	}
	return 0;
}

int eval() {
	if (check('X')) return 1;
	if (check('O')) return 2;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (a[i][j] == '.') return 0;
	return 3;
}

string msg[4] = {
	"Game has not completed",
	"X won",
	"O won",
	"Draw"
};

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++)
			scanf("%s", a[i]);
		printf("Case #%d: %s\n", t, msg[eval()].c_str());
	}
	return 0;
}
