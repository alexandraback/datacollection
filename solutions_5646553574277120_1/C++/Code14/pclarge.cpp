#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;


typedef long long LL;

LL C, D, V, d[105];
bool flag;

LL solve() {
    LL ans = 0;

    if ( flag == false ) { //renew
        d[D] = 1;
        ans = 1;
        D ++;
    }

    sort(d,d+D);

    LL cur = d[0]*C;
    LL index = 1;

    while ( cur < V ) { // not reach V
        if ( index < D ) {
            if ( cur >= d[index]-1 ) { // cur = 3, d[index] = 4 << legal
                cur += d[index]*C;
                index ++;
            }
            else { // cur = 3, d[index] = 5 << such like this
                ans ++;
                cur += (cur+1)*C;
            }
        }
        else { // no more coin
            ans ++;
            cur += (cur+1)*C;
        }
    }

    return ans;
}


int main() {

    LL i, j, t, T;

    scanf("%lld",&T);

    for ( t = 1 ; t <= T ; t ++ ) {
        scanf("%lld %lld %lld",&C,&D,&V);
        for ( flag = false, i = 0 ; i < D ; i ++ ) {
            scanf("%lld",&d[i]);
            if ( d[i] == 1 ) flag = true; // need to add 1 to the coin
        }

        printf("Case #%lld: %lld\n",t,solve());
    }

    return 0;
}
