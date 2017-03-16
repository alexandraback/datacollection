#include <cstdio>
#include <cstring>
using namespace std;

int T;
int N,M;
int k;
bool mat[1100][1100];
bool p[1100];
int v[1100];
int cas;
int loop;
bool ff;
int lz;

void dfs(int x)
{
    for(int j=1;j<=N;j++)
    {
        if(mat[x][j] && j!=lz)
        {

            if(v[j] ==0)
            {
                v[j]=loop;
                dfs(j);
            }
            else
            if(v[j]!=loop){ff=1;return;}
            if(ff) return;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    cas = 0;
    while(T--)
    {
        scanf("%d",&N);ff=0;
        memset(mat,0,sizeof(mat));
        memset(p,0,sizeof(p));
        for(int i=1;i <= N;i ++)
        {
            scanf("%d",&M);if(M>1) p[i]=1;
            for(int j=1;j<=M;j++)
            {
                scanf("%d",&k);
                mat[i][k]=1;
            }
        }
        for(int i=1;i<=N;i++)
        {
            lz = i;
            if(p[i])
            {
                memset(v,0,sizeof(v));
                loop = 0;
                for(int k=1;k<=N;k++)
                    if(mat[i][k])
                    {
                        if(v[k]==loop && loop != 0)
                        {
                            ff = 1;break;
                        }
                        loop ++;
                        v[k]=loop;
                        dfs(k);
                        if(ff) break;
                    }
                if(ff) break;
            }
        }
        cas ++;
        if(ff) printf("Case #%d: Yes\n",cas); else printf("Case #%d: No\n",cas);
    }
    return 0;
}
