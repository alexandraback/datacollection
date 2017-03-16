#include<cstdio>
#include<cstdlib>
#include<map> 
#include<vector>
#include<algorithm> 

using namespace std; 

long long flip(long long num, long long base)
{
	long long ret = 0;
	while(base > 0)
	{
		ret = num % 10 + ret*10;
		num /= 10;
		base /= 10;
	}
	return ret;
}

long long f[64], l[64];

void Init()
{
	int i;
	f[0] = 0;
	l[0] = 9;
	f[1] = 10;
	l[1] = 9;
	for(i = 2; i < 64; i ++)
	{
		l[i] = l[i-1];
		f[i] = f[i-1];
		if(i % 2 == 1)
		{
			f[i] = f[i-1] * 10;
		}
		if(i % 2 == 0)
		{
			l[i] = l[i-1] * 10 + 9;
		}
	}
}

int main()
{
    freopen("A-small-attempt4.in", "r", stdin);
    freopen("A-small-attempt4.out", "w", stdout);
	int cas, t;
	scanf("%d", &t);
	Init();
	//solve();
	for(cas = 1; cas <= t; cas ++)
	{
		int i, j, k;
		long long n, ans, m;
		scanf("%lld", &n);

		long long base = 1, halfBase = 1;
		ans = 0;
		m = n;
		if(n % 10 == 0)
		{
			n --;
			ans ++;
		}

		i = 0;
		while(base*10 <= n)
		{
			while(halfBase*halfBase <= base)
			{
				halfBase *= 10;
			}
			base *= 10;
			ans += f[i];
			ans += l[i];
			i ++;
		}
		
		long long flipN = flip(n, base);
		long long ans1, ans2;

		ans1 = ans + n - base + 1;
		ans2 = ans;
		{
			if(halfBase > 1)
			{
				ans2 += (flipN % halfBase + 1);
			}
			ans2 += (n % (base*10/halfBase));
		}
		printf("Case #%d: %lld\n", cas, min(ans1, ans2));
		
	}
 
    return 0;  
} 
