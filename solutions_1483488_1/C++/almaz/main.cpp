#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <math.h>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <cstring>
#include <string>
#include <functional>
#include <numeric>
#include <bitset>
#include <cassert>
#include <complex>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << ": " << x << endl;

const int INF = ((1 << 30) - 1);
const long long LLINF = (((1LL << 60) - 1LL));
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;  

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double LD;
typedef pair<LD, LD> pdd;
typedef pair<ll, ll> pll;


const int TEN = 10;
const int MAXN = 30;

template <typename T>
string toStr(T x) {
    stringstream ss;
    ss << x;
    return ss.str();
}

string solve() {
    int a, b;
    cin >> a >> b;
    ll res = 0;
    vector<int> used(10 * 1000 * 1000 + 5, false);
    for (int i = a; i <= b; ++i) {
        if (used[i]) {
            continue;
        }
        int cnt = 0;
        char buff[10];
        sprintf(buff, "%d", i);
        string s(buff);
        int len = s.size();
        s += s;
        for (int pos = 0; pos < len; ++pos) {
            if (s[pos] != '0') {
                int x;
                sscanf(s.substr(pos, len).c_str(), "%d", &x);
                if (!used[x] && a <= x && x <= b) {
                    ++cnt;
                }
                used[x] = true;
            }
        }
        res += cnt * (cnt - 1) / 2;
    }
    return toStr(res);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    string endline;
    getline(cin, endline);
    for (int test = 1; test <= T; ++test) {
        string res = solve();
        fprintf(stdout, "Case #%d: %s\n", test, res.c_str());
        fprintf(stderr, "Case #%d: %s\n", test, res.c_str());
    }
    return 0;
}