#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int bo[110][110];
int ma[110][110][4];
int max(int a,int b)
{
    return a>b?a:b;
}
void init(int n,int m)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        ma[i][1][0]=bo[i][1];
        for(j=2;j<=m;j++)
        ma[i][j][0]=max(bo[i][j],ma[i][j-1][0]);
        ma[i][m][2]=bo[i][m];
        for(j=m-1;j>0;j--)
        ma[i][j][2]=max(bo[i][j],ma[i][j+1][2]);
    }
    for(j=1;j<=m;j++)
    {
        ma[1][j][1]=bo[1][j];
        for(i=2;i<=n;i++)
        ma[i][j][1]=max(bo[i][j],ma[i-1][j][1]);
        ma[n][j][3]=bo[n][j];
        for(i=n-1;i>0;i--)
        ma[i][j][3]=max(bo[i][j],ma[i+1][j][3]);
    }
}
int solve(int n,int m)
{
    init(n,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(ma[i][j][k]>bo[i][j]&&ma[i][j][(k+1)%4]>bo[i][j])
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("dd.txt","w+",stdout);
    int ncase,time=0;
    scanf("%d",&ncase);
    memset(bo,0,sizeof(bo));
    while(ncase--)
    {
        printf("Case #%d: ",++time);
        int n,m,i,j;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            scanf("%d",&bo[i][j]);
        }
        if(solve(n,m))
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
