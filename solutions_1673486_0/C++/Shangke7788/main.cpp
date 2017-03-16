#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

#define N 100005
double a[N];
int n, m;
double mm[N];
double ans, tmp, yy, my;

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, ca=1;
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d%d", &n, &m);
		for ( int i=1; i<=n; i++)
			scanf("%lf", &a[i]);
		tmp = 1;
		memset(mm, 0, sizeof(mm));
		ans = n+m+1;
		for ( int i=1; i<=n; i++)
		{
			tmp *= a[i];
			yy = 1-tmp;
			mm[i] = tmp*(n+m-i-i+1)+yy*(n+m-i-i+1+m+1);
		}
		mm[n+1] = m+2;
		for ( int i=1; i<=n+1; i++)
			ans = min(ans, mm[i]);
		printf("Case #%d: %.7lf\n", ca++, ans);
	}
	return 0;
}

