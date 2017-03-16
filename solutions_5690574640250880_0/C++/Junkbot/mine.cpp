#include <cstdio>
#include <vector>
#include <string>
using namespace std;

#undef DEBUG
#ifdef DEBUG
#define D(x...) fprintf(stderr,x)
#else
#define D(x...)
#endif

const int MAX_RC = 12;

int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};

int R, C, M;
char board[MAX_RC][MAX_RC];

void printAnswer(void);
bool solve(int filled);

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        printf("Case #%d:\n",z);

        scanf("%d %d %d",&R,&C,&M);

        for(int i=0;i<MAX_RC;i++) {
            for(int j=0;j<MAX_RC;j++) {
                if(i < R && j < C) {
                    board[i][j] = '*';
                } else {
                    board[i][j] = 0;
                }
            }
        }

        bool done = false;
        for(int i=0;i<(R/2)+(R%2);i++) {
            if(done) {
                break;
            }

            for(int j=0;j<(C/2)+(C%2);j++) {
                if(done) {
                    break;
                }

                board[i][j] = 'c';
                bool res = solve(1);
                board[i][j] = '*';

                if(res) {
                    done = true;
                    break;
                }
            }
        }

        if(!done) {
            printf("Impossible\n");
        }
    }

    return 0;
}

void printAnswer(void) {
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}

bool solve(int filled) {
    if(filled == (R*C)-M) {
        printAnswer();
        return true;
    } else if(filled > (R*C)-M) {
        return false;
    } else {
        D("%%%% solve(%d)\n",filled);

        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                D("%c",board[i][j]);
            }
            D("\n");
        }

        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                if(board[i][j] == '*') {
                    continue;
                }

                int num = 0;
                int mask = 0;

                for(int k=0;k<8;k++) {
                    int nr = i+dr[k];
                    int nc = j+dc[k];

                    if(nr >= 0 && nc >= 0 && nr < R && nc < C && board[nr][nc] == '*') {
                        mask |= (1 << k);
                        num++;
                    }
                }

                if(num > 0) {
                    for(int k=0;k<8;k++) {
                        if(mask & (1<<k)) {
                            board[i+dr[k]][j+dc[k]] = '.';
                        }
                    }

                    bool res = solve(filled + num);

                    for(int k=0;k<8;k++) {
                        if(mask & (1<<k)) {
                            board[i+dr[k]][j+dc[k]] = '*';
                        }
                    }

                    if(res) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}
