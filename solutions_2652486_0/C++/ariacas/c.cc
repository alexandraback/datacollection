#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int r,n,m,k;
void f1(vl v) {
    sort(v.begin(), v.end());
    vi ma(m + 1);
    for (int i = 2; i <= m; ++i) {
        for (int j = 0; j < v.size(); ++j) {
            ll temp = v[j];
            int cur = 0;
            while (temp % i == 0) {
                temp /= i;
                ++cur;
            }
            ma[i] = max(ma[i], cur);
        }
    }
    string res = "";
    int rem = 3;
    for (int i = 0; i < ma[3]; ++i) {
        res += "3";
        --rem;
    }
    for (int i = 0; i < ma[5]; ++i) {
        res += "5";
        --rem;
    }
    if (rem == 1) {
        if (ma[2] == 1)
            res += "2";
        else res += "4";
    }
    if (rem == 2) {
        if (ma[2] <= 1)
            res += "22";
        else if (rem == 3) res += "24";
        else res += "44";
    }
    if (rem == 3) {
        if (ma[2] <= 2)
            res += "222";
        else if (rem == 3) res += "222";
        else res += "224";
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cin >> r >> n >> m >> k;
        vvl v(r, vl(k));
        printf("Case #%d:\n", test);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < k; ++j)
                cin >> v[i][j];
            if (m == 5)
                f1(v[i]);
        }
    }
    return 0;
}
