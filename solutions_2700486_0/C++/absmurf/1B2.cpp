#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

int bs(int t)
{
	if(t==1) return 0;
	int l=1,r=1000,mid=(r+l+1)/2,cur;
	while(l<=r)
	{
		//cout<<l<<" "<<r;
		cur=2*mid*mid+3*mid+1;
		if(cur<t) l=mid+1;
		else if(cur==t) return mid;
		else r=mid-1;
		mid=(l+r+1)/2;
	}
	return r;
}


int main()
{
	int i,j,T,x,y,N;
	static double nCr[1500][1500];
	static double nCum[1500][1500];
	nCr[1][0]=1;
	nCr[1][1]=1;
	nCum[1][0]=1;
	nCum[1][1]=2;
	for(i=2;i<1500;i++)
	{
		nCr[i][0]=1;
		nCum[i][0]=1;
		for(j=1;j<=i;j++)
		{
			nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
			nCum[i][j]=nCr[i][j]+nCum[i][j-1];
		}
	}
	double pow[1500];
	pow[0]=1;
	for(i=1;i<1500;i++) pow[i]=2*pow[i-1];
	scanf("%d",&T);
	int n,d,t;
	for(int c=1;c<=T;c++)
	{
		scanf("%d",&N);
		scanf("%d %d",&x,&y);
		n=bs(N); d=N-(2*n*n+3*n+1);
		if(x<0)
		{
			if(y-x<=2*n)
			{
				printf("Case #%d: %f\n",c,1.0);
				continue;
			}
			else if(y-x>2*n+2)
			{
				printf("Case #%d: %f\n",c,0.0);
				continue;
			}
		}
		else
		{
			if(y+x<=2*n)
			{
				printf("Case #%d: %f\n",c,1.0);
				continue;
			}
			else if(y+x>2*n+2)
			{
				printf("Case #%d: %f\n",c,0.0);
				continue;
			}
		}
		if(y==2*n+2||y>(d-1))
		{
			printf("Case #%d: %f\n",c,0.0);
			continue;
		}
		if(y<=(d-2*n-3))
		{
			printf("Case #%d: %f\n",c,1.0);
			continue;
		}
		if(y<0||y>2*n+2)
		{
			printf("Case #%d: %f\n",c,1.0);
			continue;
		}
		int t=y+1;
		double ans;
		ans=nCum[d][d-t]/pow[d];
		printf("Case #%d: %f\n",c,ans);
	}
	return 0;
}
