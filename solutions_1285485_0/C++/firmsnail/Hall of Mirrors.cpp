#include <iostream>
using namespace std;
double d;
int cases, n, m;
int x, y, ans;
char c;
double dis(int x1, int y1, int x2, int y2)
{
       
}
void solve()
{
     ans = 0;
     for (int i = 0; i < n; ++i)
     {
         if(dis(i, 0, x, y) <= d) ++ans;
         if(dis(i, n-1, x, y) <= d) ++ans;
     }
     for (int i = 1; i < m-1; ++i)
     {
         if(dis(0, i, x, y) <= d) ++ans;
         if(dis(n-1, i, x, y) <= d) ++ans;
     }
}
int main()
{
    scanf("%d", &cases);
    for (int t = 1; t <= cases; ++t)
    {
        scanf("%d%d%llf", &n, &m, &d);
        for (int i = 0; i < n; ++i)
        {
            getchar();
            for (int j = 0; j < m; ++j)
            {
                c = getchar();
                if(c == 'X')
                {
                     x = i;
                     y = j;
                }
            }
        }
        solve();
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
