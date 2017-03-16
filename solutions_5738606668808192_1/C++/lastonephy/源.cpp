#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<queue>
#define eps 1e-8
#define MOD 1000000007
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1010
using namespace std;

int prime[1000010], cnt;
bool flag[1000010];
char que[20];
vector<int> d;

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	for(int i = 2; i <= 1000000; i ++)
	{
		if(!flag[i])
		{
			prime[cnt ++] = i;
		}
		for(int j = 0; j < cnt && i * prime[j] <= 1000000; j ++)
		{
			flag[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
	int t;
	scanf("%d",&t);
	for(int ii = 1; ii <= t; ii ++)
	{
		int n, m;
		scanf("%d%d",&n,&m);
		n = 16;
		int sta = 1<<(n - 2);
		printf("Case #%d:\n",ii);
		for(int i = 0; i < sta; i ++)
		{
			que[0] = '1';
			for(int j = 0; j < n - 2; j ++)
			{
				if(i&(1<<j))
				{
					que[j+1] = '1';
				}
				else
				{
					que[j+1] = '0';
				}
			}
			que[n - 1] = '1';
			d.clear();
			int f = 0;
			for(int j = 2; j <= 10; j ++)
			{
				LL ans = 0;
				for(int k = 0; k < n; k ++)
				{
					ans = ans * j;
					if(que[k] == '1')
					{
						ans += 1;
					}
				}
				int f1 = 0;
				for(int k = 0; k < cnt && ans > prime[k]; k ++)
				{
					if(ans % prime[k] == 0)
					{
						d.push_back(prime[k]);
						f1 = 1;
						break;
					}
				}
				if(!f1)
				{
					f = 1;
					break;
				}
			}
			if(!f)
			{
				printf("%s%s ",que,que);
				int size = d.size();
				for(int j = 0; j < size; j ++)
				{
					printf("%d",d[j]);
					if(j == size - 1)
					{
						printf("\n");
					}
					else
					{
						printf(" ");
					}
				}
				m --;
				if(!m)
				{
					break;
				}
			}
		}
	}
	return 0;
}