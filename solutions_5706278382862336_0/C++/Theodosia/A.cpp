#include <cstdio>
#include <cstring>

long long gcd(long long a,long long b)
{
	long long c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long p,q;

int check(long long x)
{
	for (int i = 0; i <= 40; i++) if (x == (1 << i)) return i;
	return -1;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	int test; scanf("%d",&test);
	for (int T = 1; T <= test; T++)
	{
		scanf("%I64d/%I64d",&p,&q);
		long long g = gcd(p,q);
		p /= g; q /= g;
		int t = check(q);
		long long x = 1;
		if (t >= 0 && t <= 40)
		{
			int i = 0;
			while (i < t && q / x > p)
			{
				i++;
				x <<= 1;
			}
			printf("Case #%d: %d\n",T,i);
		} else
			printf("Case #%d: impossible\n",T);
	}
}
