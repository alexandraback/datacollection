#include <cstdio>
#define LL long long
#define ll1 ((LL)(1))
LL P, Q;
LL gcd(LL a, LL b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
int check(LL num)
{
	int i = 0;
	while (1)
	{
		if ((ll1<<i) == num) return i;
		else if ((ll1<<i) > num) break;
		else ++i;
	}
	return -1;
}
void solve()
{
	LL g = gcd(P, Q);
	P /= g;
	Q /= g;
	int ans = check(Q);
	if (ans == -1) puts("impossible");
	else
	{
		int cc = 0;
		while (P < Q)
		{
			Q >>= 1;
			++cc;
		}
		printf("%d\n", cc);
	}
}
int main()
{
	//freopen("E:\\My Code\\GCJ\\R1C\\A-large.in", "r", stdin);
	//freopen("E:\\My Code\\GCJ\\R1C\\A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		scanf("%lld/%lld", &P, &Q);
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}