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
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        ll p,q;
        scanf("%lld/%lld",&p,&q);
//        cerr << p << ' ' << q << endl;
        ll d = __gcd(p,q);
        p /= d;
        q /= d;
        int k = 0;
        while (q % 2 == 0) {
            q /= 2;
            ++k;
        }
        if (q != 1 || k > 40) {
            printf("impossible\n");
            continue;
        }
        while (p > 1) {
            p /= 2;
            --k;
        }
        printf("%d\n", k);
    }
    return 0;
}
