#include <iostream>

using namespace std;

typedef long long ll;

#define inf 4000000000000000000ll

int main() {
    int T;
    cin >> T;
    for(int it=1;it<=T;it++) {
        ll r, t;
        cin >> r >> t;
        ll lo = 1ll, hi = 2000000000ll;
        while(lo < hi) {
            ll mid = (lo+hi+1)/2;
            ll p = (r + mid)*2 - 1;
            if(mid <= t/p) lo = mid;
            else hi = mid-1;
        }
        cout << "Case #" << it << ": " << lo << endl;
    }
    return 0;
}

