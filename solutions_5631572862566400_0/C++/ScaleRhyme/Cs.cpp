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
int l[1005];

int search(int depth) {
	if (depth > ans) {
		int flag = 1;
		for (int i = 0; i < depth && flag; i ++) {
			if (!(B[l[i]] == l[(i + depth - 1) % depth] || B[l[i]] == l[(i + 1) % depth]))
				flag = 0;
		}
		if (flag)
			ans = depth;
	}
	for (int i = 0; i < N; i ++)
		if (visit[i] == 0) {
			visit[i] = 1;
			l[depth] = i;
			search(depth + 1);
			visit[i] = 0;
		}
}

int main() {
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("c2.out", "w", stdout);
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
		memset(visit, 0, sizeof(visit));
		search(0);
		printf("%d\n", ans);
	}
	return 0;
}
