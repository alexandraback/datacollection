/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

const int max_n = 10000 + 10;

const int table[4][4] = {
    {0, 1, 2, 3},
    {1, ~0, 3, ~2},
    {2, ~3, ~0, 1},
    {3, 2, ~1, ~0}
};

int t, n;
LL m;
char str[max_n];

int multiply(int x, int y) {
    int s = 0;
    if (x < 0) {
        x = ~x;
        s ^= 1;
    }
    if (y < 0) {
        y = ~y;
        s ^= 1;
    }
    int res = table[x][y];
    return s == 0 ? res : ~res;
}

int divide_l(int z, int x) {
    for (int y = 0; y < 4; ++y) {
        if (multiply(x, y) == z)
            return y;
        if (multiply(x, ~y) == z)
            return ~y;
    }
    while (true);
}

int divide_r(int z, int y) {
    for (int x = 0; x < 4; ++x) {
        if (multiply(x, y) == z)
            return x;
        if (multiply(~x, y) == z)
            return ~x;
    }
    while (true);
}

bool check(int x, int y, int z) {
    return x == 1 && y == 2 && z == 3;
}

bool can_find() {
    int val[4] = {};
    for (int i = 0; i < n; ++i)
        val[1] = multiply(val[1], str[i]);
    val[2] = multiply(val[1], val[1]);
    val[3] = multiply(val[2], val[1]);

    for (int i_l = 0; i_l < 4; ++i_l) {
        for (int i_m = 0; i_m < 4; ++i_m) {
            for (int i_r = 0; i_r < 4; ++i_r) {
                if (i_l + i_m + i_r > m || (i_l + i_m + i_r) % 4 != m % 4)
                    continue;
                if (check(val[i_l], val[i_m], val[i_r]))
                    return true;
            }
        }
    }

    set<vector<int> > s;
    s.insert(vector<int>(1, str[0]));
    for (int i = 1; i < n; ++i) {
        set<vector<int> > ns;
        for (set<vector<int> >::iterator j = s.begin(); j != s.end(); ++j) {
            vector<int> cur = *j;
            if (cur.size() < 3) {
                cur.push_back(str[i]);
                ns.insert(cur);
                cur.pop_back();
            }
            cur.back() = multiply(cur.back(), str[i]);
            ns.insert(cur);
        }
        s = ns;
    }

    for (int i_l = 0; i_l < 4; ++i_l) {
        for (int i_m = 0; i_m < 4; ++i_m) {
            for (int i_r = 0; i_r < 4; ++i_r) {
                if (i_l + i_m + i_r + 1 > m || (i_l + i_m + i_r + 1) % 4 != m % 4)
                    continue;
                if (i_m == 0) {
                    int v_l = divide_l(1, val[i_l]), v_r = divide_r(3, val[i_r]);
                    vector<int> v;
                    v.push_back(v_l);
                    v.push_back(2);
                    v.push_back(v_r);
                    if (s.find(v) != s.end())
                        return true;
                }
                if (val[i_l] == 1) {
                    vector<int> v;
                    v.push_back(divide_l(2, val[i_m]));
                    v.push_back(divide_r(3, val[i_r]));
                    if (s.find(v) != s.end())
                        return true;
                }
                if (val[i_r] == 3) {
                    vector<int> v;
                    v.push_back(divide_l(1, val[i_l]));
                    v.push_back(divide_r(2, val[i_m]));
                    if (s.find(v) != s.end())
                        return true;
                }
            }
        }
    }
    for (int i_l = 0; i_l < 4; ++i_l) {
        for (int i_m = 0; i_m < 4; ++i_m) {
            for (int i_r = 0; i_r < 4; ++i_r) {
                if (i_l + i_m + i_r + 2 > m || (i_l + i_m + i_r + 2) % 4 != m % 4)
                    continue;
                int v_l = divide_l(1, val[i_l]), v_r = divide_r(3, val[i_r]);
                for (int k = 0; k < 4; ++k) {
                    for (int f = 0; f < 2; ++f) {
                        int v_ml = (f == 0 ? k : ~k);
                        int v_mr = divide_l(divide_l(2, v_ml), val[i_m]);
                        vector<int> v1, v2;
                        v1.push_back(v_l);
                        v1.push_back(v_ml);
                        v2.push_back(v_mr);
                        v2.push_back(v_r);
                        if (s.find(v1) != s.end() && s.find(v2) != s.end())
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    scanf("%s", str);
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'i')
            str[i] = 1;
        else if (str[i] == 'j')
            str[i] = 2;
        else if (str[i] == 'k')
            str[i] = 3;
    }
    printf("Case #%d: %s\n", ++t, can_find() ? "YES" : "NO");
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
