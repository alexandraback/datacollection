#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>

#define mkp make_pair
#define fi first
#define se second

using namespace std;

typedef pair <int, int> PI;
const int MAXN = 2005;

struct node
 {
       int id;
       node (int X) : id(X) {}
       inline bool operator < (const node &Y) const
        {
              return id > Y.id;
        }
 };
 
priority_queue <int> h;
bool used1[MAXN];
int dp[MAXN][MAXN];
PI a[MAXN], b[MAXN];
int i, j, k, N, cas, cases, x, t, ans;

void init()
 {
     scanf("%d", &N);
     for (i = 1; i <= N; i ++)
         scanf("%d %d", &a[i].se, &a[i].fi);
     sort(a + 1, a + N + 1);
     for (i = 1; i <= N; i ++)
         b[i] = mkp(a[i].se, i);
     sort(b + 1, b + N + 1);
 }
 
void work()
 {
     while (!h.empty()) h.pop();
     memset(used1, 0, sizeof(used1));
     for (i = j = 1, x = ans = 0; i <= N; i ++, ans ++)
      {
            for (; j <= N && b[j].fi <= x; j ++)
                h.push(b[j].se);
            while (x < a[i].fi)
             {
                  if (h.empty())
                   {
                     printf("Case #%d: Too Bad\n", cas);
                        return;
                   }
                  t = h.top();h.pop();
                  if (t < i)
                   {
                        printf("Case #%d: Too Bad\n", cas);
                        return;
                   }
                  ++ x;
                  used1[t] = true;
                  ++ ans;
                  for (; j <= N && b[j].fi <= x; j ++)
                      h.push(b[j].se);
             }
            x += (used1[i] ? 1 : 2);
      }
     printf("Case #%d: %d\n", cas, ans);
 }
 
int main()
 {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    scanf("%d", &cases);
    for (cas = 1; cas <= cases; cas ++)
     {
        init();
        work();
     }
    return 0;
 }
