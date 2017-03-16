#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m,t;
int map[110][110];
bool f(int x,int y)
{
    int xmax=map[x][0];
    for(int i=0;i<m;i++)
    {
        if(map[x][i]>=xmax)
        xmax=map[x][i];
    }
    int ymax=map[0][y];
    for(int i=0;i<n;i++)
    {
        if(map[i][y]>=ymax)
        ymax=map[i][y];
    }
    return (xmax==map[x][y]||ymax==map[x][y]);
}
bool judge()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!f(i,j))
            return false;
        }
    }
    return true;
}
int main ()
{
     //freopen("B-small-attempt0.in","r",stdin);
    //freopen("b.txt","w",stdout);
    scanf("%d",&t);
    for(int l=1; l<=t; l++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        printf("Case #%d: ",l);
        if(judge())
        printf("YES\n");
        else
        printf("NO\n");
    }
}

