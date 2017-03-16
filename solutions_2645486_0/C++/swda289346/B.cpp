#include <stdio.h>
#define N 10000


inline long long max(long long a, long long b)
{
	return a>b?a:b;
}

inline long long min(long long a, long long b)
{
	return a<b?a:b;
}

long long _calc(long long *v, int e, int r, int n, int se, int ee)
{
	if (n<=0)
		return 0;
	int maxpos = 0;
	long long ans = 0;
	for (int i=1;i<n;++i)
		if (v[i]>v[maxpos])
			maxpos = i;
	long long canGetBefore = maxpos, canGetAfter = n-maxpos-1;
	canGetBefore *= r;
	canGetAfter *= r;
	long long has = min(canGetBefore+se, e), reserved = max(ee-canGetAfter, 0);
	ans += (has-reserved)*v[maxpos];
//	fprintf(stderr, "%lld %lld %lld\n", has, reserved, v[maxpos]);
	ans += _calc(v, e, r, maxpos, se, max(has-r, 0));
	ans += _calc(v+maxpos+1, e, r, n-maxpos-1, min(reserved+r, e), ee);
	return ans;
}

long long calc(long long *v, int e, int r, int n)
{
	int maxpos = 0;
	long long ans = 0;
	for (int i=1;i<n;++i)
		if (v[i]>v[maxpos])
			maxpos = i;
	ans += v[maxpos]*e;
	ans += _calc(v, e, r, maxpos, e, max(e-r, 0));
	ans += _calc(v+maxpos+1, e, r, n-maxpos-1, min(e, r), 0);
	return ans;
}

int main()
{
	int t;
	int e, r, n;
	long long v[N];
	scanf("%d", &t);
	for (int i=1;i<=t;++i)
	{
		scanf("%d%d%d", &e, &r, &n);
		for (int j=0;j<n;++j)
			scanf("%lld", &v[j]);
		printf("Case #%d: %lld\n", i, calc(v, e, r, n));
	}
	return 0;
}
