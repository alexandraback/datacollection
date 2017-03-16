#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int int64;
typedef long double ext;


const int maxn = 50;


bool mat[maxn][maxn];

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test++) {        
        int N;
        int64 M;
        scanf("%d %lld", &N, &M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mat[i][j] = false;
            }
        }
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N - 1; j++) {
                mat[i][j] = true;
            }
        }
        int64 mx = (1ll << (N - 2));        
        printf("Case #%d: ", test +  1);
        if (M > mx) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
        if (mx == M) {
            for (int i = 0; i < N - 1; i++) {
                mat[i][N - 1] = true;
            }
        }
        else {
            int64 x = M;
            for (int i = 1; i < N - 1; i++) {
                mat[i][N - 1] = (x & 1ll) == 1;
                x >>= 1;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%c", mat[i][j] ? '1' : '0');
            }
            printf("\n");
        }        
    }
    return 0;
};
