#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int N,MAX;
int P[1024];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int casT;
    scanf("%d",&casT);
    for(int cas=1;cas<=casT;cas++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&P[i]);MAX=max(MAX,P[i]);
        }
        int ans = MAX;
        for(int d=1;d<MAX;d++)
        {
            int t = 0;
            for(int i=0;i<N;i++)
            {
                t+=(P[i]+d-1)/d - 1;
            }
            ans = min(ans,d+t);
        }
        printf("Case #%d: %d\n",cas,ans);
    }

    return 0;
}
