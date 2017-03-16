#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const int N = 1010;
int a[N][2],vis[N];
int main(void)
{
	int T,n,g=0;
	freopen("B-small-attempt1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i][0],&a[i][1]);
		}
		memset(vis,0,sizeof(vis));
		int now=0,time=0;
		int tmp=0;
		while(1)
		{
			if(now==2*n)
			{
				break;
			}
			int flag=0;
			for(int i=1;i<=n;i++)
			{
				if(!vis[i]&&now>=a[i][1])
				{
					now+=2;
					vis[i]=2;
					flag=1;
					time++;
					break;
				}
			}
			if(flag) continue;
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==1&&now>=a[i][1])
				{
					now+=1;
					vis[i]=2;
					flag=1;
					time++;
					break;
				}
			}			
			if(flag) continue;
			int mark=-1;
			for(int i=1;i<=n;i++)
			{
				if(!vis[i]&&now>=a[i][0])
				{
					if(mark==-1)
					{
						mark=i;
						flag=1;
						
					}
					else
					{
						if(a[mark][1]<a[i][1])
						{
							mark=i;
						}
					}
				}
			}
			if(flag)
			{
				now+=1;
				vis[mark]=1;
				time++;
			}
			else if(!flag)
			{
				tmp=1;
				break;
			}
		}					
		if(tmp)
		{
			printf("Case #%d: Too Bad\n",++g);
		}
		else
		{
			printf("Case #%d: %d\n",++g,time);
		}
	}
	return 0;
}
