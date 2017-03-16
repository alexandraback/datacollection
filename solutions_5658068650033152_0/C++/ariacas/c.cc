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

int c2(int x) {
    return x*(x+1)/2;
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        int n,m,k;
        cin >> n >> m >> k;
        if (n > m) swap(n, m);
        if (k <= 4 || n == 1) {cout << k << endl; continue;}
        int res = min(k, 2*(n+m-2));
        for (int a = 2; a <= n; ++a) for (int b = 2; b <= m; ++b) {
            if (a*b < k) continue;
            for (int l1 = 0; l1 < min(a,b); ++l1) for (int l2 = 0; l2 < min(a,b-l1); ++l2) {
                int rem = c2(l1) + c2(l2);
                if (a*b-rem < k) continue;
                for (int l3 = 0; l3 < min(a-l2,b); ++l3) for (int l4 = 0; l4 < min(a-l1,b-l3); ++l4) {
                    if (a*b - rem - c2(l3) - c2(l4) >= k) {
                        int cand = 2*(a+b)-4-l1-l2-l3-l4;
                        if (res > cand) {
//                            cerr << a << ' ' << b << ' ' << l1 <<' ' << l2 << ' ' << l3 << ' ' << l4 << endl;
                            res = cand;
                        }
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
