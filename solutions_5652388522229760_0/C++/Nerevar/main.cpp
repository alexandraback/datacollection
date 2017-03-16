#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>

typedef long long ll;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())

using namespace std;

void solveCase(int tc) {
    printf("Case #%d: ", tc);
    cerr << tc << endl;
    ll n;
    set<int> d;
    cin >> n;
    if (n == 0) {
        cout << "INSOMNIA\n";
        return;
    }
    ll add = n;
    while (true) {
        ll t = n;
        while (t) {
            d.insert(t % 10);
            t /= 10;
        }
        if (d.size() == 10) {
            cout << n << endl;
            return;
        }
        n += add;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc; cin >> tc;
    forn(it, tc) solveCase(it + 1);
    return 0;
}
