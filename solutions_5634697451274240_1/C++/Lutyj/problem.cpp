#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXL = 100;

char S[MAXL+1];
int dist[MAXL+1][2];
pair<int, int> Q[MAXL*2+2];

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) { 
        printf("Case #%d: ", t+1);
        scanf("%s", S);
        int LS = strlen(S), N = 0;

        for (int i = 0; i < LS; ++i)
            if (i == 0 || S[i] != S[i-1]) ++N;

        memset(dist, -1, sizeof(dist));
        Q[0] = make_pair(N, (S[LS-1] == '-') ? 0 : 1);
        dist[Q[0].first][Q[0].second] = 0;

        int L = 0, R = 0;
        while (L <= R) {
            N = Q[L].first;
            LS = Q[L].second;
            ++L;

            if (N > 1 && dist[N-1][LS] == -1) {
                dist[N-1][LS] = dist[N][LS] + 1;
                Q[++R] = make_pair(N-1, LS);
            }

            if (dist[N][1-LS] == -1) {
                dist[N][1-LS] = dist[N][LS] + 1;
                Q[++R] = make_pair(N, 1-LS);
            }
        }

        printf("%d\n", dist[1][1]);
    }

    return 0;
}
