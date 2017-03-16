#include <cstdio>
#include <cassert>
#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <queue>
#include <utility>
#include <sstream>

using namespace std;

typedef long long ll;

ll A, B, K;

string to_s(ll n) {
    ostringstream os;
    os << n;
    return os.str();
}

string solve() {
    ll ans = 0;
    for (ll a = 0; a < A; a++) {
        for (ll b = 0; b < B; b++) {
            if ((a & b) < K) {
                ans++;
            }
        }
    }
    return to_s(ans);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> A >> B >> K;
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
