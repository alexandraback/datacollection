#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>
//#include <map>
#include <functional>
#include <cmath>

#define fi first
#define se second
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define SQR(x) ((x)*(x))

using namespace std;

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;
typedef pair <DB, DB> PD;
typedef pair <PI, PI> PIII;

int Read()
 {
	char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
	bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
	while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
	return neg ? -ret : ret;
 }
 
char map[5][5];

int main()
 {
	freopen("A.in", "r", stdin), freopen("A.out", "w", stdout);
	int cases; scanf("%d", &cases);
	fo (ca, 1, cases)
	 {
		fo (i, 0, 3) scanf("%s", map[i]);
		bool xwin = 0, owin = 0;
		fo (i, 0, 3)
		 {
			int cnt = 0;
			fo (j, 0, 3) if (map[i][j] == 'X' || map[i][j] == 'T') ++ cnt;
			if (cnt == 4) xwin = 1;
			cnt = 0;
			fo (j, 0, 3) if (map[j][i] == 'X' || map[j][i] == 'T') ++ cnt;
			if (cnt == 4) xwin = 1;
			cnt = 0;
			fo (j, 0, 3) if (map[i][j] == 'O' || map[i][j] == 'T') ++ cnt;
			if (cnt == 4) owin = 1;
			cnt = 0;
			fo (j, 0, 3) if (map[j][i] == 'O' || map[j][i] == 'T') ++ cnt;
			if (cnt == 4) owin = 1;
		 }
		int cnt = 0;
		fo (i, 0, 3) if (map[i][i] == 'X' || map[i][i] == 'T') ++ cnt;
		if (cnt == 4) xwin = 1;
		cnt = 0;
		fo (i, 0, 3) if (map[i][i] == 'O' || map[i][i] == 'T') ++ cnt;
		if (cnt == 4) owin = 1;
		cnt = 0;
		fo (i, 0, 3) if (map[i][3-i] == 'X' || map[i][3-i] == 'T') ++ cnt;
		if (cnt == 4) xwin = 1;
		cnt = 0;
		fo (i, 0, 3) if (map[i][3-i] == 'O' || map[i][3-i] == 'T') ++ cnt;
		if (cnt == 4) owin = 1;
		
		printf("Case #%d: ", ca);
		if (xwin ^ owin) puts(xwin ? "X won" : "O won");
		else
		 {
			bool emp = 0;
			fo (i, 0, 3) fo (j, 0, 3) if (map[i][j] == '.') emp = 1;
			puts(emp ? "Game has not completed" : "Draw");
		 }
	 } 
	return 0;
 }
