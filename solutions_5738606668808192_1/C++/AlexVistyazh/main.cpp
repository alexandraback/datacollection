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

vector<ll> listOfPrimes;

bool isPrime(ll x) {
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void calcListOfPrimes() {
    for (int i = 2; i <= 10000; i++) {
        if (isPrime(i)) listOfPrimes.push_back(i);
    }
}

ll getMod(string s, ll base, ll p) {
    ll res = 0;
    for (char c : s) {
        res = (res * base + c - '0') % p;
    }
    return res;
}

bool isLegitimate(ll x, pair<string, vector<ll>> & res) {
    string & s = res.first;
    while (x > 0) {
        s.push_back('0' + (x % 2));
        x /= 2;
    }
    reverse(s.begin(), s.end());
    vector<ll> & divisors = res.second;
    divisors.resize(9);
    for (int base = 2; base <= 10; base++) {
        bool fnd = false;
        for (ll p : listOfPrimes) {
            if (getMod(s, base, p) == 0) {
                divisors[base - 2] = p;
                fnd = true;
                break;
            }
        }
        if (!fnd) return false;
    }
    return true;
}

void solve(int tc) {
    cout << "Case #" << tc << ":" << endl;
    int N, J;
    cin >> N >> J;
    set<ll> s;
    vector<pair<string, vector<ll>>> res;
    while ((int)res.size() < J) {
        ll x = (1LL << (N - 1)) | rand(0, (1LL << (N - 2)) - 1) | 1;
        if (s.count(x)) continue;
        pair<string, vector<ll>> cur;
        if (isLegitimate(x, cur)) res.push_back(cur);
        s.insert(x);
    }
    for (auto x : res) {
        cout << x.first;
        for (ll z : x.second) {
            cout << " " << z;
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    calcListOfPrimes();
    
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
}
