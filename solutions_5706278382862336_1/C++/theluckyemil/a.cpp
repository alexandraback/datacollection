#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>

#define ll long long
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int maxn = 205;
const int md = 1e9+7;

ll gcd(ll a, ll b) {
    while (b) {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test; cin >> test;
    for (int it=0; it<test; it++) {
        char c;
        ll p, q; cin >> p >> c >> q;
        ll g = gcd(p, q);
        p/=g, q/=g;
        ll tmp=1;
        int ok=0;
        for (int iter=0; iter<60; iter++) {
            tmp*=2;
            if (tmp==q) {
                ok=1;
                break;
            }
        }
        if (!ok) {
            printf("Case #%d: impossible\n", it+1);
        } else {
            int ans = 0;
            while (2 * p < q) {
                q /= 2;
                ans++;
            }
            printf("Case #%d: %d\n", it+1, ans+1);
        }
    }
    return 0;
}
