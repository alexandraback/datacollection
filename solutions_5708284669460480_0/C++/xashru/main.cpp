#define _CRT_SECURE_NO_WARNINGS

#include <cctype>
#include <climits>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <ratio>
#include <regex>
#include <string>
#include <tuple>
#include <utility>
#include <valarray>

using namespace std;

#define INF ULLONG_MAX
#define MIN LLONG_MIN
#define pi 3.1415926535897932384626433832795

#define sz(v) v.size()
#define pb(x) push_back(x)
#define fill(v,n,x) for(int i=0;i<(int)n;i++) v.push_back(x)
#define FOR(i,n) for(i=0;i<n;i++)
#define re return
#define sum(v) accumulate(v.begin(),v.end(),0)
#define asrt(v) sort(v.begin(),v.end())
#define dsrt(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define print(v) for (auto& i:v) cout<<i<<endl
#define print "Case #"+to_string(t1)+": "

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;

struct node{
    string s;
    ld p = 1;
    int c = 0;
};

int cnt(string s, string t) {
    if (sz(s) < sz(t)) re 0;
    if (sz(s) == sz(t)) re s == t ? 1 : 0;
    int cc = 0;
    int n = sz(s), m = sz(t);
    for (int i = 0; i <= n - m; i++) {
        string ss = s.substr(i, m);
        if (ss == t) cc++;
    }
    re cc;
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.txt", "w", stdout);
    cout << setprecision(20);
    int T;
    cin >> T;
    for (int t1 = 1; t1 <= T; t1++) {
        int K, L, S;
        cin >> K >> L >> S;
        string kk, ll;
        cin >> kk >> ll;
        deque < node>V;
        node start;
        start.s = "";
        start.p = 1;
        int M = 0;
        ld tot = 0;
        V.push_back(start);
        for (int i = 0; i < S; i++) {
            int n = sz(V);
            for (int j = 0; j < n; j++) {
                node cur = V[j];
                for (int k = 0; k < K; k++) {
                    node t;
                    string ss = cur.s;
                    ss += kk[k];
                    t.s = ss;
                    t.p = cur.p / (ld)K;
                    t.c = cnt(t.s, ll);
                    if (i == S - 1) {
                        M = max(M, t.c);
                        tot += t.p*(ld)t.c;
                    }
                    V.push_back(t);
                }
            }
            for (int k = 0; k < n; k++) V.pop_front();
        }


        if (M == 0) {
            cout << print << 0 << endl;
        }
        else {
            cout << print << (ld)M - tot << endl;
        }
    }
    getchar();
    return 0;
}

