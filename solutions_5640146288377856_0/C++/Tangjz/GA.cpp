#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 131072, mod = 1000000007;
const double eps = 1e-8;
int t, r, c, w;
int main()
{
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case)
	{
		scanf("%d%d%d", &r, &c, &w);
		int ans = c / w * r + w - 1 + (c % w >= 1);
		printf("Case #%d: %d\n", Case, ans);
	}
	return 0;
}
