#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int gcd(long long int a, long long int b)
{
    if (a%b == 0)
       return b;
    else return gcd(b,a%b);

}
int main()
{

freopen("aal.in","r",stdin);
freopen("abcd.txt","w",stdout);
    long long int t,p,q,g,temp,cases,cnt;
 scanf("%lld",&t);
    for (cases = 1; cases <= t; cases++) {
          cnt = 0;
          scanf("%lld/%lld",&p,&q);
          g = gcd(p,q);
          p = p/g;
          q = q/g;
          temp = q;

          while (temp != 0) {
             if (temp % 2 == 1 && temp != 1)
                 break;
             temp = temp/2;
          }
          if (temp != 0) {
             printf("Case #%lld: impossible\n",cases);
             continue;
          }



          while (q > p) {
                q = q/2;
                cnt++;

          }

          printf("Case #%lld: %lld\n",cases,cnt);
    }
    return 0;
}


