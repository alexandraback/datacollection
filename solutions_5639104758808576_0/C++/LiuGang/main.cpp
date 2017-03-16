#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1050 ;

char buf[maxn] ;
int a[maxn] , N ;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w" ,stdout) ;

    int T , cas = 1;
    scanf("%d", &T) ;
    while(T--)  {
        scanf("%d%s", &N , buf) ;
        for(int i=0; i<=N; i++) a[i] = buf[i] - '0' ;
        int sum = 0 , ans = 0;
        for(int s = 0 ; s<=N; s++) {
            for(int i=1; i<=a[s]; i++) {
                if(sum >= s) sum ++ ;
                else {
                    while(sum < s) sum ++ , ans ++ ;
                    sum ++ ;
                }
            }
        }
        printf("Case #%d: %d\n", cas++ , ans) ;
    }
    return 0;
}
