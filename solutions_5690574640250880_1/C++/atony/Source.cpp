#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 51;
const int MAXM = 2000011;
const int MAXK = 201;
const int INF = 1000000001;
const double eps = 1e-5;

char a[MAXK][MAXK];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,cas,i,j,m,n,r,c;
	bool impossible;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d%d%d",&r,&c,&m);
		n= r*c-m;
		impossible=false;
		for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					a[i][j]='*';
		if(r*c-m==1)
		{
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					a[i][j]='*';
		}
		else
		if(min(r,c)==1)
		{
			if(r>1)
			{
				for(i=0;i<r;i++)
					if(i<n)
						a[i][0]='.';
			}
			else
			{
				for(j=0;j<c;j++)
					if(j<n)
						a[0][j]='.';
			}
		}
		else
		if(n<4|| ((min(r,c)==2)&&(n&1)) || ((n&1)&&n<9))
		{
			impossible=true;
		}
		else
		if(min(r,c)==2)
		{
			if(r==2)
			{
				for(j=0;j<n/2;j++)
					a[0][j]=a[1][j]='.';
			}
			else
			{
				for(i=0;i<n/2;i++)
					a[i][0]=a[i][1]='.';
			}
		}
		else
		{
			for(i=0;i<2;i++)
				for(j=0;j<2;j++)
					a[i][j]='.';
			n-=4; 
			for(i=2;i<r&&i<c;i++)
			{
				if(n>=2)
				{
					a[i][0]=a[i][1]='.';
					n-=2;
				}
				if(n>=2)
				{
					a[0][i]=a[1][i]='.';
					n-=2;
				}	
			}
			for(;i<r;i++)
			{
				if(n>=2)
				{
					a[i][0]=a[i][1]='.';
					n-=2;
				}
			}
			for(;i<c;i++)
			{
				if(n>=2)
				{
					a[0][i]=a[1][i]='.';
					n-=2;
				}	
			}
			for(i=2;i<r&&n>0;i++)
				for(j=2;j<c&&n>0;j++,n--)
					a[i][j]='.';
		}
		a[0][0]='c';
		printf("Case #%d:\n",cas);
		if(impossible==true)
			printf("Impossible\n");
		else
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
					printf("%c",a[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
	
}