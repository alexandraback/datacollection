#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;
typedef pair<ll, double> pid;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-9;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;

pll best;



ll toInt(string s) {
    stringstream ss(s);
    ll res;
    ss >> res;
    return res;
}

void upd(string s1, string s2) {
    pll res = make_pair(toInt(s1), toInt(s2));
    if (best.first == -1) {
        best = res;
        return;
    }
    ll d1 = abs(best.first - best.second);
    ll d2 = abs(res.first - res.second);
    if (d1 < d2) {
        return;
    }
    if (d1 > d2) {
        best = res;
        return;
    }
    if (best.first < res.first) {
        return;
    }
    if (best.first > res.first) {
        best = res;
        return;
    }
    if (best.second < res.second) {
        return;
    }
    if (best.second > res.second) {
        best = res;
        return;
    }
    return;
}

void upd11(string s1, string s2, int pos) {
    if (s1[pos] == '9')
        return;
    s1[pos] = s1[pos] + 1;
    int n = s1.size();
    for (int i = pos + 1; i < n; ++i) {
        if (s1[i] == '?')
            s1[i] = '0';
        if (s2[i] == '?')
            s2[i] = '9';
    }
    upd(s1, s2);
}

void upd12(string s1, string s2, int pos) {
    if (s1[pos] == '0')
        return;
    s1[pos] = s1[pos] - 1;
    int n = s1.size();
    for (int i = pos + 1; i < n; ++i) {
        if (s1[i] == '?')
            s1[i] = '9';
        if (s2[i] == '?')
            s2[i] = '0';
    }
    upd(s1, s2);
}

void upd21(string s1, string s2, int pos) {
    if (s2[pos] == '9')
        return;
    s2[pos] = s2[pos] + 1;
    int n = s1.size();
    for (int i = pos + 1; i < n; ++i) {
        if (s1[i] == '?')
            s1[i] = '9';
        if (s2[i] == '?')
            s2[i] = '0';
    }
    upd(s1, s2);
}

void upd22(string s1, string s2, int pos) {
    if (s2[pos] == '0')
        return;
    s2[pos] = s2[pos] - 1;
    int n = s1.size();
    for (int i = pos + 1; i < n; ++i) {
        if (s1[i] == '?')
            s1[i] = '0';
        if (s2[i] == '?')
            s2[i] = '9';
    }
    upd(s1, s2);
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    best = pll(-1, 0);

    int n = s1.size();
    for (int i = 0; i < n; ++i) {
        if ((s1[i] == '?') && (s2[i] == '?')) {
            s1[i] = '0';
            s2[i] = '0';
            upd11(s1, s2, i);
            upd21(s1, s2, i);
            continue;
        }
        if ((s1[i] == '?') && (s2[i] != '?')) {
            s1[i] = s2[i];
            upd11(s1, s2, i);
            upd12(s1, s2, i);


            continue;
        }
        if ((s1[i] != '?') && (s2[i] == '?')) {
            s2[i] = s1[i];
            upd21(s1, s2, i);
            upd22(s1, s2, i);
            continue;
        }
        if (s1[i] == s2[i])
            continue;
        if (s1[i] > s2[i]) {
            for (int j = i + 1; j < n; ++j) {
                if (s1[j] == '?')
                    s1[j] = '0';
                if (s2[j] == '?')
                    s2[j] = '9';
            }
        }
        else {
            for (int j = i + 1; j < n; ++j) {
                if (s2[j] == '?')
                    s2[j] = '0';
                if (s1[j] == '?')
                    s1[j] = '9';
            }
        }
        break;
    }
    upd(s1, s2);
    stringstream ss1;
    ss1 << best.first;
    ss1 >> s1;
    for (int i = s1.size(); i < n; ++i)
        cout << '0';
    cout << best.first << " ";
    stringstream ss2;
    ss2 << best.second;
    ss2 >> s2;
    for (int i = s2.size(); i < n; ++i)
        cout << '0';
    cout << best.second << endl;
    return;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tt;

    cin >> tt;
    for (int i = 0; i < tt; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
        
        std::cerr << i << endl;
    }
    return 0;
}
