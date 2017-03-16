#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define ass(v) (v)||++*(int*)0;
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<double> VD;
int main()
{
	int t;
	scanf("%d", &t);
	for (int cs = 1; cs <= t; ++cs)
	{
		int n;
		scanf("%d", &n);
		VI a(n), b(n), c(n);
		rep(i, n) scanf("%d%d", &a[i], &b[i]);
		int ans = 0, rate = 0;
		while (true)
		{
			bool ok = false;
			rep(i, n)
			{
				if (c[i] == 2) continue;
				if (rate >= b[i])
				{
					++ans;
					rate += 2 - c[i];
					c[i] = 2;
					ok = true;
					break;
				}
			}

			if (ok) continue;

			int maxb = -1, sel = -1;
			rep(i, n)
			{
				if (c[i] >= 1) continue;
				if (rate >= a[i] && maxb < b[i])
				{
					maxb = b[i];
					sel = i;
				}
			}
			if (sel >= 0)
			{
				++ans;
				rate += 1 - c[sel];
				c[sel] = 1;
				ok = true;
			}

			if (!ok) break;
		}
		printf("Case #%d: ", cs);
		if (rate >= n * 2) printf("%d\n", ans); else puts("Too Bad");
	}
	return 0;
}
