#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
const int nmax = 100 + 18;
using namespace std;
int D, C, V;
int v[nmax];

int solve()
{
	sort(v + 1, v + D + 1);
	int now = 1, rnt = 0;
	long long x = 0;
	while (x < V) {
		while (now <= D && v[now] <= x) {
			x += C *1LL* v[now++];
			if (x >= V) return rnt;
		}
//		printf("%lld %d\n", x, v[now]);
		if (!(now <= D && v[now] == x + 1))
			++rnt;
		else
			++now;
		x += (x + 1) *1LL* C;
	}
	return rnt;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases) {
		scanf("%d%d%d", &C, &D, &V);
		//printf("%d %d %d\n", C, D, V);
		for (int i = 1; i <= D; ++i)
			scanf("%d", v + i);//, printf("%d\n", v[i]);
		printf("Case #%d: %d\n", cases, solve());
	}
	return 0;
}
