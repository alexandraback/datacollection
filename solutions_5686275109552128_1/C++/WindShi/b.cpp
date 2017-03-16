#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, a[1001];

int main(){
     freopen("b.in", "r", stdin);
     freopen("b.out", "w", stdout);
     scanf("%d", &test);
     for (int uu = 1; uu <= test; uu++)
     {
          printf("Case #%d: ", uu);
          scanf("%d", &n);
          for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
          int ans = 1 << 30;
          for (int i = 1; i <= 1000; i++)
          {
               int num = i;
               for (int j = 1; j <= n; j++) 
               {
                    num += a[j] / i;
                    if (!(a[j] % i)) --num;
               }
               ans = min(ans, num);
          }
          printf("%d\n", ans);
     }
}
