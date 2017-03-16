#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 2e9
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <long long> vll;


string s;

bool if2(ll x) {
    while (x % 2 == 0) {
        x /= 2;
    }
    return x == 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    forn (it, tests) {
        printf("Case #%d: ", it + 1);
        cin >> s;
        int i = 0;
        ll p = 0, q = 0;
        while (s[i] != '/') {
            p = p * 10 + (s[i] - '0');
            i++;
        }
        i++;
        while (i < s.size()) {
            q = q * 10 + (s[i] - '0');
            i++;
        }
        if (p == 0) {
            cout << "impossible" << endl;
            continue;
        }
        ll g = __gcd(p, q);
        p /= g;
        q /= g;
        if (!if2(q)) {
            cout << "impossible" << endl;
            continue;
        }

        int ans = 1;
        while (2 * p < q) {
            p *= 2;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
