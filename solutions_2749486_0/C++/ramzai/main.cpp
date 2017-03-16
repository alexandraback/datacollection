#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <memory>
#include <cassert>
#include <climits>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define FORD(i, a, b) for(int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) for (int (i) = 0; (i) < n; (i)++)
#define SIZE(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()

typedef long long LL;
typedef vector<pair<int, int> > vpii;

#define DBG(x) cout << #x << " = " << x << endl
// #define DBG(x) ;
template<typename T>
void dbg_vector(const vector<T>& v, const string& name) {
    cout << name << " = ";
    REP(i, SIZE(v)) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

string doit2(int x, int y) {
    string res;
    REP(i, abs(x)) {
        if (x > 0) {
            res += "WE";
        } else {
            res += "EW";
        }
    }
    REP(i, abs(y)) {
        if (y > 0) {
            res += "SN";
        } else {
            res += "NS";
        }
    }
    return res;
}

int main() {
    int tests;
    cin >> tests;
    REP(zzz, tests) {
        int x, y;
        cin >> x >> y;
        string res = doit2(x, y);
        cout << "Case #" << zzz + 1 << ": " << res << endl;
        // LL res2 = doit2(name, n);
        // cout << "Case #" << zzz + 1 << ": " << res << ' ' << res2 << endl;
    }

    return 0;
}
