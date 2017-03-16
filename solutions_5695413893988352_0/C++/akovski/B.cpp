/*{{{*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second
#define bitcnt __builtin_popcount
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
inline int ri() {int x; scanf("%d", &x); return x;}
#define rep2(i, n, ...) for (int i = 0; i < (n); i ++) 
#define rep3(i, a, b, ...) for (int i = (a); i < (b); i ++)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
template<typename T>inline bool smax(T&a, T b){if(a<b){a=b;return true;}return false;} 
template<typename T>inline bool smin(T&a, T b){if(a>b){a=b;return true;}return false;} 
/*}}}*/

string str(int x, int n) {
    string s = "";
    rep(i, n) {
        s += '0' + x % 10;
        x /= 10;
    }
    reverse(all(s));
    return s;
}
bool match(string a, string b) {
    for (int i = 0; i < a.length(); i ++) if (a[i] != b[i] && b[i] != '?') return false;
    return true;
}

void solve() {
    string a, b; cin >> a >> b;
    int n = a.length();
    int same = 1;
    rep(i, n) if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) same = 0;
    if (same) {
        rep(i, n){
            if (a[i] != '?') b[i] = a[i];
            else if (b[i] != '?') a[i] = b[i];
            else a[i] = b[i] = '0';
        }
        cout << a << ' ' << b << endl;
        return;
    }

    pair<string, string> p;
    for (int l = 0; l < n; l ++) {
        rep(i, 10) if (a[l] == '?' || i == a[l] - '0')
            rep(j, 10) if (b[l] == '?' || j == b[l] - '0') {
                string sa = a, sb = b;
                int ok = 1;
                if (i <= j) {
                    rep(k, l) {
                        if (sa[k] != '?' && sb[k] != '?' && sa[k] != sb[k]) {
                            ok = 0; break;
                        } else if (sa[k] != '?') sb[k] = sa[k];
                        else if (sb[k] != '?') sa[k] = sb[k];
                        else sa[k] = sb[k] = '0';
                    }
                    sa[l] = '0' + i;
                    sb[l] = '0' + j;
                    rep(k, l + 1, n) if (sa[k] == '?') sa[k] = '9';
                    rep(k, l + 1, n) if (sb[k] == '?') sb[k] = '0';
                } else ok = 0;            
                if (ok) {
                    if (p.fr == "") p = make_pair(sa, sb);
                    else if (abs(stol(sa) - stol(sb)) < abs(stol(p.fr) - stol(p.sc))) {
                        p = make_pair(sa, sb);
                    } else if (abs(stol(sa) - stol(sb)) == abs(stol(p.fr) - stol(p.sc)) && sb < p.sc) {
                        p = make_pair(sa, sb);
                    } else if (abs(stol(sa) - stol(sb)) == abs(stol(p.fr) - stol(p.sc)) && sb == p.sc && sa < p.fr) {
                        p = make_pair(sa, sb);
                    }
                }
            }
    }
    for (int l = 0; l < n; l ++) {
        rep(i, 10) if (a[l] == '?' || i == a[l] - '0')
            rep(j, 10) if (b[l] == '?' || j == b[l] - '0') {
                string sa = a, sb = b;
                int ok = 1;
                if (i >= j) {
                    rep(k, l) {
                        if (sa[k] != '?' && sb[k] != '?' && sa[k] != sb[k]) {
                            ok = 0; break;
                        } else if (sa[k] != '?') sb[k] = sa[k];
                        else if (sb[k] != '?') sa[k] = sb[k];
                        else sa[k] = sb[k] = '0';
                    }
                    sa[l] = '0' + i;
                    sb[l] = '0' + j;
                    rep(k, l + 1, n) if (sa[k] == '?') sa[k] = '0';
                    rep(k, l + 1, n) if (sb[k] == '?') sb[k] = '9';
                } else ok = 0;
                if (ok) {
                    if (p.fr == "") p = make_pair(sa, sb);
                    else if (abs(stol(sa) - stol(sb)) < abs(stol(p.fr) - stol(p.sc))) {
                        p = make_pair(sa, sb);
                    } else if (abs(stol(sa) - stol(sb)) == abs(stol(p.fr) - stol(p.sc)) && sb < p.sc) {
                        p = make_pair(sa, sb);
                    } else if (abs(stol(sa) - stol(sb)) == abs(stol(p.fr) - stol(p.sc)) && sb == p.sc && sa < p.fr) {
                        p = make_pair(sa, sb);
                    }
                }
            }
    }

    for (int i = 0; i < 1000; i ++) if (match(str(i, n), b))
        for (int j = 0; j < 1000; j ++) if (match(str(j, n), a)) {
            if (abs(stol(str(i, n)) - stol(str(j, n))) < abs(stol(p.fr) - stol(p.sc))) {
                cout << str(j, n) << " " << str(i, n) << endl;
                cout << p.fr << " " << p.sc << endl;
                cout << a << ' ' << b << endl;
                exit(0);
            }
        }

    cout << p.fr << ' ' << p.sc << endl;
}

int main() {
    #ifdef _TEST_
    freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    #endif
    int Q; cin >> Q;
    rep(i, Q) {
        cout << "Case " << "#" << i + 1 << ": ";
        solve();
    }
    return 0;
}
