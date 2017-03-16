#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
vector<int> vec[1010];
int rd[1010],v[1010];
int flag;


void dfs(int k)
{
	int i,x;

	//printf("k=%d\n",k);
	if(v[k]) {flag=1; return;}
	v[k]=1;
	for(i=0;i<vec[k].size();i++)
	{
      x=vec[k][i];
	  dfs(x);
	}
}

int main()
{
	int ca,n,m,i,j,x,test=0;

		freopen("A.in","r",stdin);
	    freopen("A.out","w",stdout);

	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d",&n);
		flag=0;
		memset(rd,0,sizeof(rd));
		for(i=0;i<1010;i++) vec[i].clear();

		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&x);
				rd[x]++;
				vec[i].push_back(x);
			}
		}

		printf("Case #%d: ",++test);
		for(i=1;i<=n;i++)
		{
			if(rd[i]==0) 
			{
				memset(v,0,sizeof(v));
				dfs(i);
			}
		}
		if(flag) printf("Yes\n");else printf("No\n");
	}
	return 0;
}