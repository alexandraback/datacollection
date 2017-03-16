#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

typedef long long int int64;

using namespace std;

int main(){
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int n; scanf("%d", &n);
        int64 an[3], dn[3];
        int cc = 0; 
        for(int lx = 0;lx < n;lx++){
            int64 d, h, m; scanf("%lld %lld %lld", &d, &h, &m);
            for(int64 i = 0;i < h;i++){
                an[cc] = m+i;
                dn[cc] = d;
                cc++;
            }
        }
        if(cc == 1) printf("Case #%d: 0\n", lt);
        else if(cc == 2){
            if(an[0] < an[1]) swap(an[0], an[1]), swap(dn[0], dn[1]);
            // an[0] >= an[1]
            int64 dt;
            dt = (720-dn[1]);
            printf("Case #%d: %d\n", lt, dt*an[1] <= (360-dn[0])*an[0]);
        }
    }
    return 0;
}
