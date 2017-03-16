#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long LL;

#define MAXN 22
#define sqr(x) ((x)*(x))

LL r, t;

int main()
{
	int T, cases = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld", &r, &t);
		printf("Case #%d: ", ++cases);
		LL low = 0, hig = 10000000010LL;
		LL ans = 0;
		while (low <= hig)
		{
			LL mid = (low + hig) >> 1;
			double s = double(r) * mid * 2 + double(mid) * (mid - 1) * 2 + mid;
//			cout << mid << ' ' << s << endl;
			if (s > double(t + 100))
			{
				hig = mid - 1;
				continue;
			}
			LL s1 = LL(r) * mid * 2 + LL(mid) * (mid - 1) * 2 + mid;
//			cout << s1 << ' ' << t << endl;
			if (s1 <= t)
			{
				ans = mid;
				low = mid + 1;
			}
			else 
				hig = mid - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
