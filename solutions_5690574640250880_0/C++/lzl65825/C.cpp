#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;
int T,n,m,q,map[60][60];
const int dxy[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void print()
{
	int i,j,k;
	for (i=1;i<=n;++i)
	{
		for (j=1;j<=m;++j)
		{
			if (i==1 && j==1)
			{
				printf("c");
				continue;
			}
			bool flag=0;
			for (k=0;k<8;++k)
			{
				int x=i+dxy[k][0],y=j+dxy[k][1];
				if (map[x][y])
				{
					flag=1;
					break;
				}
			}
			if (flag)
				printf(".");
			else
				printf("*");
		}
		puts("");
	}
}
int main()
{
	freopen("C-small-attempt4.in","r",stdin);
	freopen("C-small-attempt4.out","w",stdout);
	int i,j;
	scanf("%d",&T);
	//printf("%d\n",T);
	for (int ii=1;ii<=T;++ii)
	{
		scanf("%d%d%d",&n,&m,&q);
		memset(map,0,sizeof(map));
		//printf("%d %d %d\n",n,m,q);
		printf("Case #%d:\n",ii);
		if (q==0)
		{
			for (i=1;i<=n;++i)
				for (j=1;j<=m;++j)
					map[i][j]=1;
			print();
			continue;
		}
		if (n==1)
		{
			for (i=1;i<m-q;++i)
				map[n][i]=1;
			print();
			continue;
		}
		if (m==1)
		{
			for (i=1;i<n-q;++i)
				map[i][m]=1;
			print();
			continue;
		}
		if (q==n*m-1)
		{
			for (i=1;i<=n;++i)
			{
				for (j=1;j<=m;++j)
					if (i==1 && j==1)
						printf("c");
					else
						printf("*");
				puts("");
			}
			continue;
		}
		if (q==n*m-2 || q==n*m-3 || q==n*m-5)
		{
			puts("Impossible");
			continue;
		}
		int tmp=n*m-q;
		tmp-=4;
		map[1][1]=1;
		for (j=2;j<=m;++j)
		{
			if (tmp==0)
			{
				print();
				break;
			}
			if (j==m) 
			{
				--j;
				break;
			}
			if (tmp>1)
				tmp-=2,map[1][j]=1;
			else
			{
				--j;
				break;
			}
		}
		if (n==2 && tmp>0)
		{
			puts("Impossible");
			continue;
		}
		if (tmp==0) continue;
		int last=j;
		for (i=2;i<n;++i)
		{
			if (tmp==1)
			{
				if (last>1)
					map[i-1][last]=0,tmp+=1+(i==2),--last;
				else
					break;
			}
			for (j=1;j<=last;++j)
			{
				if (j==1)
					tmp-=2,map[i][j]=1;
				else
					tmp--,map[i][j]=1;
				if (tmp==0)
				{
					print();
					break;
				}
			}
			last=j-1;
			if (tmp==0) break;
		}
		if (tmp)
			puts("Impossible");
	}
	//system("pause");
	return 0;
}
