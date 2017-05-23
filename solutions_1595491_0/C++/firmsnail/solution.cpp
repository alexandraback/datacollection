#include <iostream>
using namespace std;
#define min(a, b) (a<b ? a:b)
int cases, n, s, p, ans, surprising;
int main()
{
    freopen("B-small-attempt0(1).in", "r", stdin);
    freopen("B-small-attempt0(1).out", "w", stdout);
    scanf("%d", &cases);
    for (int t = 1; t <= cases; ++t)
    {
        scanf("%d%d%d", &n, &s, &p);
        ans = surprising = 0;
        for (int i = 0; i < n; ++i)
        {
            int a;
            scanf("%d", &a);
            if((a+2)/3 >= p) ++ans;
            else if(a)
            {
                if(1+a/3 >= p) ++surprising;
                else if(a%3 == 2 && 2+a/3>= p) ++surprising;
            }
        }
        ans += min(surprising, s);
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
