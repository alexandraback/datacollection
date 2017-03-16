#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int maxn = 500000 + 50 ;

int N ;
struct Node{
    int s , t ;
    bool operator < (const Node&r) const {
        return t > r.t ;
    }
}e[maxn];

int main()
{
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("c.txt", "w", stdout) ;

    int T, cas= 1 ;
    scanf("%d", &T) ;
    while(T--) {
        int n ;
        scanf("%d", &n) ;

        N = 0 ;
        for(int i=0; i<n; i++) {
            int s , h , t ;
            scanf("%d%d%d", &s, &h, &t) ;
            for(int j=0; j<h; j++) {
                e[N++] = (Node){s , t+j} ;
            }
        }

        if(N <= 1) {
            printf("Case #%d: %d\n", cas++ , 0) ;
            continue ;
        }

        sort(e,e+N) ;
        double tmp1 = (double) e[0].t * (360.0 - e[0].s) / 360.0 ;
        double tmp2 = (double) e[1].t * (360+360.0 - e[1].s) / 360.0 ;

        int ans = 0;
        if(tmp2 - tmp1 < 0) ans = 1 ;

        printf("Case #%d: %d\n", cas++ , ans)  ;
    }
    return 0;
}
