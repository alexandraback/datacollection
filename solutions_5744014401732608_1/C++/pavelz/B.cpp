// Description
// URL

#include <bits/stdc++.h>
using namespace std;

#define FOR(c, m) for(int c=0;c<(int)(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)
#define LLI long long int
#define MOD 1000000007

int power(int a, int b) {
    int sq = a;
    int result = 1;
    while (b > 0) {
        if ((b & 1) == 1) result = result * (LLI)sq % MOD;
        sq = sq * (LLI)sq % MOD;
        b >>= 1;
    }
    return result;
}

int inv(int a) {
    return power(a, MOD - 2);
}

void fail() {
    *((char *)0) = 0;
}

/*bool used[1000];
bool edge[10][10];
bool visited[1000];
int ways[1000];
vector<pair<int, int> > edges;
int b;

int calc(int node, int level) {
    if (node == 0) return 1;
    if (level >= 10) return -1;
    visited[node] = true;
    int result = 0;
    FOR(i, b) if (edge[i][node]) {
        int r = calc(i, level + 1);
        if (r >= 0) result += r; else return r;
    }
    ways[node] = result;
    return result;
}*/

#define MAX_B 60
int matrix[MAX_B][MAX_B];

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int cc=1;cc<=cases;cc++) {
        int b;
        LLI m;
        scanf("%d %lld", &b, &m);
        LLI mx = 1;
        mx <<= (b - 2);
        printf("Case #%d: ", cc);
        if (m > mx) printf("IMPOSSIBLE\n");
        else {
            FOR(i, b) FOR(j, b) matrix[i][j] = 0;
            FOR(i, b - 1) FORE(j, i + 1, b - 1) matrix[i][j] = 1;
            if (m == mx) { matrix[0][b - 1] = 1; m--;}
            FORE(i, 1, b - 1) {
                if ((m & 1) == 1) matrix[i][b - 1] = 1;
                m >>= 1;
            }
            printf("POSSIBLE\n");
            FOR(i, b) {
                FOR(j, b) printf("%d", matrix[i][j]);;
                printf("\n");
            }
        }


        /*edges.clear();
        FOR(i, b - 1) edges.push_back(make_pair(0, i + 1));
        FORE(i, 1, b - 1) FORE(j, 1, b) if (i != j) edges.push_back(make_pair(i, j));
        int ts = edges.size();
        FOR(i, 1 << ts) {
            FOR(j, b) FOR(k, b) edge[j][k] = false;
            int t = i;
            FOR(j, ts) {
                if ((t & 1) == 1) edge[edges[j].first][edges[j].second] = true;
                t >>= 1;
            }
            FOR(i, b) visited[i] = false;
            int r = calc(b - 1, 0);
            //printf("%d\n", r);
            if (r >= 0) used[r] = true;
        }
        printf("%d\n", edges.size());
        FOR(i, 1000) if (used[i]) printf("%d\n", i);
        return 0;*/

    }


}
