#pragma comment (linker, "/STACK:214721677")
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <string>

using namespace std;

#define REP(i,n) for (int i=0, _n=(n)-1; i <= _n; ++i)
#define REPD(i,n) for (int i=(n)-1; i >= 0; --i)
#define FOR(i,a,b) for (int i=(a), _b=(b); i <= _b; ++i)
#define FORD(i,a,b) for (int i=(a), _b=(b); i >= _b; --i)
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sz(a) ((int) ((a).size()))
template < class T > T sqr (T a) { return (a) * (a); }
template < class T > T abs (T a) { return (a < 0) ? -(a) : (a); }
const double Pi = acos(-1.0);
const double eps = 1e-10;
const int INF = 1000*1000*1000;
const double phi = 0.5 + sqrt(1.25);
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

bitset<1010> used;
vector<int> q;

bool dfs(int v, int from, vector<vector<int> > G) {
    used[v] = 1;
    REP(i, (int) G[v].size())
        if (!used[ G[v][i] ]) {
            if (dfs(G[v][i], v, G))
                return 1;
        }
        else {
            if (G[v][i] != from)
            return 1;
        }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    REP(test, T) {
        int N, m, to;
        scanf("%d\n", &N);
        vector<vector<int> > G (N);
        REP(i, N) {
            scanf("%d", &m);
//          G[i].resize(m);
            REP(j, m) {
                scanf("%d", &to);
                G[i].pb(to - 1);
 //             G[to - 1].pb(i);
            }
            scanf("\n");
        }

        q.clear();


        bool ok = 0;
        REP(vertex, N) {
            used.reset();
            if (dfs(vertex, -1, G)) {
                ok = 1;
                break;
            }
        }

        printf("Case #%d: ", test + 1);
        if (ok)
            printf("Yes\n");
        else
            printf("No\n");

    }

    return 0;
}