#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
vector <ll> pl;

int cs[1000], ncs;

bool isPalin(ll x) {
    ncs = 0;
    while (x) {
        cs[++ncs] = x % 10;
        x /= 10;
    }

    for (int i = 1; i <= ncs; i++)
        if (cs[i] != cs[ncs + 1 - i]) return false;

    return true;
}

ll make_1(int x) {
   ncs = 0;
    while (x) {
        cs[++ncs] = x % 10;
        x /= 10;
    }

    ll s = 0;
    for (int i = ncs; i >= 1; i--)
        s = s * 10 + cs[i];
    for (int i = 2; i <= ncs; i++)
        s = s * 10 + cs[i];

    return s;
}

ll make_2(int x) {
   ncs = 0;
    while (x) {
        cs[++ncs] = x % 10;
        x /= 10;
    }

    ll s = 0;
    for (int i = ncs; i >= 1; i--)
        s = s * 10 + cs[i];
    for (int i = 1; i <= ncs; i++)
        s = s * 10 + cs[i];

    return s;
}

void init() {
    for (int i = 1; i <= 9999; i++) {
        ll x = make_1(i);
        if (isPalin(x * x)) pl.push_back(x*x);

        x = make_2(i);
        if (isPalin(x * x)) pl.push_back(x*x);
    }

    sort(pl.begin(), pl.end());
}

int main() {
    freopen("C-large-1.in", "r", stdin);
    freopen("c.out", "w", stdout);

    init();

    int ntest;
    cin >> ntest;
    for (int test = 1; test <= ntest; test++) {
        cout << "Case #" << test << ": ";

        ll L, R;
        cin >> L >> R;
        int res = 0;
        for (int i = 0; i < pl.size(); i++)
                if (L <= pl[i] && pl[i] <= R) res++;
        cout << res << endl;
    }

}
