#include <stdio.h>

int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    long long a, b, k, t, cases = 0;
    
    long long i, j, ans;
    
    scanf("%lld", &t);
    
    while (t--) {
          ans = 0;
          
          scanf("%lld%lld%lld", &a, &b, &k);
          cases++;
          printf("Case #%lld: ", cases);
          
          for (i = 0; i < a; i++) {
              for (j = 0; j < b; j++) {
                  if ((i & j) < k) {
                     ans++;
                  }
              }
          }
          
          printf("%lld\n", ans);
    }
    
    return 0;
}
    
