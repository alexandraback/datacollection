#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1050 ;

int D;
int P[maxn];

int main()
{
   // freopen("B-large.in", "r" ,stdin) ;
   //freopen("large.txt", "w", stdout) ;


    int T , cas = 1;
    scanf("%d", &T) ;
    while(T--) {
        scanf("%d", &D) ;
        int ans = 1000 , mx = 0 ;
        for(int i=1; i<=D; i++) scanf("%d", &P[i]) , mx = max(mx , P[i]) ;

        for(int pice = 1; pice <= mx; pice++ ) {
            int sum = 0;
            for(int i=1; i<=D; i++) {
                int tmp = ( P[i] % pice == 0 ? P[i] / pice :  P[i] / pice + 1) - 1 ;
                sum += tmp ;
            }
            ans = min(ans , pice + sum) ;
        }
        printf("Case #%d: %d\n", cas++ , ans) ;
    }
    return 0;
}
