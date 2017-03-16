#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int inf = 1e9;
const int maxn = 1e6 + 6;

int M, n;
int a[maxn];

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        int ans = inf;
        
        scanf("%d%d", &M, &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        if (M == 1)
        {
            ans = n;
            printf("Case #%d: ", T);
            printf("%d\n", ans);
            fprintf(stderr, "%d/%d cases done!\n", T, NT);
            continue;
        }
        sort(a, a + n);
        for (int i = 0; i <= n; i++)
        {
            int cursize = M;
            int cur = 0;
            int curans = 0;
            while (cur < i)
            {
                if (cursize > a[cur])
                {
                    cursize += a[cur];
                    cur++;
                }
                else
                {
                    cursize += cursize - 1;
                    curans++;
                }
            }
//             cout << i << ' ' << curans << endl;
            ans = min(ans, curans + (n - i));
        }
        
        printf("Case #%d: ", T);
        printf("%d\n", ans);
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
