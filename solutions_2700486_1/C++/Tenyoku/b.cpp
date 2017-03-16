#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, x, y;
double dp[1000000];

int get_now(int n)
{
    int l = 0, r = 5000;
    while(l+1!=r)
    {
        int c = (l+r)/2;
        if((c*2)*(c*2-1)/2 <= n) l = c;
        else r = c;
    }
    return l*2-1;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int cnt=1; cnt<=T; ++cnt)
    {
        scanf("%d %d %d", &n, &x, &y);
        if(x<0) x=-x;
        printf("Case #%d: ", cnt);
        int now = get_now(n);
        if(x+y+1<=now) puts("1.0");
        else if(x+y>now+2) puts("0.0");
        else
        {
            n -= now*(now+1)/2;
            int num = y+1;
            if(num==now+2||n<num) puts("0.0");
            else
            {
                memset(dp, 0, sizeof(dp));
                dp[0] = 1;
                for(int i=0; i<n; ++i)
                {
                    for(int j=min(n-1, now); j>=0; --j)
                    {
                        if(i-j<now+1)
                        {
                            dp[j+1] += dp[j]/2;
                            dp[j]/=2;
                        }
                        else
                        {
                            dp[j+1] += dp[j];
                            dp[j] = 0;
                        }
                    }
                }
                double ans = 0;
                for(int i=num; i<=n; ++i) ans += dp[i];
                printf("%.7lf\n", ans);
            }
        }
    }
    return 0;
}
