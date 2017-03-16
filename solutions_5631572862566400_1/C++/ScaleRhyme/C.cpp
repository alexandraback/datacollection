#ifndef FLLD
#ifdef WIN32
#define FLLD "%I64d"
#else
#define FLLD "%lld"
#endif
#endif

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <ctime>
#include <tuple>
#include <random>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <queue>

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define NOKEY(x, y) ((x).find(y) == (x).end())
#define EXISTKEY(x, y) ((x).find(y) != (x).end())
#define INCMAP(x, y) ((x)[y] = MAPINTV(x, y) + 1)
#define MAPINTV(x, y) (EXISTKEY(x, y) ? (x)[y] : 0)
#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; i ++)
#define FORALL(x, l) for (const auto & x : l)
#define DEBUGLEVEL 5
#define DEBUG(debuglevel, ...) if(debuglevel <= DEBUGLEVEL) fprintf(stderr, ##__VA_ARGS__);
typedef long long ll;

using namespace std;

int B[1005];
int visit[1005];

int s[1005];
int ans;
int N;

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T;
	scanf("%d", &T);
	REP(testCase, 0, T) {
		printf("Case #%d: ", testCase + 1);
		scanf("%d", &N);
		REP(i, 0, N) {
			scanf("%d", &B[i]);
			B[i] --;
		}
		ans = 0;
		memset(s, 0, sizeof(s));
		REP(i, 0, N) {
			memset(visit, -1, sizeof(visit));
			int u = 1;
			int j;
			for (j = i; visit[j] == -1; j = B[j]) {
				visit[j] = u;
				u ++;
			}
			if (u - visit[j] > ans)	ans = u - visit[j];
			if (B[B[j]] == j) {
				if (u - 1 > s[j])
				{
//					if (testCase == 11)
//						printf("%d %d %d %d\n", i, j, B[B[j]], u);
					s[j] = u - 1;
					if (s[j] > ans)	ans = s[j];
					if (s[j] + s[B[j]] - 2 > ans)	ans = s[j] + s[B[j]] - 2;
				}
			}
		}
		int ans2 = 0;
		REP(i, 0, N) {
			//printf("s[%d]:%d\n", i, s[i]);
			if (s[i] > 0 && (i < B[i]))
				ans2 += s[i] + s[B[i]] - 2;
		}
		if (ans2 > ans)
			ans = ans2;
		printf("%d\n", ans);
	}
	return 0;
}
