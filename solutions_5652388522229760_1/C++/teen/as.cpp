#include <bits\stdc++.h>
using namespace std;
bool vis[10];
int main()
{
	freopen("0.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t;i++)
	{
		memset(vis,false,sizeof(vis));
		int n;
		scanf("%d",&n);
		int cnt = 0;
		bool is = false;
		int ans = 0;
		for(int j = n; n!=0&&j <= 100000000;j+=n)
		{
			int tm = j;
			while(tm>0)
			{
				if(!vis[tm%10])
				{
					vis[tm%10] = true;
					cnt++;
				}
				tm /=10;
			}
			if(cnt == 10)
			{
				is = true;
				ans = j;
				break;
			}
		}
		printf("Case #%d: ",i);
		if(is)
			printf("%d\n",ans);
		else
			printf("INSOMNIA\n");
	}
	return 0;
}