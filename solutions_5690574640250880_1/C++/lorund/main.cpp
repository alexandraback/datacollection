#include <cstdio>
#include <cstring>

int T, R, C, M, m, r, c;
char board[52][52];
bool bboard[52][52];

bool check(){
    for (int i=0; i<=R+1; ++i){
        board[i][0] = board[i][C+1] = '.';
    }
    for (int j=0; j<=C+1; ++j){
        board[0][j] = board[R+1][j] = '.';
    }

    memset(bboard, 0, sizeof(bboard));
    for (int i=1; i<=R; ++i){
        for (int j=1; j<=C; ++j){
            if (board[i][j] == '.'){
                bboard[i][j] = (board[i-1][j] & board[i-1][j+1] & board[i][j+1] & board[i+1][j+1] & board[i+1][j] & board[i+1][j-1] & board[i][j-1] & board[i-1][j-1])=='.';
            }
        }
    }
    for (int i=1; i<=R; ++i){
        for (int j=1; j<=C; ++j){
            if (board[i][j] == '.'){
                if (bboard[i][j])
                    continue;
                if (bboard[i-1][j]||bboard[i-1][j+1]||bboard[i][j+1]||bboard[i+1][j+1]||bboard[i+1][j]||bboard[i+1][j-1]||bboard[i][j-1]||bboard[i-1][j-1])
                    continue;
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);

    scanf("%d", &T);
    for (int t=1; t<=T; ++t){
        printf("Case #%d:\n", t);
        scanf("%d %d %d", &R, &C, &M);
        m = M;
        r = R;
        c = C;
        memset(board, '.', sizeof(board));
        for (;M;){
            if (r<c){
                if (r-1==M){
                    if (c>1){
                        board[r][c-1] = '*';
                        --M;
                    }
                    for (int i=r; i && M; --i){
                        board[i][c] = '*';
                        --M;
                    }
                }
                else{
                    for (int i=r; i && M; --i){
                        board[i][c] = '*';
                        --M;
                    }
                    --c;
                }
            }
            else{
                if (c-1==M){
                    if (r>1){
                        board[r-1][c] = '*';
                        --M;
                    }
                    for (int j=c; j&&M; --j){
                        board[r][j] = '*';
                        --M;
                    }
                }
                else{
                    for (int j=c; j && M; --j){
                        board[r][j] = '*';
                        --M;
                    }
                    --r;
                }
            }
        }
        if (check() || C*R-m==1){
            board[1][1] = 'c';
            for (int i=1; i<=R; ++i){
                for (int j=1; j<=C; ++j){
                    printf("%c", board[i][j]);
                }
                puts("");
            }
        }
        else{
            puts("Impossible");
        }
    }
    return 0;
}
