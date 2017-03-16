#include <cstdio>

using namespace std;

const int MAXN = 100 +5;
const char* OUTPUT[] = {"NO", "YES"};

int map[MAXN][MAXN];
int rmax[MAXN], cmax[MAXN];
int N, M;

void input() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
}

int solve() {
    for (int i=0; i<N; ++i) {
        rmax[i] = 0;
        for (int j=0; j<M; ++j) {
            if (rmax[i] < map[i][j])
                rmax[i] = map[i][j];
        }
    }
    for (int j=0; j<M; ++j) {
        cmax[j] = 0;
        for (int i=0; i<N; ++i) {
            if (cmax[j] < map[i][j])
                cmax[j] = map[i][j];
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (map[i][j] < rmax[i])
                if (map[i][j] < cmax[j])
                    return 0;
        }
    }

    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; ++i) {
        printf("Case #%d: ", i);
        input();
        int res = solve();
        printf("%s\n", OUTPUT[res]);
    }
}
