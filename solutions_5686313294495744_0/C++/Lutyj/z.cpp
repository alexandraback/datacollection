#include <cstring>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

const int MAXL = 30;
const int MAXN = 3000;

int N, eu[MAXN], ev[MAXN];
map<string, int> words1, words2;
int G[MAXN][MAXN + 1], p[MAXN];
bool mark[MAXN];
char tmp[MAXL + 1];
int M1, M2;

bool dfs(int u)
{
    if (mark[u]) return false;
    mark[u] = true;

    for (int e = 1; e <= G[u][0]; ++e) {
        int v = G[u][e];
        if (p[v] == -1 || dfs(p[v])) {
            p[v] = u;
            return true;
        }
    }

    return false;
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        words1.clear();
        words2.clear();
        memset(G, 0, sizeof(G));
        memset(p, -1, sizeof(p));

        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%s", tmp);
            if (words1.find(tmp) == words1.end()) {
                int z = words1.size();
                words1[tmp] = z;
            }
            int w1 = words1[tmp];
            scanf("%s", tmp);
            if (words2.find(tmp) == words2.end()) {
                int z = words2.size();
                words2[tmp] = z;
            }
            int w2 = words2[tmp];

            G[w1][++G[w1][0]] = w2;
        }

        M1 = words1.size();
        M2 = words2.size();
        int res = 0;

        for (int u = 0; u < M1; ++u) {
            memset(mark, 0, sizeof(mark));
            if (dfs(u)) ++res;
        }

        printf("Case #%d: %d\n", t + 1, N - (M1 + M2 - res));
    }

    return 0;
}
