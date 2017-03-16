#include <iostream>

#define ll long long int

using namespace std;

int T;
ll r, t;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> r >> t;
        cout << "Case #" << (i+1) << ": ";
        ll k = 0, a = 0, v = 0;
        while (1) {
            ll m = 0;
            ll j = 0;
            for (ll i = 1; ; i *= 2) {
                ll x = 4*((v+i-1)*(v+i)/2-((v-1)*(v))/2);
                ll u = a+2*r*i+x+i;
                if (u > t) break;
                m = u;
                j = i;
            }
            if (m == 0) break;
            a = m;
            v += j;
        }
        cout << v << endl;
    }
}
