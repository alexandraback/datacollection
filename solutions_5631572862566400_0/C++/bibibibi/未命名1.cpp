#include<bits/stdc++.h>
using namespace std;

vector  <int> s[1005];

int M,n,book[1005]={0};
void dfs(int st,int now,int count,int last);
int main()
{
	int T,i,t,j;
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&t);
			s[j].push_back(t);
		}
		M=0;
		for(j=1;j<=n;j++)
		{
			dfs(j,j,0,0);
		}
		printf("Case #%d: ",i);
		printf("%d\n",M);
		for(j=1;j<=n;j++)
		{
			s[j].clear();
		}
	}
}

void dfs(int st,int now,int count,int last)
{
	int j;
	if(book[now])
	{
		if(now==st||s[now][0]==last||now==last)	
		{
			M=max(count,M);
		}
		if(s[now][0]==last||now==last)
		{
			for(j=1;j<=n;j++)
			{
				if(!book[j])
				{
					if(s[j][0]==last)
					{
						book[j]=1;
						dfs(st,j,count+1,j);
						book[j]=0;
					}
					else
					{
						dfs(st,j,count,last);
					}
				}
			}
		}
		return ;
	}
	count++;
	book[now]=1;
	dfs(st,s[now][0],count,now);
	book[now]=0;
}
