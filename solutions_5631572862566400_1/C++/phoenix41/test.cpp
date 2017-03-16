#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector < long long > vll;
typedef pair <long long, long long> pll;
typedef pair <int, int> pii;
typedef vector < int > vii;
typedef complex < double > Point;

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mp make_pair
#define fst first
#define snd second
#define prev PREV
ll t, n, m, u, v, q, r, ql, qr, k, l, s, w, h, c, z, d, x, y;
const int N = 1e5 + 500;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 62LL;
const bool JUDGE = false;
int Next[N], ideg[N];
int C[N][2];
int typec[N];
int vis[N];
int main() {
    csl;
    if (JUDGE) {
        freopen("angry.in", "r", stdin);
        freopen("angry.out", "w", stdout);
    }
    cin >> t;
    for (int ii = 1; ii <= t; ++ii) {
        cout << "Case #" << ii << ": ";
        cin >> n;
        for (int i = 0; i <= n; ++i) ideg[i] = 0;
        for (int i = 0; i <= n; ++i) C[i][0] = C[i][1] = 0;
        for (int i = 0; i <= n; ++i) typec[i] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> Next[i];
        }
        for (int i = 1; i <= n; ++i) {
            if (i == Next[Next[i]]) {
                typec[i] = min(i, Next[i]);
                typec[Next[i]] = min(i, Next[i]);
            }
        }
        int sol = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) vis[j] = 0;
            int x = 0;
            int s = i;
            while (!vis[s]) {
                if (i == 2) {
                 //   cout<< s << " " << x << " " ;
                }
                
                vis[s] = ++x;
                s = Next[s];
            }
            //cout << '\n';
            if (x - vis[s] == 1) {
                if (s == typec[s])
                    C[typec[s]][0] = max(C[s][0], x - 2);
                else C[typec[s]][1] = max(C[typec[s]][1], x - 2);
                
            } else {
                 //cout << s << " " << vis[s] << " " << x << "| ";
                sol = max(sol, x - vis[s] + 1);
            }
        }
        int x = 0;
        for (int i = 1; i <= n; ++i) {
            if (typec[i] != 0 && i == typec[i])
                x += C[typec[i]][1] + C[typec[i]][0] + 2;
        }
        //cout << x << " ";
        sol = max(sol, x);
        cout << sol << '\n';
    }
    return 0;
}








