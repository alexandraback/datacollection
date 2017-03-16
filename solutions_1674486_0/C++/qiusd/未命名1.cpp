#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int t,n,m,p;

bool mp[1010][1010];

int num;
void dfs(int now,int e)
{
    int i,j;
    if(now==e)
    {
        num++;
        return;
    }
    for(i=1;i<=n;i++)
        if(mp[now][i]==1)
            dfs(i,e);
}



int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a-small-0.out","w",stdout);
    
    int i,j;
    scanf("%d",&t);
    int tt=1;
    while(t--)
    {
        memset(mp,0,sizeof(mp));
        int flag=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(j=1;j<=m;j++)
            {
                scanf("%d",&p);
                mp[i][p]=1;
            }
        }
        //puts("");
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%d ",mp[i][j]);
            }
            puts("");
        }*/
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    num=0;
                    dfs(i,j);
                    //printf("      %d %d %d\n",num,i,j);
                    if(num>1)
                        break;
                }
            }
            if(num>1)
                break;
        }
        printf("Case #%d: ",tt++);
        //printf("\n%d\n",num);
        if(num>1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    
    
    //system("pause");
    return 0;
} 
