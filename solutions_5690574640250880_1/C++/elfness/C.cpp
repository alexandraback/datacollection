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

char map[52][52];

int _,r,c,m;

int dp[52][52][2520],en;

bool doit()
{
    if(en==1)
    {
        map[0][0]='c';
        return true;
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<c;i++)
    dp[1][i][2*(i+1)]=1,dp[0][i][i+1]=1;
    for(int i=1;i<r;i++)
    for(int j=0;j<c;j++)
    for(int k=0;k<=en;k++)
    if(dp[i][j][k]==1)
    {
        for(int kk=1;kk<=j;kk++)
        dp[i+1][kk][k+kk+1]=1;
    }
    for(int i=1;i<r;i++)
    for(int j=1;j<c;j++)
    if(dp[i][j][en]==1)
    {
        int re=en;
        for(int x=i;x>=0;x--)
        for(int y=0;y<c;y++)
        if(dp[x][y][re]==1)
        {
            for(int k=0;k<=y;k++)
            map[x][k]='.';
            re-=y+1;
            break;
        }
        map[0][0]='c';
        return true;
    }
    return false;
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&_);
	for(int ca=1;ca<=_;ca++)
	{
		scanf("%d%d%d",&r,&c,&m);
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		map[i][j]='*';
		printf("Case #%d:\n",ca);
		en=r*c-m;
		if(r==1)
		{
		    map[0][0]='c';
		    for(int i=1;i<en;i++)
		    map[0][i]='.';
		}
		else if(c==1)
		{
		    map[0][0]='c';
		    for(int i=1;i<en;i++)
		    map[i][0]='.';
		}
		else
		{
		    if(!doit())
		    {
		        puts("Impossible");
                continue;
		    }
		}
		for(int i=0;i<r;i++,puts(""))
		for(int j=0;j<c;j++)
		printf("%c",map[i][j]);
	}
	return 0;
}
