#include <iostream>
#include <algorithm>
using namespace std;

const int nmax = 1E7;
typedef long long ll;
ll fs[nmax];
int nfs;

bool pal(ll x) {
    int d[20];
    int i, nd = 0;
    
    for (i = 0; x; i++) {
        d[nd++] = x % 10;
        x /= 10;
    }

    for (i = 0; i < nd / 2; i++) if (d[i] != d[nd - i - 1]) return false;
    
    return true;
}

int main() {
    for (ll i = 1; i <= nmax; i++) {
        if (pal(i) && pal(i * i)) fs[nfs++] = i * i;
    }
    
    int nt, it;

    cin >> nt;
    for (it = 1; it <= nt; it++) {
        ll a, b, r;

        cin >> a >> b;
        r = upper_bound(fs, fs + nfs, b) - lower_bound(fs, fs + nfs, a);
        
        cout << "Case #" << it << ": " << r << endl;
    }
}
