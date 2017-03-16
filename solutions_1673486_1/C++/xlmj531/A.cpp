#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int A, B, cas;
double p[100010];
double ans;

int main()
{
    freopen("A2.in","r",stdin);
    freopen("A2.out","w",stdout);
    scanf("%d",&cas);
    for (int run = 1; run<=cas; run++ )
    {
        scanf("%d%d",&A,&B);
        ans = B+2;
        double tmp = 1;
        for (int i = 1; i<=A; i++ )
        {
            scanf("%lf",p+i);
            tmp = tmp*p[i];
            ans = min(ans, tmp*(A-i+B-i+1)+(1-tmp)*(A-i+B-i+1+B+1));
        }
        printf("Case #%d: %.6f\n",run,ans);
    }
    return 0;
}
