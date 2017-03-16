#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N, M;
int matriz[100][100];
int maxfilas[100];
int maxcols[100];

main() {
    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++) {
        memset(maxfilas, 0, sizeof(maxfilas));
        memset(maxcols, 0, sizeof(maxcols));
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                maxfilas[i] = max(maxfilas[i], matriz[i][j]);
                maxcols[j] = max(maxcols[j], matriz[i][j]);
            }
        }
        bool valid = true;
        for (int i = 0; i < N && valid; i++) {
            for (int j = 0; j < M && valid; j++) {
                if (matriz[i][j] != maxfilas[i] && matriz[i][j] != maxcols[j]) {
                    valid = false;
                }
            }
        }
        if (valid) printf("Case #%d: YES\n", caso);
        else printf("Case #%d: NO\n", caso);
    }
}
