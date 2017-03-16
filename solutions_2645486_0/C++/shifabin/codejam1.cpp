#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int a[1000],b[100][100];
int main()
{
	//	freopen("B.in","r",stdin);freopen("B.out","w",stdout);
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	

	int ii,i,j,k,p,tt,e,r,n,max;



	scanf("%d",&tt);
	for(ii=1;ii<=tt;ii++)
	{
		scanf("%d%d%d",&e,&r,&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<=n;i++)
			for(j=0;j<=e;j++)
				b[i][j]=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=e;j++)
			{
				for(k=0;k<=j;k++)
				{
					p=j-k+r;
					if (p>e)  p=e;
					if (b[i-1][j]+a[i]*k>b[i][p])  b[i][p]=b[i-1][j]+a[i]*k;
				}
			}
		}
		max=0;
		for(i=0;i<=e;i++)
			if (b[n][i]>max)  max=b[n][i];
		printf("Case #%d: %d\n",ii,max);
	}
    
	
	
	
	
	
	
	
	
	return 0;

}