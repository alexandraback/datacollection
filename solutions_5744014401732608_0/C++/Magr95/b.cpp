#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    freopen("B-small-attempt2.in.txt", "r", stdin);
    freopen("small.txt", "w", stdout);
    int cases;
    cin >> cases;
    int grid[50][50];
    for (int i = 1; i <= cases; i++) {
        printf("Case #%d: ", i);
        int B, M;
        cin >> B >> M;
        for (int j = 0; j < B; j++) {
            for (int l = 0; l < B; l++) {
                grid[j][l] = 0;
            }
        }
        int count = 0;
        bool stop = false;
        //for (int k = 1; k < col; col++) grid[k][col] = 1;
        //for (int j = 1; j < n; j++) grid[j][B-1] = 1;
        while (count < M && !stop) {
            for (int fila = 1; fila <= B-1 && count < M; fila++) {
                for (int j = B - fila; j >= fila && count < M; j--) {
                    count ++;
                    if (j != B - fila) grid[j][B-fila] = 1;
                    grid[fila - 1][j] = 1;
                }
                if (fila == B-1) stop = true;
            }
        }
        if (count < M) printf("IMPOSSIBLE\n");
        else {
            printf("POSSIBLE\n");
            for (int j = 0; j < B; j++) {
                for (int l = 0; l < B; l++) {
                    printf("%d", grid[j][l]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
