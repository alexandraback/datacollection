#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#pragma comment(linker, "/STACK:1024000000,1024000000")

const int maxV = 30, maxn = 5;
int limit, n;
LL coin[maxn], V;


int main() {
//freopen("in", "r", stdin);
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d %d %lld", &limit, &n, &V);
		for (int i = 0; i < n; i++) scanf("%lld", coin + i);

		LL cur = 1, ALL = (1LL << (V + 1)) - 1;
		for (int i = 0; i < n; i++)
		if (coin[i] <= V)
			cur = (cur | (cur << coin[i])) & ALL;
		int res = 0;
		for (int i = 0; i <= V; i++)
		if ((cur & (1LL << i)) == 0) {
			res++;
			cur = (cur | (cur << i)) & ALL;
		}

		printf("Case #%d: %d\n", ti, res);
	}
	return 0;
}
