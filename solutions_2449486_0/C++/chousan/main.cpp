#include<stdio.h>
#include<iostream>
using namespace std;
int map[200][200];
int n,m;
bool check(int x,int y)
{
    int i;
    for(i=0;i<m;++i)
    {
        if(map[x][i]>map[x][y])break;
    }
    if(i==m)return true;
    for(i=0;i<n;++i)
    {
        if(map[i][y]>map[x][y])break;
    }
    if(i==n)return true;
    return false;
}
bool solve()
{
    int i,j;
      for(i=0;i<n;++i)
        {
            for(j=0;j<m;++j)
            {
                if(!check(i,j))return false;
            }
        }
        return true;
}
int main()
{
    freopen("3.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    for(int c=1;c<=cas;++c)
    {
        printf("Case #%d: ",c);
        int i,j;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;++i)
        {
            for(j=0;j<m;++j)
            {
                scanf("%d",&map[i][j]);
            }
        }
        if(solve())printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}
