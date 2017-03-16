#include <iostream>
#include <vector>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

inline long long f(long long r, long long x) {
    return 2LL * r * x + x * (2LL * x - 1);
}

void solve() {
    long long r,t;
    cin >> r >> t;

    long long low = 0, high = 1;
    while(f(r,high) <= t) {
        high *= 2;
    }
    while(low + 1 < high) {
        long long mid = (low + high) / 2;
        if (f(r,mid) <= t) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << low << endl;
}

int main() {
    int T;
    cin >> T;
    rep(i,T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
