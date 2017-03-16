// {{{
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <numeric>
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define FOR(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SIZE(x) ((int) ((x).size()))
#define DEBUG(x) { cerr << #x << ": " << (x) << endl; }
#define SQR(x) ((x) * (x))
#define INF 1023456789
using namespace std;

template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os;
}

template<typename T> ostream& operator << (ostream& os, const vector<T>& v) {
    os << "["; FORE(i, v) { if (i != v.begin()) os << ", "; os << *i; } os << "]"; return os;
}

typedef long long LL;
typedef pair<int, int> PI;
typedef pair<int, PI> TRI;
typedef vector<int> VI;
typedef vector<VI> VVI;
// }}}

int n, m;
VI zip;
VVI G;

bool connected(const vector<bool>& F) {
    vector<bool> V(F);
    bool first = true;
    REP(i, n) if (!V[i]) {
        if (first) {
            first = false;
        } else {
            return false;
        }
        queue<int> Q;
        Q.push(i);
        V[i] = true;
        while (!Q.empty()) {
            int t = Q.front();
            Q.pop();
            FORE(i, G[t]) if (!V[*i]) {
                Q.push(*i);
                V[*i] = true;
            }
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    FOR(ti, 1, t) {
        scanf("%d%d", &n, &m);
        zip.clear();
        zip.resize(n);
        REP(i, n)
            scanf("%d", &zip[i]);
        G.clear();
        G.resize(n);
        REP(i, m) {
            int a, b;
            scanf("%d%d", &a, &b);
            --a, --b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        printf("Case #%d: ", ti);

        int start = -1;
        REP(i, n) if (start == -1 || zip[i] < zip[start])
            start = i;

        VI S;
        vector<bool> open(n, false);
        vector<bool> closed(n, false);
        S.push_back(start);
        printf("%d", zip[start]);
        open[start] = true;

        while (!S.empty()) {
            PI best = PI(-1, -1);
            vector<bool> F(closed);
            FORD(i, SIZE(S) - 1, 0) {
                FORE(j, G[S[i]]) if (!open[*j] && !closed[*j])
                    if (best == PI(-1, -1) || zip[*j] < zip[best.second])
                        best = PI(i, *j);
                F[S[i]] = true;
                if (!connected(F))
                    break;
            }
            if (best == PI(-1, -1))
                break;
            while (best.first != SIZE(S) - 1) {
                closed[S.back()] = true;
                S.pop_back();
            }
            S.push_back(best.second);
            printf("%d", zip[best.second]);
            open[best.second] = true;
        }

        printf("\n");
    }
}
