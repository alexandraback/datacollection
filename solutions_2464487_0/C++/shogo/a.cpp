#include <iostream>
#include <cmath>
using namespace std;

long long int S(long long int r, long long int n) {
    return n * (2*r + 2*n - 1);
}

int main(void) {
    int T;
    cin >> T;
    for(int no = 1; no <= T; no++) {
        long long int r, t;
        cin >> r >> t;
        long long int ans = 0;
        for(int i = 30; i >= 0; --i) {
            int v = 1 << i;
            if(S(r, ans+v) <= t) ans += v;
        }
        cout << "Case #" << no << ": " << ans << endl;
    }
}
