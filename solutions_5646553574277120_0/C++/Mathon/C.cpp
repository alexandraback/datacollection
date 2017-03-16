#include<vector>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=2000+5;

bool vis[maxn];

int A[maxn];

int main()
{
    int C,D,V,T,temp;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C.txt","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(vis,false,sizeof vis);
        scanf("%d%d%d",&C,&D,&V);
        int K=D;
        for(int i=0;i<D;i++)
        {
            scanf("%d",&A[i]);
            vis[A[i]]=true;
        }
        bool flag=false;
        while(!flag)
        {
            flag=true;
            for(int i=1;i<(1<<D);i++)
            {
                int t=0;
                for(int j=0;j<D;j++)
                {
                    if((1<<j) & i)
                    {
                        t+=A[j];
                    }

                }
                vis[t]=true;
            }
           for(int i=1;i<=V;i++)
           {
             if(!vis[i])
             {
                 flag=false;
                // printf("%d!\n",i);
                 A[D++]=i;
                 break;
             }

           }


        }
        printf("Case #%d: %d\n",cas,D-K);

    }

    return 0;
}
