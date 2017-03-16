#include <iostream>
#include <cstdio>
#include <algorithm>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long i64;

i64 a[100500];
i64 S;
int n;

int solve() {
    sort(a, a + n);
    int ans = n;
    int z = 0;
    if(S > 1) {
        forn(i, n) {
            if( S > a[i] ) {
                S += a[i];
            } else {
                ans = min(ans, z + n - i);
                while( S <= a[i] ) {
                    z += 1;
                    S += S - 1;
                }
                S += a[i];
            }
        }
        ans = min(ans, z);
    }
    return ans;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    forn(_t, T) {
        cin >> S >> n;
        forn(i, n) cin >> a[i];
        cout << "Case #" << _t + 1 << ": " << solve() << '\n';
    }
    return 0;
}
