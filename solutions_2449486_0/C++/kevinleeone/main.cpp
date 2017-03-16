#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
    int round;
    scanf("%d", &round);
    for (int r = 1; r <= round; ++r) {
        int row, col, * lawn;
        bool* possible, pattern = true;
        scanf("%d%d", &row, &col);
        lawn = (int*) calloc(row * col, sizeof(int));
        possible = (bool*) calloc(row * col, sizeof(bool));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                scanf("%d", &lawn[i * col + j]);
            }
        }
        for (int i = 0; i < row; ++i) {
            int max = 0;
            for (int j = 0; j < col; ++j) {
                if (max < lawn[i * col + j]) {
                    max = lawn[i * col + j];
                }
            }
            for (int j = 0; j < col; ++j) {
                if (max == lawn[i * col + j]) {
                    possible[i * col + j] = true;
                }
            }
        }
        for (int j = 0; j < col; ++j) {
            int max = 0;
            for (int i = 0; i < row; ++i) {
                if (max < lawn[i * col + j]) {
                    max = lawn[i * col + j];
                }
            }
            for (int i = 0; i < row; ++i) {
                if (max == lawn[i * col + j]) {
                    possible[i * col + j] = true;
                }
            }
        }
        for (int i = 0; i < row * col; ++i) {
            if (!possible[i]) {
                pattern = false;
                break;
            }
        }
        if (pattern) {
            printf("Case #%d: YES\n", r);
        } else {
            printf("Case #%d: NO\n", r);
        }
        free(lawn);
        free(possible);
    }
    return 0;
}

