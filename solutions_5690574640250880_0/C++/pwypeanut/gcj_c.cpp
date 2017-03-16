#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
bool visited[5][5];
int grid[5][5], hi[25];
int T, R, C, M;
bool check_valid(int X, int Y) {
    if ( X < 0 || X >= R ) return false;
    if ( Y < 0 || Y >= C ) return false;
    return true;
}

bool have_neighbours(int X, int Y) {
    for ( int i = 0; i < 8; i++ ) if ( check_valid(X + dir[i][0], Y + dir[i][1]) ) if ( grid[X + dir[i][0]][Y + dir[i][1]] == 1 ) return true;
    return false;
}
void dfs(int X, int Y) {
    if ( visited[X][Y] ) return;
    else visited[X][Y] = true;
    if ( have_neighbours(X, Y) ) return;
    for ( int i = 0; i < 8; i++ ) if ( check_valid(X + dir[i][0], Y + dir[i][1]) ) if ( !visited[X + dir[i][0]][Y + dir[i][1]] ) dfs(X + dir[i][0], Y + dir[i][1]);
}

int main() {
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.out", "w", stdout);
    scanf("%d", &T);
    for ( int tc = 1; tc <= T; tc++ ) {
        scanf("%d%d%d", &R, &C, &M);
        memset(hi, 0, sizeof(hi));
        for ( int i = 0; i < M; i++ ) hi[i] = 1;
        sort(hi, hi + R*C);
        do {
            memset(visited, 0, sizeof(visited));
            for ( int i = 0; i < R*C; i++ ) {
                if ( hi[i] > 0 ) {
                    grid[i/C][i%C] = 1;
                }
                else grid[i/C][i%C] = 0;
            }
            int dfsx, dfsy;
            for ( int i = 0; i < R; i++ ) {
                for ( int j = 0; j < C; j++ ) {
                    if ( grid[i][j] == 0 && !have_neighbours(i, j) ) {
                        dfs(i, j);
                        dfsx = i;
                        dfsy = j;
                        goto death;
                    }
                }
            }
            for ( int i = 0; i < R; i++ ) {
                for ( int j = 0; j < C; j++ ) {
                    if ( grid[i][j] == 0 ) {
                        dfs(i, j);
                        dfsx = i;
                        dfsy = j;
                        goto death;
                    }
                }
            }
            death:
            for ( int i = 0; i < R; i++ ) {
                for ( int j = 0; j < C; j++ ) {
                    if ( grid[i][j] == 0 && !visited[i][j] ) goto hell;
                }
            }
            printf("Case #%d:\n", tc);
            for ( int i = 0; i < R; i++ ) {
                for ( int j = 0; j < C; j++ ) {
                    if ( dfsx == i && dfsy == j ) printf("c");
                    else if ( grid[i][j] == 1 ) printf("*");
                    else printf(".");
                }
                printf("\n");
            }
            goto end;
            hell:
            0+0;
        } while ( next_permutation(hi, hi + R*C) );
        printf("Case #%d:\nImpossible\n", tc);
        end:
            0+0;
    }
}
