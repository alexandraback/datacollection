#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXN = 100005;

const double eps = 1e-8;

double ans, now, p[MAXN];
int i, j, k, A, B, T, cases, cas;

void init()
 {
     scanf("%d %d", &A, &B);
     for (i = 1; i <= A; i ++)
         scanf("%lf", &p[i]);
 }
 
void work()
 {
     ans = B + 2;
     for (i = 1, now = 1.0; i <= A; i ++)
      {
            now *= p[i];
            ans = min(ans, now * (double) (A - i + B - i + 1) + (1.0 - now) * (double)(A - i + B - i + B + 2));
      }
     printf("Case #%d: %.8f\n", cas, ans);
 }
 
int main()
 {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d", &cases);
    for (cas = 1;  cas <= cases; cas ++)
     {
        init();
        work();
     }
    return 0;
 }
