#include <stdio.h>
#include <string.h>
int height[105][105];
bool can[105][105];
int count = 0;

int main() {
    int T;
    scanf("%d", &T);
    int M, N;
    for (int i = 0; i < T; i++) {
        scanf("%d%d", &N, &M);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                scanf("%d", &height[j][k]);
            }
        }
        count = 0;
        memset(can, false, sizeof(can));
        bool can_solve = true;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int max = height[j][k];
                bool find_path = true;
                for (int t = 0; t < N; t++) {
                    if (height[t][k] > max) {
                        find_path = false;
                        break;
                    }
                }
                if (find_path) continue;
                find_path = true;
                for (int t = 0; t < M; t++) {
                    if (height[j][t] > max) {
                        find_path = false;
                        break;
                    }
                }
                if (!find_path) {
                    can_solve = false;
                    break;
                }
            }
            if (!can_solve) {
                break;
            }
        }
        printf("Case #%d: ", i + 1);
        if (!can_solve) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}

// (shell-command (format "%s < %s > %s " ts-run-file-name "B-small-attempt0.in" "B-small-attempt0.out"))
// (shell-command (format "%s < %s > %s " ts-run-file-name "A-large.in" "A-large.out"))
