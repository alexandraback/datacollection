#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>
#include <bitset>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define MAXN 1005
#define INF 100000000
int F[MAXN];
int D[MAXN][MAXN];
bool is_leaf[MAXN];

int best[MAXN];
int second_best[MAXN];
bool vis[MAXN];
int N;

void dfs(int i) {
    if (vis[i]) return;
    vis[i] = true;

    dfs(F[i]);
    D[i][F[i]] = 1;
    FOR(j,N) D[i][j] = min(D[i][j], D[i][F[i]] + D[F[i]][j]);
}

int main() {
    int TEST;
    scanf("%d",&TEST);
    FOR(test,TEST) {
        memset(F,0,sizeof(F));
        memset(best,0,sizeof(best));
        memset(second_best,0,sizeof(second_best));
        memset(D,0,sizeof(D));
        memset(is_leaf,0,sizeof(is_leaf));
        memset(vis,0,sizeof(vis));

        scanf("%d",&N);
        FOR(i,N) is_leaf[i] = true;
        FOR(i,N) scanf("%d",&F[i]), F[i]--, is_leaf[F[i]] = false;
        FOR(i,N) FOR(j,N) D[i][j] = INF;

        // do it twice
        FOR(times,2) {
            memset(vis,0,sizeof(vis));
            FOR(i,N) if (!vis[i]) dfs(i);
            FOR(i,N) assert(vis[i]);
        }

        int ans = 0;

        // Case 1: Just a cycle
        FOR(i,N) if (D[i][i] < INF) ans = max(ans, D[i][i]);

        // Case 2: Self-loops and 2-cycles
        FOR(i,N) FOR(j,N) if (is_leaf[i] && D[i][j] < INF && (D[j][j] == 1 || (D[j][j] == 2 && D[i][F[j]] > D[i][j]))) {
            if (D[i][j] > best[j]) {
                second_best[j] = best[j];
                best[j] = D[i][j];
            } else if (D[i][j] > second_best[j]) {
                second_best[j] = D[i][j];
            }
        }

        int sum = 0;

        FOR(i,N)
            if (D[i][i] == 1) sum += best[i] + second_best[i] + 1;
            else if (D[i][i] == 2) sum += best[i] + 1;

        ans = max(ans,sum);

        printf("Case #%d: %d\n", test+1, ans);
    }

}































