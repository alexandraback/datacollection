#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
typedef unsigned long long ll;
const ll inf = 1000000000000000000L;

ll R, t;

ll f(ll x) {
    //if(x > 1000000000L) return 0;
    //cout << x*x*2+x*R << endl;
    return (double)x*x*2.0+(double)x*R*2.0 - (double)x <= (double)t;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("Aout.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++) {
        cin >> R >> t;
        //cout << f(50) << endl;
        ll m, l = 1, r = inf;
        while(l <= r) {
            //cout << "m=" << m << endl;
            m = l + (r - l) / 2;
            if(f(m)) l = m + 1;
            else r = m - 1;
        }
        printf("Case #%d: ", kase);
        cout << r << endl;
    }
    return 0;
}
