#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double pi = acos(-1);
int T;
long long R, t;
int main()
{
	freopen("put.in", "r", stdin);
	freopen("put.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%lld%lld", &R, &t);
		long long l = 0, r = 1005, ans;
		while (l < r)
		{
			long long mid = (l+r)>>1;
			long long A = 2*mid*mid+(2*R-1)*mid;
			if (A <= t)
			{
				ans = mid;
				l = mid+1;
			}
			else
				r = mid;
		}
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}
