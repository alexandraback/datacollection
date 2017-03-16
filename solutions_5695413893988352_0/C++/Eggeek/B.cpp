#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
typedef long long llong;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const llong INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/

void fill_same(string& c, string& j, int l, int r) {
    for (int i=l; i<r; i++) {
        if (c[i] == '?' && j[i] != '?') c[i] = j[i];
        else if (c[i] != '?' && j[i] == '?') j[i] = c[i];
        else if (c[i] == j[i] && c[i] == '?') {
            c[i] = '0'; j[i] = '0';
        }
    }
}

void fill_str(string& s, int l, int r, int num) {
    for (int i=l; i<r; i++) if (s[i] == '?') s[i] = num + '0';
}

llong get_var(string s) {
    llong res = 0;
    for (int i=0; i<s.length(); i++) res = res * 10 + s[i]-'0';
    return res;
}

pair<string, string> better(pair<string, string> a, pair<string, string> b) {
    if (a.first == "-1") return b;
    if (b.first == "-1") return a;
    llong vac = get_var(a.first);
    llong vaj = get_var(a.second);
    llong vbc = get_var(b.first);
    llong vbj = get_var(b.second);
    if (abs(vac - vaj) < abs(vbc - vbj)) return a;
    else if (abs(vac - vaj) > abs(vbc - vbj)) return b;
    else {
        if (vac > vbc) return b;
        else if (vac < vbc) return a;
        else if (vaj > vbj) return b;
        else return a;
    }
}

pair<string, string> solve(string c, string j) {
    pair<string, string> res = make_pair("-1", "-1");
    string tc, tj;
    int n = (int)c.length();
    tc = c, tj = j;
    fill_same(tc, tj, 0, n);
    res = make_pair(tc, tj);
    // c > j
    for (int i=0; i<n; i++) {
        tc = c, tj = j;
        if (c[i] != '?' && j[i] != '?') {
            if (c[i] > j[i]) {
                fill_same(tc, tj, 0, i);
                fill_str(tc, i+1, n, 0);
                fill_str(tj, i+1, n, 9);
                res = better(res, make_pair(tc, tj));
            }
        } else {
            int x = i;
            if (c[x] == '?' && (j[x] != '9' && j[x] != '?')) {
                tc[x] = tj[x] + 1;
            } else if ((c[x] != '?' && c[x] != '0') && j[x] == '?') {
                tj[x] = tc[x] - 1;
            } else if (c[x] == '?' && j[x] == '?') {
                tc[x] = '1'; tj[x] = '0';
            }
            fill_same(tc, tj, 0, x+1);
            fill_str(tc, x+1, n, 0);
            fill_str(tj, x+1, n, 9);
            res = better(res, make_pair(tc, tj));
        }
    }

    // c < j
    for (int i=0; i<n; i++) {
        tc = c, tj = j;
        if (c[i] != '?' && j[i] != '?') {
            if (c[i] < j[i]) {
                fill_same(tc, tj, 0, i);
                fill_str(tc, i+1, n, 9);
                fill_str(tj, i+1, n, 0);
                res = better(res, make_pair(tc, tj));
            }
        } else {
            int x = i;
            if (c[x] == '?' && (j[x] != '0' && j[x] != '?')) {
                tc[x] = tj[x] - 1;
            } else if (j[x] == '?' && (c[x] != '9' && c[x] != '?')) {
                tj[x] = tc[x] + 1;
            } else if (j[x] == '?' && c[x] == '?') {
                tj[x] = '1', tc[x] = '0';
            }
            fill_same(tc, tj, 0, x+1);
            fill_str(tc, x+1, n, 9);
            fill_str(tj, x+1, n, 0);
            res = better(res, make_pair(tc, tj));
        }
    }

    return res;
}

void  dfs(int id, string c, string j, pair<string, string>& res) {
    if (id == c.length()) {
        if (res.first == "-1") {
            res = make_pair(c, j);
            return;
        }
        llong abs0 =  abs(get_var(c) - get_var(j));
        llong abs1 = abs(get_var(res.first) - get_var(res.second));
        if (abs0 < abs1) {
            res = make_pair(c, j);
        } else if (abs0 == abs1 && get_var(c) < get_var(res.first)) {
            res = make_pair(c, j);
        } else if (abs0 == abs1 && get_var(c) == get_var(res.first) &&
                get_var(j) < get_var(res.second)) {
            res = make_pair(c, j);
        }
        return;
    }
    if (c[id] == '?' && j[id] == '?') {
        for (int x=0; x<=9; x++)
            for (int y=0; y<=9; y++) {
                c[id] = x + '0';
                j[id] = y + '0';
                dfs(id+1, c, j, res);
            }
    } else {
        if (c[id] == '?') {
            for (int x=0; x<=9; x++) {
                c[id] = x + '0';
                dfs(id+1, c, j, res);
            }
        } else if (j[id] == '?') {
            for (int y=0; y<=9; y++) {
                j[id] = y + '0';
                dfs(id+1, c, j, res);
            }
        }
        else dfs(id+1, c, j, res);
    }
}

pair<string, string> bf(string c, string j) {
    pair<string, string> res = make_pair("-1", "-1");
    dfs(0, c, j, res);
    return res;
}

int main() {
    //freopen("test.in", "r", stdin);
    int cases;
    cin >> cases;
    for (int cas=1; cas<=cases; cas++) {
        string c, j;
        cin >> c >> j;
        pair<string, string> ans = solve(c, j);
        //pair<string, string> ansb = bf(c, j);
        printf("Case #%d: %s %s\n", cas, ans.first.c_str(), ans.second.c_str());
        //printf("Case #%d: %s %s\n", cas, ansb.first.c_str(), ansb.second.c_str());
        /*
        if (ans != ansb) {
            printf("Case:%d c:%s j:%s\n", cas, c.c_str(), j.c_str());
            break;
        }
        assert(ans == ansb);*/
    }
    return 0;
}
