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
     int n, s, p;
     cin >> n >> s >> p;
     vector<bool> can(MAXN + 1, false), canSurprised(MAXN + 1, false);
     for (int i = 0; i <= TEN; ++i) {
         for (int j = i; j <= TEN; ++j) {
             for (int k = j; k <= TEN; ++k) {
                int sum = i + j + k;
                if (k < p || k - i > 2) {
                    continue;
                }
                if (k - i == 2) {
                    canSurprised[sum] = true;
                }
                else {
                    can[sum] = true;
                }
             }
         }
     }
     int res = 0;
     for (int i = 0; i < n; ++i) {
         int x;
         cin >> x;
         if (can[x]) {
             ++res;
         }
         else if (s > 0 && canSurprised[x]) {
             ++res;
             --s;
         }
     }
     return toStr(res);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        string res = solve();
        fprintf(stdout, "Case #%d: %s\n", test, res.c_str());
        fprintf(stderr, "Case #%d: %s\n", test, res.c_str());
    }
    return 0;
}