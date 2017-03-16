#include <algorithm>
#include <assert.h>
#include <chrono>
#include <functional>
#include <numeric>
#include <math.h>
#include <memory.h>
#include <stdint.h>
#include <time.h>
#include <utility>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>

#include <bitset>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define countbits __builtin_popcountll
#define print(a)            cerr << (a) << '\n'
#define dbg(a)              cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)          cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c)       cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'
#define dbg4(a, b, c, d)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << '\n'
#define dbg5(a, b, c, d, e) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << " " << #e << " = " << (e) << '\n'
#define PI 3.1415926535897932384626433

using std::cerr;
using std::cin;
using std::cout;

using std::bitset;
using std::deque;
using std::map;
using std::pair;
using std::queue;
using std::set;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;

using std::abs;
using std::max;
using std::min;

using std::sort;
using std::swap;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;

void init() {
    #ifndef LOCAL
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    std::iostream::sync_with_stdio(0);
    cout << std::fixed << std::setprecision(10);
    cerr << std::fixed << std::setprecision(10);
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}
int n;
ll stl(string s) {
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res *= 10;
        res += ll(s[i] - '0');
    }
    return res;
}
pair<string, string> solve(string a, string b) {
    ll ans = 1e18 + 118;
    string ansx, ansy; 
    ll ansone, anstwo;
    string x = a, y = a;
    for (int start = 0; start <= n; ++start) {
        for (int i = 0; i < start; ++i) {
            x[i] = (a[i] == '?' ? (b[i] == '?' ? '0' : b[i]) : a[i]);
            y[i] = (b[i] == '?' ? (a[i] == '?' ? '0' : a[i]) : b[i]);
        }
        if (start < n) {
            if (a[start] == '?' && b[start] == '?') {
                x[start] = '0';
                y[start] = '1';
                for (int i = start + 1; i < n; ++i) {
                    x[i] = (a[i] == '?' ? '9' : a[i]);
                    y[i] = (b[i] == '?' ? '0' : b[i]);
                }
                ll one = stl(x);
                ll two = stl(y);
                ll dif = abs(one - two);
                if (ans > dif || 
                    (ans == dif && (ansone > one || 
                                    (ansone == one && (anstwo > two))))) {
                    ans = dif;
                    ansx = x;
                    ansy = y;
                    ansone = one;
                    anstwo = two;
                } 
            }
            if (a[start] == '?' && b[start] == '?') {
                x[start] = '1';
                y[start] = '0';
                for (int i = start + 1; i < n; ++i) {
                    x[i] = (a[i] == '?' ? '0' : a[i]);
                    y[i] = (b[i] == '?' ? '9' : b[i]);
                }
                ll one = stl(x);
                ll two = stl(y);
                ll dif = abs(one - two);
                if (ans > dif || 
                    (ans == dif && (ansone > one || 
                                    (ansone == one && (anstwo > two))))) {
                    ans = dif;
                    ansx = x;
                    ansy = y;
                    ansone = one;
                    anstwo = two;
                } 
            }
            if (a[start] == '?' && b[start] != '?') {
                x[start] = (int(b[start] - '0') + 1) % 10 + '0';
                y[start] = b[start];
                for (int i = start + 1; i < n; ++i) {
                    x[i] = (a[i] == '?' ? '0' : a[i]);
                    y[i] = (b[i] == '?' ? '9' : b[i]);
                }
                ll one = stl(x);
                ll two = stl(y);
                ll dif = abs(one - two);
                if (ans > dif || 
                    (ans == dif && (ansone > one || 
                                    (ansone == one && (anstwo > two))))) {
                    ans = dif;
                    ansx = x;
                    ansy = y;
                    ansone = one;
                    anstwo = two;
                } 
            }
            if (a[start] == '?' && b[start] != '?') {
                x[start] = (int(b[start] - '0') + 9) % 10 + '0';
                y[start] = b[start];
                for (int i = start + 1; i < n; ++i) {
                    x[i] = (a[i] == '?' ? '9' : a[i]);
                    y[i] = (b[i] == '?' ? '0' : b[i]);
                }
                ll one = stl(x);
                ll two = stl(y);
                ll dif = abs(one - two);
                if (ans > dif || 
                    (ans == dif && (ansone > one || 
                                    (ansone == one && (anstwo > two))))) {
                    ans = dif;
                    ansx = x;
                    ansy = y;
                    ansone = one;
                    anstwo = two;
                } 
            }
            if (a[start] != '?' && b[start] == '?') {
                x[start] = a[start];
                y[start] = (int(a[start] - '0') + 1) % 10 + '0';
                for (int i = start + 1; i < n; ++i) {
                    x[i] = (a[i] == '?' ? '9' : a[i]);
                    y[i] = (b[i] == '?' ? '0' : b[i]);
                }
                ll one = stl(x);
                ll two = stl(y);
                ll dif = abs(one - two);
                if (ans > dif || 
                    (ans == dif && (ansone > one || 
                                    (ansone == one && (anstwo > two))))) {
                    ans = dif;
                    ansx = x;
                    ansy = y;
                    ansone = one;
                    anstwo = two;
                } 
            }
            if (a[start] != '?' && b[start] == '?') {
                x[start] = a[start];
                y[start] = (int(a[start] - '0') + 9) % 10 + '0';
                for (int i = start + 1; i < n; ++i) {
                    x[i] = (a[i] == '?' ? '0' : a[i]);
                    y[i] = (b[i] == '?' ? '9' : b[i]);
                }
                ll one = stl(x);
                ll two = stl(y);
                ll dif = abs(one - two);
                if (ans > dif || 
                    (ans == dif && (ansone > one || 
                                    (ansone == one && (anstwo > two))))) {
                    ans = dif;
                    ansx = x;
                    ansy = y;
                    ansone = one;
                    anstwo = two;
                } 
            }
            if (a[start] != '?' && b[start] != '?') {
                x[start] = a[start];
                y[start] = b[start];
                for (int i = start + 1; i < n; ++i) {
                    y[i] = (b[i] == '?' ? '9' : b[i]);
                    x[i] = (a[i] == '?' ? '0' : a[i]);
                }
                ll one = stl(x);
                ll two = stl(y);
                ll dif = abs(one - two);
                if (ans > dif || 
                    (ans == dif && (ansone > one || 
                                    (ansone == one && (anstwo > two))))) {
                    ans = dif;
                    ansx = x;
                    ansy = y;
                    ansone = one;
                    anstwo = two;
                } 
            }
            if (a[start] != '?' && b[start] != '?') {
                x[start] = a[start];
                y[start] = b[start];
                for (int i = start + 1; i < n; ++i) {
                    y[i] = (b[i] == '?' ? '0' : b[i]);
                    x[i] = (a[i] == '?' ? '9' : a[i]);
                }
                ll one = stl(x);
                ll two = stl(y);
                ll dif = abs(one - two);
                if (ans > dif || 
                    (ans == dif && (ansone > one || 
                                    (ansone == one && (anstwo > two))))) {
                    ans = dif;
                    ansx = x;
                    ansy = y;
                    ansone = one;
                    anstwo = two;
                } 
            }
        } else {
            ll one = stl(x);
            ll two = stl(y);
            ll dif = abs(one - two);
            if (ans > dif || 
                (ans == dif && (ansone > one || 
                                (ansone == one && (anstwo > two))))) {
                ans = dif;
                ansx = x;
                ansy = y;
                ansone = one;
                anstwo = two;
            }             
        }
    }
    return {ansx, ansy};
}

int main() {
    init();

    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test) {
        string a, b;
        cin >> a >> b;
        n = a.length();
        auto ans = solve(a, b);
        cout << "Case #" << test << ": " << ans.ff << ' ' << ans.ss << '\n';
    }




    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
