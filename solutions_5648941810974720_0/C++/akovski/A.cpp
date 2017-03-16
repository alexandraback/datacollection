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


vector<string> w = {"ZERO", "TWO", "EIGHT", "THREE", "FOUR", "FIVE", "SEVEN", "SIX", "ONE", "NINE"};
vector<int> d = {0, 2, 8, 3, 4, 5, 7, 6, 1, 9};
void solve() {
    string s; cin >> s;
    map<char, int> cnt;
    for (auto c : s) cnt[c] ++;
    vector<int> res;
    rep(i, 10) {
        while (true) {
            int ok = 1;
            for (char c : w[i]) if (!cnt.count(c) || cnt[c] == 0) ok = 0; 
            if (ok) {
                for (char c : w[i]) cnt[c] --;
                res.pb(d[i]);
            }
            else break;
        }
    }
    sort(all(res));
    for (int i : res) cout << i;
    cout << endl;
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
