#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,n,m,map[11][11];
bool check()
{
    int i,j,r,flag=1;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(map[i][j]==1)
        {
            int tag1=1,tag2=1;
            for(r=1;r<=m;r++)
            {
                if(map[i][r]!=1)
                {
                    tag1=0;break;
                }
            }
            for(r=1;r<=n;r++)
            {
                if(map[r][j]!=1)
                {
                    tag2=0;break;
                }
            }
            if(tag2+tag1==0)
            {
                flag=0;break;
            }
        }
        if(!flag)
        break;
    }
    if(flag==0)
    return false;
    return true;
}
int main()
{
    freopen("B.txt","r",stdin);
    freopen("1.txt","w",stdout);
    int k=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int i,j;
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            scanf("%d",&map[i][j]);
        }

        if(check())
        printf("Case #%d: YES\n",k++);
        else
        printf("Case #%d: NO\n",k++);
    }
}
