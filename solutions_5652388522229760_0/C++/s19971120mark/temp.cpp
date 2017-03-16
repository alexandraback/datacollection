#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T,tt,n,flag,i,ans,t,f,j;
int vis[100];
int main(){
//	freopen("temp.in","r",stdin);
//	freopen("temp.out","w",stdout);
	scanf("%d",&T);
	for (tt = 1;tt <= T;tt++)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		flag = 0;
		for (i = 1;i <= 100;i++)
		{
			ans = t = n*i;
			while (t!=0)
			{
				vis[t%10] = 1;
				t/=10;
			}
			f = 1;
			for (j = 0;j<=9;j++)
			{
				if (vis[j]==0)
				{
					f = 0;
				}
			}
			if (f==1)
			{
				printf("Case #%d: %d\n",tt,ans);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("Case #%d: INSOMNIA\n",tt);
		}
	}
}
