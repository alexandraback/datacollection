#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

char a[10][10];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int Tests, tts = 0;
	for (scanf("%d", &Tests); Tests--; ) {
		for (int i = 1; i <= 4; ++i)
		scanf("%s", a[i] + 1);

		int w = -1;
		int c0, c1, c2;
		for (int i = 1; i <= 4; ++i) {
			c0 = 0, c1 = 0, c2 = 0;
			for (int j = 1; j <= 4; ++j)
			if (a[i][j] == 'X') ++c1;
			else
			if (a[i][j] == 'O') ++c0;
			else
			if (a[i][j] == 'T') ++c2;

			if (c1 + c2 == 4) {
				w = 1;
				break;
			}
			if (c0 + c2 == 4) {
				w = 0;
				break;
			}
			c0 = 0, c1 = 0, c2 = 0;
			for (int j = 1; j <= 4; ++j)
			if (a[j][i] == 'X') ++c1;
			else
			if (a[j][i] == 'O') ++c0;
			else
			if (a[j][i] == 'T') ++c2;

			if (c1 + c2 == 4) {
				w = 1;
				break;
			}
			if (c0 + c2 == 4) {
				w = 0;
				break;
			}
		}

		c0 = c1 = c2 = 0;
		for (int j = 1; j <= 4; ++j)
		if (a[j][j] == 'X') ++c1;
		else
		if (a[j][j] == 'O') ++c0;
		else
		if (a[j][j] == 'T') ++c2;

		if (c1 + c2 == 4) w = 1;
		else if (c0 + c2 == 4) w = 0;

		c0 = c1 = c2 = 0;
		for (int j = 1; j <= 4; ++j)
		if (a[j][4 - j + 1] == 'X') ++c1;
		else
		if (a[j][4 - j + 1] == 'O') ++c0;
		else
		if (a[j][4 - j + 1] == 'T') ++c2;

		if (c1 + c2 == 4) w = 1;
		else if (c0 + c2 == 4) w = 0;

		if (w == -1) {
			for (int i = 1; i <= 4; ++i)
			for (int j = 1; j <= 4; ++j)
			if (a[i][j] == '.') w = -2;
		}

		printf("Case #%d: ", ++tts);
		if (w == -1) puts("Draw");
		else
		if (w == -2) puts("Game has not completed");
		else
		if (w == 0) puts("O won");
		else puts("X won");
	}
	return 0;
}
