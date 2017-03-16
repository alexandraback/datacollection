#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

double a[1001], v[1001];
int test, ans1, ans2, n;
bool b[1001];

int main(){
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    scanf("%d", &test);
    for (int uu = 1; uu <= test; uu++)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%lf", &v[i]);
        sort(a + 1, a + n + 1); sort(v + 1, v + n + 1);
        ans1 = 0;
        for (int i = 1; i <= n; i++)
        {
            bool ok = true;
            for (int j = i, k = 1; j <= n; j++, k++)
                if (a[j] < v[k])
                {
                   ok = false;
                   break;
                }
            if (ok) 
            {
                ans1 = n - i + 1;
                break;
            }
        }
        ans2 = 0;
        memset(b, false, sizeof(b));
        for (int i = 1; i <= n; i++)
        {
            int position = 0; double Min = 2.0;
            for (int j = 1; j <= n; j++)
                if (!b[j] && v[j] > a[i] && v[j] < Min)
                   Min = v[j], position = j;
            if (position) b[position] = true;
            else 
            {
                 ++ans2;
                 Min = 2.0;
                for (int j = 1; j <= n; j++)
                    if (!b[j] && v[j] < Min)
                       Min = v[j], position = j;
                b[position] = true;
            }
        }
        printf("Case #%d: %d %d\n", uu, ans1, ans2);
    }
}
                
