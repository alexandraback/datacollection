#include <cstdio>
#include <vector>
#include <algorithm>

typedef std::vector<int> Vec;
typedef std::vector<Vec> Mat;

int main(int argc, char const *argv[]) {
    int cas = 0, T, N, M;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        Vec row(N);
        Vec col(M);

        Mat lawn(N, Vec(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                scanf("%d", &lawn[i][j]);
                row[i] = std::max(row[i], lawn[i][j]);
                col[j] = std::max(col[j], lawn[i][j]);
            }
        }

        bool isValid = true;
        for (int i = 0; i < N && isValid; ++i) {
            for (int j = 0; j < M && isValid; ++j) {
                if (lawn[i][j] < row[i] && lawn[i][j] < col[j]) {
                    isValid = false;
                }
            }
        }

        printf("Case #%d: %s\n", ++cas, isValid ? "YES" : "NO");
    }
    return 0;
}