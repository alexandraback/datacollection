#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
#include<queue>
using namespace std;

int admat[1005][15],val[1005];

void bfs(int node)
{

    queue<int> qi;
//    qi.clear();
    qi.push(node);
    val[node]=1;
    int tmp,i;
    while(!qi.empty())
    {
        tmp=qi.front();

        for(i=1;i<=admat[tmp][0];i++)
        {
            qi.push(admat[tmp][i]);
            val[admat[tmp][i]]+=val[tmp];
            if(val[admat[tmp][i]]>1)
                return;
        }
        qi.pop();
    }
}
int main()
{

    freopen("a-large.in","r",stdin);
    freopen("a-large.out","w",stdout);

    int test,i,j,kase,n,m,mi;
    scanf("%d",&test);
    for(kase=1;kase <= test; kase++)
    {
        printf("Case #%d: ",kase);

        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&admat[i][0]);
            for(j=1;j<=admat[i][0];j++)
            {
                scanf("%d",&admat[i][j]);
            }
        }

        bool ans=true;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=n;j++)
                val[j]=0;
            if(ans)
                bfs(i);
            else
                break;
            for(j=1;j<=n;j++)
            {
                if(val[j]>1)
                    ans=false;
            }
        }
        if(ans)
            printf("No\n");
        else
            printf("Yes\n");
    }


    return 0;
}
