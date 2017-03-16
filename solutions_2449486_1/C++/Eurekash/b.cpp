#include <cstdio>

const int maxn=110;

int n,m,a[maxn][maxn];

bool row(int x,int y)
{
	for(int i=0;i<m;++i)
		if(a[x][i]>a[x][y])  return false;
	return true;
}

bool column(int x,int y)
{
	for(int i=0;i<n;++i)
		if(a[i][y]>a[x][y])  return false;
	return true;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",a[i]+j);
		bool flag=true;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				if(!row(i,j) && !column(i,j))
				{
					flag=false;
					break;
				}
			}
		printf("Case #%d: ",t);
		puts(flag?"YES":"NO");
	}
	return 0;
}
