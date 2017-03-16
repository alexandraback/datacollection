#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

string binary(ll x) {
    string out = "";
    while (x > 0) {
        out += char(x % 2 + '0');
        x /= 2;
    }
    reverse(out.begin(), out.end());
    return out;
}

ll convert(ll x, ll base) {
    ll result = 0;
    string t = binary(x);
    for (int i = 0; i < t.size(); ++i) {
        result = result * base + (int)(t[i] - '0');
    }
    return result;
}

ll getDiv(ll x) {
    for (ll i = 3, cnt = 0; i <= x; ++i, ++cnt) {
        if (cnt == 1000) return x;
        if (x % i == 0)
            return i;
    }
    return x;
}

void Solve() {
    int n, j;
    scanf("%d %d", &n, &j);
    cout << endl;
    ll current;
    vector<int> result;
    for (current = 0; ; ++current) {
        if (result.size() == j) break;
        ll number = (1LL << (n - 2)) + current;
        number *= 2;
        ++number;
        vector<ll> divs;
        bool ok = true;
        for (int i = 2; i <= 10; ++i) {
            ll curDiv = getDiv(convert(number, i));
            if (curDiv == convert(number, i)) {
                ok = false;
                break;
            }
            divs.push_back(curDiv);
        }
        if (ok) {
            result.push_back(number);
        }
    }
    for (int i = 0; i < result.size(); ++i) {
        cout << binary(result[i]) << " ";
        for (int j = 2; j <= 10; ++j) {
            cout << getDiv(convert(result[i], j)) << (j == 10 ? "\n" : " ");
        }
    }
}

int main() {
    int z; scanf("%d", &z);
    for (int i = 0; i < z; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
