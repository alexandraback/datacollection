/* HellGeek */
/* Shiva Bhalla */
/* iit2012077 */


#include<stdio.h>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<math.h>

#define LL long long
#define FIT(i,t) for(i=0;i<t;i++)
#define FIN(i,n) for(i=0;i<n;i++)
#define FJT(j,t) for(j=0;j<t;j++)
#define FJN(j,n) for(j=0;j<n;j++)
#define MAX2(a,b) a>b?a:b
#define MIN2(a,b) a>b?b:a
#define REP(i,a,b) for(i=a;i<=b;i++)

using namespace std;

int main()
{
    
    
    LL aj, bakar, karte, tc, cases = 0;
    
    LL i, j, an;
    
    scanf("%lld", &tc);
    
    while (tc--) {
          an = 0;
          scanf("%lld%lld%lld", &aj, &bakar, &karte);
          cases++; printf("Case #%lld: ", cases);
          for (i = 0; i < aj; i++) {
              for (j = 0; j < bakar; j++) {
                  if ((i & j) < karte) {
                     an++;}}}printf("%lld\n", an);}
    return 0;
}
    
