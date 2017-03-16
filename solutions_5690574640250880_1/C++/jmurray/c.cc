#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

char mine[1024][1024];

int main() {
    int n;
    scanf("%d",&n);
    for(int aoeu=1;aoeu<=n;aoeu++) {
        printf("Case #%d:\n",aoeu);
        int rows,cols,mines;
        scanf("%d %d %d",&rows,&cols,&mines);
        int empty = rows*cols-mines;
        if(empty==1) {
            for(int i=0;i<rows;i++,putchar('\n'))for(int j=0;j<cols;j++) {
                putchar(i==0&&j==0?'c':'*');
            }
            continue;
        }
        if (min(rows,cols)==1) {
            for(int i=0;i<rows;i++,putchar('\n'))for(int j=0;j<cols;j++){
                if(i==0&&j==0){putchar('c');empty--; }
                else{
                    if(empty){putchar('.');empty--;}
                    else putchar('*');
                }
            }
            continue;
        }
        vector<vector<bool> > dp(cols+1, vector<bool>(empty+1));
        vector<vector<int> > backtrack(cols+1, vector<int>(empty+1));
        for(int n=0;n<=empty;n++) {
            for(int h=0;h<=cols;h++) {
                if (!n) dp[h][0]=true;
                else for(int hh=2;hh<=h;hh++) {
                    if (n >= hh && dp[hh][n-hh]) {
                        dp[h][n] = true;
                        backtrack[h][n] = hh;
                    }
                }
            }
        }
        int first_cols = -1;
        for (int i=2;i<=cols;i++) {
            if (2*i <= empty && dp[i][empty-2*i]) {
                first_cols = i;
            }
        }
        if (first_cols == -1) {
            printf("Impossible\n");
        } else {
            int left = empty;
            for(int j=0;j<cols;j++){
                mine[0][j]=(j<first_cols?'.':'*');
            }
            left-=first_cols;
            for(int i=1;i<rows;i++){
                for(int j=0;j<cols;j++){
                    if(left && j < first_cols) {
                        mine[i][j] = '.';
                        left--;
                    } else {
                        mine[i][j]='*';
                    }
                }
                assert(left>=0);
                first_cols = backtrack[first_cols][left];
            }
            if(left) {
                printf("Impossible\n");
            } else {
                mine[0][0]='c';
                for(int i=0;i<rows;i++,putchar('\n'))for(int j=0;j<cols;j++) {
                    putchar(mine[i][j]);
                }
            }
        }
    }
    return 0;
}
