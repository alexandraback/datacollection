#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

double a[1001], b[1001];
int n;

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
            scanf("%lf", &a[i]);
        for(int i=0; i<n; ++i)
            scanf("%lf", &b[i]);
        sort(a, a+n);
        sort(b, b+n);
        printf("Case #%d: ", cas);
        int ans = 0;
        for(int ra=n-1, rb=n-1; ra>=0&&rb>=0; --ra)
        {
            while(b[rb]>a[ra]) --rb;
            if(rb>=0) ++ans, --rb;
        }
        printf("%d ", ans);
        ans = 0;
        set<double> se;
        for(int i=0; i<n; ++i)
            se.insert(b[i]);
        for(int i=0; i<n; ++i)
        {
            set<double>::iterator t = se.upper_bound(a[i]);
            if(t == se.end())
            {
                ++ans;
                se.erase(se.begin());
            }
            else se.erase(t);
        }
        printf("%d\n", ans);
    }
    return 0;
}
