#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

struct Prime {
    static const int N = 1000001;
    int pr[N + 1], is[N + 1], n;
    Prime() {
        int i, j, d;
        memset(is, 0, sizeof(is)), n = 0;
        for (i = 3, is[2] = 1; i <= N; i += 2) is[i] = 1;
        for (i = 3; i * i <= N; i += 2) if (is[i]) for (j = i * i, d = i << 1; j <= N; j += d) is[j] = 0;
        for (i = 2; i <= N; i++) if (is[i]) pr[n++] = i;
    }
    int size() { return n; }
    bool operator()(int k) { return is[k]; }
    int operator[](int k) { return pr[k]; }
};

template<class T> inline T mod_pow(T x, T n, T mod) {
    if (x >= mod) x %= mod;
    T res = 1;
    for (; n; x = x * x % mod, n >>= 1) if (n & 1) res = res * x % mod;
    return res;
}

ll power(ll x, ll p) {
    if (p == 0) return 1;
    return x * power(x, p - 1);
}

mt19937 mt;
Prime pr;

int main () {
    int i;
    int n = 16;
    int j = 50;

    uniform_int_distribution<int> rnd(0, 1);
    set<string> found;

    vector<string> res;
    vector<vector<int>> divisors;

    for (; ; ) {
        string str(n, '0');
        for (auto& c: str) c = rnd(mt) + '0';
        str[0] = '1';
        str.back() = '1';
        if (found.count(str)) continue;

        int all_ok = 1;
        vector<int> divs(11);
        for (int base = 2; base <= 10; ++base) {
            int ok = 0;
            for (int p = 0; p < 20; ++p) {
                int prime = pr[p];
                int value = 0;
                for (int k = 0; k < n; ++k) {
                    if (str[k] == '1') {
                        value += mod_pow(base, n - k - 1, prime);
                        value %= prime;
                    }
                }
                if (value == 0) {
                    ok = 1;
                    divs[base] = prime;
                    break;
                }
            }
            if (ok == 0) {
                all_ok = 0;
                break;
            }
        }
        if (all_ok) {
            found.insert(str);
            res.push_back(str);
            divisors.push_back(divs);
        }
        if (found.size() == j) break;
    }


    puts("Case #1:");
    for (int k = 0; k < j; ++k) {
        cout << res[k];
        for (int base = 2; base <= 10; ++base) {
            cout << " " << divisors[k][base];
        }
        puts("");
    }



    /*
    for (int k = 0; k < j; ++k) {
        cout << res[k] << endl;
        for (auto d: divisors[k]) cout << d << " "; puts("");
        for (int base = 2; base < 10; ++base) {
            ll value = 0;
            for (i = 0; i < res[k].size(); ++i) {
                if (res[k][i] == '1') {
                    value += power(base, i);
                }
            }
            cout << "base = " << base << " value = " << value << " modulo " << value % divisors[k][base] << endl;
        }
    }
    */

    return 0;
}
