#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1111];
int a[1111];
int main(int argv, char** argc)
{
    int T,t,n,ans;
    if (argv > 1)
        freopen(argc[1], "r", stdin);
    if (argv > 2)
        freopen(argc[2], "w", stdout);
    scanf("%d",&T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; ++i) scanf("%d", a+i);
        ans = 1001;
        for (int i = 0; i < 1001; ++i)
        {
            if (i>=ans) break;
            int l, r, mid;
            for (l=0, r=1000; l < r-1;)
            {
                int mid=(l+r)/2;
                int res = 0;
                for (int j = 0; j < n; ++j)
                    res += (a[j]-1)/mid;
                if (res > i)
                    l = mid;
                else
                    r = mid;
            }
            ans = min(ans, i+r);
        }
        
        printf("Case #%d: %d\n", t, ans);
    }
}