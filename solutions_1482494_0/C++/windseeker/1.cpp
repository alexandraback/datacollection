#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int Maxv=1100;
bool vis[2][Maxv];
int star[2][Maxv];

int main()
{
	int i,j;
	int c;
	int tc=1;
	freopen("B-small-attempt3.in","r",stdin);
	freopen("B-small-attempt3.out","w",stdout);
	scanf("%d",&c);
	while(c--)
	{
		int n;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d%d",&star[0][i],&star[1][i]);
		int now=0;
		int tot=n;
		int no=0;
		while(tot)
		{
			no++;
			for(i=0;i<n;i++)
			if(!vis[1][i]&&!vis[0][i]&&star[1][i]<=now)
			{
				vis[1][i]=true;
				now+=2;
				break;
			}
			if(i!=n)
			{
				tot--;
				continue;
			}
			for(i=0;i<n;i++)
			{
				if(!vis[1][i]&&star[1][i]<=now)
				{
					now++;
					vis[1][i]=true;
					break;
				}
			}
			if(i!=n)
			{
				tot--;
				continue;
			}
			for(i=0;i<n;i++)
			{
				if(!vis[0][i]&&vis[1][i]&&star[0][i]<=now)
				{
					now++;
					vis[0][i]=true;
					break;
				}
			}
			if(i!=n)
			continue;
			int m=-1;
			int id=-1;
			for(i=0;i<n;i++)
			{
				if(!vis[0][i]&&star[0][i]<=now)
				{
					if(star[1][i]>m)
					{
						id=i;
						m=star[1][i];
					}
				}
			}
			if(id!=-1)
			{
				now++;
				vis[0][id]=true;
			}
			else
			break;
		}
//		cout<<now<<endl;
		printf("Case #%d: ",tc++);
		if(tot)
		puts("Too Bad");
		else
		printf("%d\n",no);
	}
}