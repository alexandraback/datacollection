#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstring>
 
using namespace std;
 
#define ll long long
#define point pair<double, double>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define uint unsigned int
//#define double long double
#define merge botva
#define double long double
#define time botva1

#ifdef ONLINE_JUDGE
#define olo "%I64d\n"
#define jolo "%011I64d"
#else
#define olo "%lld\n"
#define jolo "%011Ld"
#endif

#define satan2 atan2
const int maxn = 42000, maxlen = 502 * 502 + 20, consta = 1050, maxi = consta + 4, big = 10000000;
//magic = 239, magic1 = 359;
const long long INF = 1000000000;
const char BLANK = '-', FULL = '#';

long long a[maxn];
int n;
long long sum = 0;

vector<int> e[maxn];
int usd[maxn];
int magic = 1;
bool lold;

void dfs(int v) {
    usd[v] = magic;
    for (int i = 0; i < e[v].size(); ++i)
        if (usd[e[v][i]] == magic)
            lold = 1;
        else dfs(e[v][i]);
}

int main() {
    //freopen("complexity.in", "r", stdin);
    //freopen("complexity.out", "w", stdout);
   
    int h, m, t, v;
    cin >> t;
    map<long long, pair<long long, int> > was;
                //from who
    for (int ti = 1; ti <= t; ++ti) {
        cin >> n;
        lold = 0;
        //n = 20;
        //was.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> m;
            for (int j = 0; j < m; ++j) {
                cin >> v;
                e[i].pb(v);
            }
        }
        for (int i = 1; i <= n; ++i) {
            ++magic;
            dfs(i);
            if (lold) break;
        }
        printf("Case #%d: ", ti);
        if (lold) printf("Yes\n"); else printf("No\n");
        for (int i = 1; i <= n; ++i)
            e[i].clear();
    }

}
