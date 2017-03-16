#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<string>
#include<iostream>
#include<vector>
#define LL long long
using namespace std;

LL sum[16], c[16];
int num[16], cnt;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	LL n;
	c[0] = 1;
	for(int i = 1; i < 16; i ++)
	{
		c[i] = c[i - 1] * 10;
	}
	sum[0] = 9;
	for(int i = 2; i < 16; i ++)
	{
		sum[i-1] = c[i / 2] - 1 + c[(i  + 1) / 2];
	}
	int t;
	scanf("%d",&t);
	for(int ii = 1; ii <= t; ii ++)
	{
		scanf("%lld",&n);
		if(n <= 20)
		{
			printf("Case #%d: %lld\n",ii,n);
			continue;
		}
		LL ans = 0;
		cnt = 0;
		for(int i = 0; i < 16; i ++)
		{
			if(c[i + 1] <= n)
			{
				ans += sum[i];
			}
			if(c[i] == n)
			{
				break;
			}
			else if(c[i] > n)
			{
				if(n % 10 == 0)
				{
					n --;
					ans ++;
				}
				LL re = n;
				while(re)
				{
					num[cnt ++] = re % 10;
					re /= 10;
				}
				for(int i = 0; i < cnt / 2; i ++)
				{
					swap(num[i],num[cnt-i-1]);
				}
				int flag = 0;
				int x = cnt / 2;
				if(num[0] == 1)
				{
					for(int i = 1; i < x; i ++)
					{
						if(num[i] != 0)
						{
							flag = 1;
							break;
						}
					}
				}
				else
				{
					flag = 1;
				}
				LL s = 0;
				if(flag)
				{
					for(int i = x - 1; i >= 0; i --)
					{
						s = s * 10 + num[i];
					}
					ans += s;
				}
				s = 0;
				for(int i = x; i < cnt; i ++)
				{
					s = s * 10 + num[i];
				}
				ans += s;
				break;
			}
		}
		printf("Case #%d: %lld\n",ii,ans + 1);
	}
	return 0;
}