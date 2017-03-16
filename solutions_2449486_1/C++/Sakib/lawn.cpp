#include <stdio.h>
#include <iostream>

using namespace std;

int lawn[105][105],n,m;

bool check(int x,int y)
{
    int i,j,k;

    for(j=0;j<m;j++)
    {
        if(lawn[x][j]<=lawn[x][y]) continue;
        break;
    }

    //cout<<j<<endl;

    if(j==m) return 1;

    for(i=0;i<n;i++)
    {
        if(lawn[i][y]<=lawn[x][y]) continue;
        break;
    }

    if(i==n) return 1;

    return 0;
}

int main()
{
    int i,j,k,t,total,r;

    freopen("B-large.in","r",stdin);
    freopen("lawn-out-large.txt","w",stdout);

    scanf("%d",&total);

    for(t=1;t<=total;t++)
    {
        scanf("%d %d",&n,&m);

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++) scanf("%d",&lawn[i][j]);
        }

        for(r=1,i=0;i<n && r;i++)
        {
            for(j=0;j<m && r;j++)   if(!check(i,j)) r=0;
        }

        printf("Case #%d: %s\n",t,r ? "YES" : "NO");
    }

    return 0;
}
