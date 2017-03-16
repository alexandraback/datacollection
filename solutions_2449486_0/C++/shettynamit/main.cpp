#include <iostream>
#include <cstdio>
#define N 100
#define M 100
using namespace std;
int G[N][M];
int R[N],C[M];
int main()
{
    freopen("small.in","r",stdin);
    freopen("small.out","w",stdout);
    int t;
    scanf("%d",&t);
    int n,m,i,j;
    for(int c=1;c<=t;c++)
    {
        scanf("%d%d",&n,&m);
        fill(R,R+n,0);
        fill(C,C+m,0);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&G[i][j]);
                R[i] = max(R[i],G[i][j]);
                C[j] = max(C[j],G[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(G[i][j]!=R[i]&&G[i][j]!=C[j])
                    break;
            }
            if(j<m)
                break;
        }
        printf("Case #%d: ",c);
        if(i<n)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
