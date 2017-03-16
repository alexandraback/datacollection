#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int A[102][102], B[102][102], R[102], C[102], M, N, T;
    scanf("%d\n", &T);
    for (int t = 1; t <= T; t++) {
        
        scanf("%d %d\n", &M, &N);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &A[i][j]);
            }
            scanf("\n");
        }

        for (int i = 0; i < 102; i++) R[i] = C[i] = -1;

        // Max rows / cols
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) 
                if (A[i][j] > R[i]) R[i] = A[i][j];
        }
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++)
                if (A[i][j] > C[j]) C[j] = A[i][j];
        }

        // Check
        bool possible = true;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] != min(R[i], C[j])) {
                    possible = false;
                    break;
                }
            }
        }

        printf("Case #%d: %s\n", t, possible ? "YES" : "NO");

    }
}
