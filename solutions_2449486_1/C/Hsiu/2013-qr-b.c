#include <stdio.h>

int main(int argc, char *argv[]){
    int T, cases;
    scanf("%d", &T);
    int ans;
    for (cases = 1; cases <= T; cases++) {
        int N, M;
        scanf("%d%d", &N, &M);
        int i, j;
        int grass[200][200];
        int iStrategy[200], jStrategy[200];
        for (i = 0 ;i < N; ++i)
            for (j = 0; j < M; ++j)
                scanf("%d", &grass[i][j]);
        for (i = 0; i < N; ++i) {
            int m = -1;
            for (j = 0; j < M; ++j)
                if (grass[i][j] > m)
                    m = grass[i][j];
            iStrategy[i] = m;
        }
        for (j = 0; j < M; ++j) {
            int m = -1;
            for (i = 0; i < N; ++i)
                if (grass[i][j] > m)
                    m = grass[i][j];
            jStrategy[j] = m;
        }
        ans = 1;
        for (i = 0; i < N; ++i)
            for (j = 0; j < M; ++j) {
                int m;
                if (iStrategy[i] < jStrategy[j])
                    m = iStrategy[i];
                else
                    m = jStrategy[j];
                if (m != grass[i][j])
                    ans = 0;
            }
                
        if (ans == 0)
            printf("Case #%d: NO\n", cases);
        if (ans == 1)
            printf("Case #%d: YES\n", cases);
    }
    return 0;
}
