#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
using namespace std;

typedef long long int lli;

inline lli lastdig(lli X, int len, int pos_ans)
{
	return (X - pos_ans*(pow(10, len-1)));
}

lli steps(int X)
{
	if (X == 0 || X == 1)
		return 0;

	else if (X == 2)
	{
		return 10;
	}
	else 
	{
		lli ans = 10;
		ans += (X-2)*9;
		for (int i = 1; i <= X-2; i++)
		{
			ans += pow(10, i);
		}
		return ans;
	}
}

int digs(lli n)
{
	if (n == 0)
		return 0;
	else
	{
		int ans=0;
		while (n > 0)
		{
			n /= 10;
			ans++;
		}
		return ans;
	}
}

int main(void)
{
	int t;
	scanf("%d",&t);
	for (int rep = 1;rep <= t;rep++)
	{
		lli n;
		scanf("%lld",&n);
		int len = digs(n), pos_ans = n/pow(10, len-1);
		lli stepp = steps(len), lastdigit = lastdig(n, len, pos_ans);

		if (n <= 10)
		{
			printf("Case #%d: %lld\n", rep, n);
		}
		else if (pos_ans == 1)
		{
			printf("Case #%d: %lld\n", rep, stepp+lastdigit);
		}
		else
		{
			printf("Case #%d: %lld\n", rep, stepp+pos_ans+lastdigit);
		}
	}
}
