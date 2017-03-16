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
#define LL __int64
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1010
using namespace std;

int flag[10];
int n;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ii = 1; ii <= t; ii ++)
	{
		scanf("%d",&n);
		if(n == 0)
		{
			printf("Case #%d: INSOMNIA\n",ii);
			continue;
		}
		int ans = n;
		int cnt = 0;
		mem(flag, 0);
		while(ans)
		{
			int re = ans % 10;
			if(!flag[re])
			{
				cnt ++;
				flag[re] = 1;
			}
			ans /= 10;
		}
		ans = n;
		while(1)
		{
			ans = ans + n;
			int re = ans;
			while(re)
			{
				int x = re % 10;
				if(!flag[x])
				{
					cnt ++;
					flag[x] = 1;
				}
				re /= 10;
			}
			if(cnt == 10)
			{
				break;
			}
		}
		printf("Case #%d: %d\n",ii,ans);
	}
	return 0;
}