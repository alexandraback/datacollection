#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull rand64() {
    return (ull(rand()) << 48) |
           (ull(rand()) << 32) |
           (ull(rand()) << 16) |
           (ull(rand()));
}

ll rand(ll L, ll R) {
    return rand64() % (R - L + 1) + L;
}

ll mypow(ll x, ll n) {
    ll prod = 1;
    while (n--) {
        prod *= x;
    }
    return prod;
}

void solve(int tc) {
    cout << "Case #" << tc << ":";
    ll K, C, S;
    cin >> K >> C >> S;
    if (S * C < K) {
        cout << " IMPOSSIBLE" << endl;
        return;
    }
    vector<ll> res(S);
    for (int i = 0; i < K; i++) {
        res[i / C] += mypow(K, i % C) * i;
    }
    set<ll> res2(res.begin(), res.end());
    for (ll x : res2) {
        cout << " " << x + 1;
    }
    cout << endl;
}

int main() {
    srand(time(0));
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
        
    
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
}
