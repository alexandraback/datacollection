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

const int MAXN = 20 * 100 * 1000 + 5;

string solve() {
    vector<int> M(MAXN, -1);
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int a = -1, b = -1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int s = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                s += v[i];
            }
        }
        if (M[s] != -1) {
            a = M[s];
            b = mask;
            break;
        }
        M[s] = mask;
    }
    if (a == -1) {
        return "\nImpossible";
    }
    stringstream res;
    res << "\n";
    for (int i = 0; i < n; ++i) {
        if ((a >> i) & 1) {
            res << v[i] << " ";
        }
    }
    res << "\n";
    for (int i = 0; i < n; ++i) {
        if ((b >> i) & 1) {
            res << v[i] << " ";
        }
    }
    return res.str();
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