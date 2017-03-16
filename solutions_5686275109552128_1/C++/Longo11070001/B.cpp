#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define pb push_back
using namespace std;
const int maxn = 1010;
int cnt[maxn];
int num[maxn];
int D,ans,ma;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T,cas,p,i,j,cur;
    /*puts("5");
    puts("1000");
    for(i=1; i<=1000; i++) printf("%d ",i); puts("");
    puts("1000");
    for(i=1; i<=1000; i++) printf("1000 "); puts("");
    puts("1");
    puts("1000");
    puts("1");
    puts("512");
    puts("1");
    puts("999");*/
    scanf("%d",&T);
    for(cas=1; cas<=T; cas++)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&D); ma = 0;
        for(i=1; i<=D; i++) scanf("%d",&num[i]),ma = max(ma,num[i]);
        ans = ma;
        int kk = 0;
        for(i=1; i<=ma; i++)
        {
            kk = 0;
            for(j=1; j<=D; j++)
            {
                int yy = num[j]/i;
                if(num[j] % i == 0)
                {
                    yy--;
                }
                kk += yy;
            }
            ans = min(ans,kk+i);
        }
        printf("Case #%d: %d\n",cas,ans,ma);
    }
    return 0;
}
