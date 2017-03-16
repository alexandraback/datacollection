#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 1010;
bool vis[maxN];
int a[maxN], b[maxN], d[maxN];
int T, x, p, s, ans, n;
bool bad;


bool cmp2(int x, int y)
{
     return b[x] < b[y];
}

int main()
{
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a[i], &b[i]);
            d[i] = i;
        }   
        sort(d, d + n, cmp2);
        ans = n;
        x = s = 0;
        bad = false;
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            while (s < b[d[i]])
            {
                  p = -1;
                  for (int j = 0; j < n; j++)
                      if (!vis[j] && s >= a[j] && (p == -1 || b[p] < b[j]))
                         p = j;
                  if (p == -1)
                  {
                        bad = true;
                        break;
                  }
                  s++;
                  ans++;
                  vis[p]++;
            }
            if (bad) break;
            if (!vis[d[i]]) s += 2;
            else s++;
            vis[d[i]] = true;
        }
        if (bad) printf("Case #%d: Too Bad\n", cas);
        else printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
