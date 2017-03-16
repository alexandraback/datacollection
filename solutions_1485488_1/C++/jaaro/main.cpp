#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

const int MOD = 127;

int MIN[111][111], MAX[111][111];
bool DP[MOD + 1][111][111];
int hlevel, curr, N, M;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool move(int x0, int y0, int x1, int y1)
{
    if (x1 < 1 || x1 > N || y1 < 1 || y1 > M) return false;

    if (MAX[x1][y1] - MIN[x1][y1] < 50) return false;
    if (MAX[x1][y1] - hlevel < 50) return false;
    if (MAX[x1][y1] - MIN[x0][y0] < 50) return false;

    if (MAX[x0][y0] - hlevel < 50) return false;
    if (MAX[x0][y0] - MIN[x1][y1] < 50) return false;
    return true;

}

void one_move()
{
    int prev = (curr + MOD) % (MOD + 1);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            DP[prev][i][j] = false;
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if (DP[curr & MOD][i][j]) {
                for(int k=0; k<4; k++) {
                    if (move(i, j, i + dx[k], j + dy[k])) {
                        int x = curr + 10;
                        if (hlevel - MIN[i][j] < 20) x = curr + 100;

                        DP[x & MOD][i + dx[k]][j + dy[k]] = true;
                    }
                }
                DP[(curr+1) & MOD][i][j] = true;
            }
        }
    }
}

int main()
{
    int numberOfCases;
    scanf("%d",&numberOfCases);
    for(int testNo=1; testNo<=numberOfCases; testNo++) {
        scanf("%d %d %d",&hlevel, &N, &M);

        curr = 0;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                scanf("%d", &MAX[i][j]);
            }
        }

        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++)
                for(int k=0; k<=MOD; k++)
                    DP[k][i][j] = false;
        }

        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                scanf("%d", &MIN[i][j]);
            }
        }


        DP[curr][1][1] = true;
        for(int kk=0; kk<=N+M; kk++) {
            for(int i=1; i<=N; i++) {
                for(int j=1; j<=M; j++) {
                    for(int k=0; k<4; k++) {
                        if (DP[curr][i][j] && move(i, j, i + dx[k], j + dy[k])) {
                            DP[curr][i + dx[k]][j + dy[k]] = true;
                        }
                    }
                }
            }
        }

        printf("Case #%d: ", testNo);

        while(!DP[curr & MOD][N][M]) {
            one_move();
            hlevel--;
            curr++;
        }

        std::cerr << "END " << testNo << std::endl;

        printf("%lf\n", curr / 10.0);
    }
}
