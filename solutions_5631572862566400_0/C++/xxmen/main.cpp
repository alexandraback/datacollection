#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int a[1010], b[1010];
bool v[1010];
int n, ans = 0;
int c[1010];
int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t, Case = 0;
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for (int i = 1; i <=n; i++)
        {
            int x;
            scanf("%d", &x);
            a[i] = x;
            b[x] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            memset(v, false, sizeof(v));
            v[i] = true;
            c[0] = i;
            int m = 0;
            while (1)
            {
                if (m > 0 && c[m - 1] == a[c[m]])
                {
                    if (!v[b[c[m]]])
                    {
                        m++;
                        c[m] = b[c[m - 1]];
                        v[c[m]] = true;
                    }
                    else{
                        ans = max(ans, m + 1);
                        break;
                    }
                }
                else{
                    m++;
                    if (!v[a[c[m - 1]]])
                    {
                        c[m] = a[c[m - 1]];
                        v[c[m]] = true;
                    }
                    else{
                        if (c[0] == a[c[m - 1]])
                            ans = max(ans, m);
                        break;
                    }
                }
            }
            
            
        }
        
        printf("Case #%d: %d\n", ++Case, ans);
    }
}