#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int A,N,v[401010],aux;
int cost[401010];
int ind=0,ret=101010,T;
void init()
{
        for(int i=0;i<=10000+N;++i)
            cost[i]=0;
        for(int i=0;i<=10000+N;++i)
            v[i]=0;
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("ax.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {   ++ind;
        ret = 101010;
        init();
        scanf("%d%d\n",&A,&N);
        for(int i=1;i<=N;++i)
            scanf("%d",&v[i]);
        sort(v+1,v+N+1);
        aux = A;
        if(A==1)
            {
                printf("Case #%d: %d\n",ind,N);
                continue;
            }

        for(int i=1;i<=N;++i)
        {
            while(v[i]>=aux)
            {
             //   printf("%d ",aux);
                aux += (aux-1);
                ++cost[i];
            }
            aux += v[i];
            cost[i]+=cost[i-1];
        }
        for(int i=0;i<=N;++i)
        {
            //printf("%d %d\n",cost[i],i);
            ret = min(ret,cost[i] + N-i);
        }
        printf("Case #%d: %d\n",ind,ret,N);
    }
    return 0;
}
