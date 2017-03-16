#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int f(int x) {
    return (x + 1) / 2;
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        int x,r,c;
        cin >> x >> r >> c;
        if (r > c) swap(r, c);
        if (x >= 7 || (r*c) % x || x > max(r, c) || f(x) > min(r, c) || (f(x) == r && x > 3 && x % f(x) == 0)) {
            printf("RICHARD\n");
        } else {
            printf("GABRIEL\n");
//            if (x > 3) cerr << x << ' ' << r << ' ' << c << endl;
        }
    }
    return 0;
}
