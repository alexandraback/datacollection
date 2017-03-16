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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;

int n, k;
vector<vector<int> > g;
vector<int> mt;
vector<int> used;

bool kun(int v) {
    if (used[v])  
        return false;
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if ((mt[to] == -1) || (kun(mt[to]))) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}



ll solve() {
    int N;
    cin >> N;
    string s1, s2;
    vector<pii> ed;
    map<string, int> m1, m2;
    n = 0, k = 0;
    for (int i = 0; i < N; ++i) {
        cin >> s1 >> s2;
        if (m1.find(s1) == m1.end()) {
            m1[s1] = n;
            ++n;
        }
        if (m2.find(s2) == m2.end()) {
            m2[s2] = k;
            ++k;
        }
        ed.push_back(pii(m1[s1], m2[s2]));
    }
    g.clear();
    g.resize(n);
    for (int i = 0; i < ed.size(); ++i) {
        g[ed[i].first].push_back(ed[i].second);
    }
    int par = 0;
    mt.assign(k, -1);
    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        par += kun(v);
    }
    return N - n - k + par;
}
   



int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tt;
    cin >> tt;
    for (int i = 0; i < tt; ++i) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
        std::cerr << i << endl;
    }
    return 0;
}
