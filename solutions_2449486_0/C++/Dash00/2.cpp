#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MXN 102

int a[MXN][MXN],n,m;

bool judge(int x,int y)
{
	int f=0;
	for(int i=0;i<m;++i)
	{
		if(a[x][i]>a[x][y]){++f;break;}
	}
	for(int i=0;i<n;++i)
	{
		if(a[i][y]>a[x][y]){++f;break;}
	}
	if(f<2)return true;
	return false; 
}

int main()
{
	int i,k,T,cas=0,f;
	scanf("%d",&T);
	while(T--)
	{
		cas++;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;++i)
		{
			for(k=0;k<m;++k)
			{
				scanf("%d",&a[i][k]);
			}
		}
		f=1;
		for(i=0;i<n;++i)
		{
			for(k=0;k<m;++k)
			{
				if(judge(i,k)==false)
				{
					f=0;break;
				}
			}
			if(f==0)break;
		}
		if(f)
			printf("Case #%d: YES\n",cas);
		else
			printf("Case #%d: NO\n",cas);
	}
	return 0;
}
