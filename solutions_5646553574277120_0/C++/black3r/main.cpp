#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool testem(ll upto, vector<ll> coins) {
    vector<bool> good(upto+47);
    for (ll i = 0; i < (1<<(coins.size())); i++) {
        ll number = 0;
        for (ll j = 0; j < coins.size(); j++) {
            if (i & (1<<j)) {
                number += coins[j];
            }
        }
        if (number < upto+47) {
            good[number] = true;
        }
    }
    for (ll i = 1; i <= upto; i++) {
        if (!good[i]) {
            return false;
        }
    }
    return true;
}

bool contains(vector<ll> v, ll w) {
    for (ll t : v) if (t == w) return true;
    return false;
}

int try_solve(vector<ll> inputs, ll v) {
    ll c = inputs.size();
    if (testem(v, inputs)) return 0;
    //try one
    inputs.push_back(0);
    for (int i = 1; i <= v; i++) {
        if (!contains(inputs, i)) {
            inputs[c] = i;
            if (testem(v, inputs)) return 1;
        }
    }
    // try two
    inputs.push_back(0);
    for (int i = 1; i <= v; i++) {
        if (contains(inputs, i)) continue;
        inputs[c] = i;
        for (int j = i+1; j <= v; j++) {
            if (contains(inputs, j)) continue;
            inputs[c+1] = j;
            if (testem(v, inputs)) return 2;
        }
    }
    inputs.push_back(0);
    // try three
    for (int i = 1; i <= v; i++) {
        if (contains(inputs, i)) continue;
        inputs[c] = i;
        for (int j = i+1; j <= v; j++) {
            if (contains(inputs, j)) continue;
            inputs[c+1] = j;
            for (int k = j+1; k <= v; k++) {
                if (contains(inputs, k)) continue;
                inputs[c+2] = k;
                if (testem(v, inputs)) return 3;
            }
        }
    }
    inputs.push_back(0);
    for (int i = 1; i <= v; i++) {
        if (contains(inputs, i)) continue;
        inputs[c] = i;
        for (int j = i+1; j <= v; j++) {
            if (contains(inputs, j)) continue;
            inputs[c+1] = j;
            for (int k = j+1; k <= v; k++) {
                if (contains(inputs, k)) continue;
                inputs[c+2] = k;
                for (int l = k+1; l <= v; l++) {
                    if (contains(inputs, l)) continue;
                    inputs[c+3] = l;
                    if (testem(v, inputs)) return 4;
                }
            }
        }
    }
    inputs.push_back(0);
    for (int i = 1; i <= v; i++) {
        if (contains(inputs, i)) continue;
        inputs[c] = i;
        for (int j = i+1; j <= v; j++) {
            if (contains(inputs, j)) continue;
            inputs[c+1] = j;
            for (int k = j+1; k <= v; k++) {
                if (contains(inputs, k)) continue;
                inputs[c+2] = k;
                for (int l = k+1; l <= v; l++) {
                    if (contains(inputs, l)) continue;
                    inputs[c+3] = l;
                    for (int m = l+1; m <= v; m++) {
                        if (contains(inputs, m)) continue;
                        inputs[c+4] = m;
                        if (testem(v, inputs)) return 5;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    ll T; cin >> T;
    for (ll I = 1; I <= T; I++) {
        ll c, d, v; cin >> c >> d >> v;
        vector<ll> inputs(d);
        for (ll &x : inputs) cin >> x;
        // test without additionals:
        ll result = try_solve(inputs, v);
        cout << "Case #" << I << ": " << result << endl;
    }
    return 0;
}

