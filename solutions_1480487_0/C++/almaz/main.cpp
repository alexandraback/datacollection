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


template <typename T>
string toStr(T x) {
    stringstream ss;
    ss << x;
    return ss.str();
}

string getStr(const vector<LD>& v) {
    char buff[25];
    string res;
    for (int i = 0; i < v.size(); ++i) {
        sprintf(buff, "%0.18lf", v[i]);
        res += string(buff);
        if (i + 1 != v.size()) {
            res += " ";
        }
    }
    return res;
}

string solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int X = accumulate(all(v), 0);
    vector<LD> res(n);
    for (int ID = 0; ID < n; ++ID) {
        LD l = 0, r = 1;
        for (int it = 0; it < 200; ++it) {
            LD mid = (l + r) / 2;
            LD value = mid * X + v[ID];
            LD remain = 1 - mid;
            for (int i = 0; i < n; ++i) {
                if (i == ID) {
                    continue;
                }
                if (v[i] > value) {
                    continue;
                }
                LD takePart = (value - v[i]) / X;
                remain -= takePart;
            }
            if (remain < 0) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        res[ID] = (l + r) / 2 * 100;
    }
    string ans = getStr(res);
    return ans;
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