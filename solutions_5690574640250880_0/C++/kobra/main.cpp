#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <memory.h>

using namespace std;
/*

vector<int> matrix;
int N, M, K;
int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 0, -1, 1, 1, 0, -1, -1};


bool isZero(int x, int y) {
    if (matrix[ x * M + y ] == 1)
        return false;
    for(int i = 0; i < 8; i++)
    {
        if( (x + dx[i] < 0) || (x + dx[i] >= N) || (y + dy[i] < 0) || (y + dy[i] >=M) )
            continue;
        if (matrix[ (x + dx[i]) * M + y + dy[i]] == 1)
            return false;
    }
    return true;
}

bool hasZero(int x, int y) {
    if (matrix[ x * M + y ] == 1)
        return false;
    for(int i = 0; i < 8; i++)
    {
        if( (x + dx[i] < 0) || (x + dx[i] >= N) || (y + dy[i] < 0) || (y + dy[i] >=M) )
            continue;
        if (isZero(x + dx[i], y + dy[i]))
            return true;
    }
    return false;
}

bool isOk() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(matrix[i * M + j] == 0)
                if(!(isZero(i, j) || hasZero(i, j)))
                    return false;
    vector<bool> zero;
    int cord;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(isZero(i, j)) {
                cord = i * M + j;
                zero.push_back(true);
            }
            else
                zero.push_back(false);
    queue<int> Q;
    zero[cord] = false;
    Q.push(cord);
    while(!Q.empty()) {
        cord = Q.front();
        Q.pop();
        int x = cord / M;
        int y = cord % M;
        for(int i = 0; i < 8; i++)
        {
            if( (x + dx[i] < 0) || (x + dx[i] >= N) || (y + dy[i] < 0) || (y + dy[i] >=M) )
                continue;
            cord = (x + dx[i]) * M + y + dy[i];
            if (zero[cord]) {
                zero[cord] = false;
                Q.push(cord);
            }
        }
    }
    for(int i = 0; i < N * M; i++)
        if(zero[i])
            return false;
    return true;
}

bool next_permutation() {
    int size = N * M;
    int zero = 0;
    for(int i = size - 1; i >=0; i--)
        if(matrix[i] == 1)
            break;
        else
            zero++;
    int one = 0;
    for(int i = size - 1 - zero; i >=0; i--)
        if (matrix[i] == 0)
            break;
        else
            one++;
    if(one + zero == size)
        return false;
    matrix[size - one - zero - 1] = 1;
    one--;
    zero++;
    for(int i = 0; i < one; i++)
        matrix[size - 1 - i] = 1;
    for(int i = 0; i < zero; i++)
        matrix[size - 1 - one - i] = 0;
    return true;
}

int main()
{

    freopen("C.out", "w", stdout);
    for (N = 1; N < 6; N++)
        for(M = N; M < 6; M++) {
            printf("%dx%d\n", N, M);

            for(K = 1; K < N * M - 1; K++) {
                bool possible = false;
                matrix.clear();
                for(int l = 0; l < N * M; l++)
                    if (l + K >= N * M)
                        matrix.push_back(1);
                    else
                        matrix.push_back(0);
                do {
                    if (isOk()) {
                        isOk();
                        possible = true;
                        break;
                    }
                }
                while(next_permutation());
                if(possible) {
                    printf("%d - pos\n", K);
                    for (int i = 0; i < N; i++) {
                        for(int j = 0; j < M; j++)
                            if(matrix[i * M + j] == 0)
                                printf(".");
                            else
                                printf("*");
                        printf("\n");
                    }
                }
                else
                    printf("%d - impos\n", K);

            }
        }
    return 0;
}
*/



const int MAX = 51;
char D[MAX][MAX][MAX*MAX][MAX];

bool possible(int N, int M, int K, int s) {
    if (D[N][M][K][s] == -1) {
        if (K > N * M) {
            D[N][M][K][s] = 0;
        } else {
            for(int i = 0; i <= s; i++)
                if (possible(N-1, M, K-i, i) == 1)
                    D[N][M][K][s] = 1;
            if (D[N][M][K][s] != 1)
                D[N][M][K][s] = 0;
        }
    }
    return D[N][M][K][s] == 1;
}

int main()
{
    memset(D, -1, sizeof(D));
    for(int i = 1; i < MAX; i++) {
        for(int k = 0; k < MAX * MAX; k++) {
            for(int s = 0; s < MAX; s++)
                if (2 * s >= k && s <= i && k % 2 == 0 && s != i - 1 && (2 * i - k != 2))
                    D[2][i][k][s] = 1;
                else
                    D[2][i][k][s] = 0;
        }
    }

    for(int i = 1; i < MAX; i++)
        for(int j = 1; j < MAX; j++)
            for(int k = 0; k < MAX * MAX; k++)
                D[i][j][k][j-1] = 0;

    for(int i = 1; i < MAX; i++) {
        for(int k = 0; k < MAX; k++) {
            for(int s = 0; s < MAX; s++)
                D[1][i][k][s] = D[i][1][k][s] = 1;
        }
    }

    freopen("C-small-attempt8.in", "r", stdin);
    freopen("C.out", "w", stdout);

    int T;
    cin >> T;
    for (int z = 0; z < T; z++) {
        int N, M, K;
        cin >> N >> M >> K;



        printf("Case #%d:\n", z + 1);

        if (M == 1) {
            for(int i = 0; i < K; i++)
                printf("*\n");
            for(int i = K; i < N - 1; i++)
                printf(".\n");
            printf("c\n");
            continue;
        }

        if(N * M - 1 == K) {
            for(int i = 0; i < N - 1; i++) {
                for(int j = 0; j < M; j++)
                    printf("*");
                printf("\n");
            }
            for(int i = 0; i < M - 1; i++)
                printf("*");
            printf("c\n");
            continue;
        }

        if (!possible(N, M, K, M))
            printf("Impossible\n");
        else {
            int lastS = M;
            while (N > 2) {
                for(int i = 0; i <= lastS; i++) {
                    if (possible(N - 1, M, K - i, i)) {
                        for(int j = i; j < M; j++)
                            printf(".");
                        printf("\n");
                        lastS = i;
                        K-=i;
                        N--;
                        break;
                    } else {
                        printf("*");
                    }
                }
            }
            if (N == 2) {
                for(int j = 0; j < K / 2; j++)
                    printf("*");
                for(int j = K / 2; j < M; j++)
                        printf(".");
                printf("\n");
                for(int j = 0; j < K / 2; j++)
                    printf("*");
                for(int j = K / 2; j < M - 1; j++)
                        printf(".");
                printf("c\n");
            } else {
                for(int i = 0; i < K; i++)
                    printf("*");
                for(int i = K; i < M - 1; i++)
                    printf(".");
                printf("c\n");
            }
        }
    }
    return 0;
}

