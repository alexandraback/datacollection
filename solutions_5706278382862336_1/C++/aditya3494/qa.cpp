#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

long long gcdr (long a,long b)
{
  if ( a==0 ) return b;
  return gcdr ( b%a, a );
}

int main()
{
    freopen("A-large.in.txt","r",stdin);
    freopen("oxwer2.txt","w",stdout);

    int t;
    scanf("%d", &t);

    for(int i = 1;i <= t;i++) {
        long long n, d;
        scanf("%lld/%lld", &n, &d);
        long gcd = gcdr(n,d);
        n = n/gcd;
        d = d/gcd;

        long long ans = -1;
        if(d && ((d & (d-1)) == 0)) {
            int level = (int)log2(d);
            ans = -1;

            if(n == 1) {
                ans = level;
            } else {
                ans = -1;
                long long x = 1, p = 1;
                if(n & 1) {
                    while(n > x) {
                        x = x + (long long)pow(2,p++);
                    }
                    p--;
                    ans = level - p;
                }
            }
        }

        if(ans == -1) {
            printf("Case #%d: impossible\n",i);
        } else {
            printf("Case #%d: %lld\n", i, ans);
        }
    }
    return 0;
}
