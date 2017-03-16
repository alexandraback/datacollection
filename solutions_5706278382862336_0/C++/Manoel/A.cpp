#include <stdio.h>
#include <string.h>

long long gcd(long long a, long long b)
{
	if(a > b)
	{
		long long c = a;
		a = b;
		b = c;
	}
	
	if(a==0)
		return b;
	return gcd(b%a, a);
}

int solve(long long a, long long b)
{
	if(a >= b/2)
		return 1;
	return 1 + solve(a, b/2);
}

int main()
{
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	
	int n, t=1;
	scanf(" %d", &n);
	
	while(n--)
	{
		char st[40];
		scanf(" %s", st);
		
		long long a=0LL, b=0LL;
		int i=0, ln = strlen(st);
		while(st[i] != '/')
		{
			a *= 10LL;
			a += (long long)(st[i]-'0');
			i++;
		}
		i++;
		while(i < ln)
		{
			b *= 10LL;
			b += (long long)(st[i]-'0');
			i++;
		}
		long long c = gcd(a, b);
		a /= c;
		b /= c;
		
		int k=0;
		long long d = b;
		bool flag = true;
		while(d > 1)
		{
			if(d%2==0)
			{
				d /= 2;
				k++;
			}
			else
			{
				flag = false;
				break;
			}
		}
		
		printf("Case #%d: ", t++);
		
		if(flag == false)
		{
			printf("impossible\n");
			continue;
		}
		
		int ans = solve(a, b);
		
		printf("%d\n", ans);
	}
	
	//fclose(stdin);
	//fclose(stdout);
	
	return 0;
}
