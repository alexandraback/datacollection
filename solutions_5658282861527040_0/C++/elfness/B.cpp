/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;

LL dp[40][2][2][2];

int a[40],b[40],c[40],A,B,K,_;

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&_);
	for(int ca=1;ca<=_;ca++)
	{
		scanf("%d%d%d",&A,&B,&K);
		A--;B--;
		for(int i=0;i<=30;i++)
		if(A&(1<<i))a[i+1]=1;
		else a[i+1]=0;
		for(int i=0;i<=30;i++)
		if(B&(1<<i))b[i+1]=1;
		else b[i+1]=0;
		for(int i=0;i<=30;i++)
		if(K&(1<<i))c[i+1]=1;
		else c[i+1]=0;
		memset(dp,0,sizeof(dp));
		dp[31][1][1][1]=1;
		for(int i=31;i>0;i--)
		for(int x=0;x<2;x++)
		for(int y=0;y<2;y++)
		for(int z=0;z<2;z++)
		if(dp[i][x][y][z])
		{
		   // if(i<4)printf("%d %d %d %d %lld\n",i,x,y,z,dp[i][x][y][z]);
			for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
			{
				int l=j&k;
				if(x==1&&j>a[i])continue;
				if(y==1&&k>b[i])continue;
				if(z==1&&l>c[i])continue;
				int tx=x;
				if(j==a[i])tx&=1;
				else tx&=0;
				int ty=y;
				if(k==b[i])ty&=1;
				else ty&=0;
				int tz=z;
				if(l==c[i])tz&=1;
				else tz&=0;
			//	if(i<4)printf("Tr %d %d %d %d %d\n",j,k,tx,ty,tz);
				dp[i-1][tx][ty][tz]+=dp[i][x][y][z];
			}
		}
		LL ret=0;
		for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		ret+=dp[0][i][j][0];
		printf("Case #%d: %lld\n",ca,ret);
	}
	return 0;
}
