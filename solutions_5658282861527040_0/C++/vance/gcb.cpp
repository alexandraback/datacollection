#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
int main()
{
    int t, a, b, k, i, j;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    for(int cnt = 1;cnt <= t;cnt++){
        scanf("%d %d %d",&a,&b,&k);
        int ret = 0;
        for(i=0;i<a;i++)for(j=0;j<b;j++)if((i&j) < k)
            ret ++;
        printf("Case #%d: %d\n",cnt,ret);
    }
    return 0;
}
