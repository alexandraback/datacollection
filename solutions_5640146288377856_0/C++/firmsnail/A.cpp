#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <iterator>
#include <string>
#include <queue>
#include <cctype>
using namespace std;
#define LL long long
const LL l1 = 1LL;
int r, c, w;
int ans;
void solve()
{
	int len = (c/w);
	ans = (r-1)*len;
	ans += len;
	ans += w;
	if (c % w == 0) --ans;
	printf("%d\n", ans);
}
int main()
{
	freopen("E:\\My Code\\GCJ\\2015\\R1C\\A-small-attempt0.in", "r", stdin);
	freopen("E:\\My Code\\GCJ\\2015\\R1C\\A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d%d%d", &r, &c, &w);
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}