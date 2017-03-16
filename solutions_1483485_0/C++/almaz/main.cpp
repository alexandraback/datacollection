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
    vector<string> v;
    v.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
    v.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    v.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");
    vector<string> tr;
    tr.push_back("our language is impossible to understand");
    tr.push_back("there are twenty six factorial possibilities");
    tr.push_back("so it is okay if you want to just give up");
    map<char, char> M;
    for (int i = 0; i < v.size(); ++i) {
        assert(v[i].size() == tr[i].size());
        for (int j = 0; j < v[i].size(); ++j) {
            if (M.count(v[i][j])) {
                assert(M[v[i][j]] == tr[i][j]);
            }
            M[v[i][j]] = tr[i][j];
        } 
    }
    M['q'] = 'z';
    M['z'] = 'q';
    assert(M.count(' '));
    assert(M.size() == 27);
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
        s[i] = M[s[i]];
    }
    return s;
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