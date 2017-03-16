#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>

#define DEBUG 0
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

int R,C,M;

char A[100][100];


int solve(int r, int c, int m, int last) {
    if (m == 0) return 0;
    if (r == 0 || c == 0) return m;
    if (m > r*c) return m;
    if (m == 1 && ((r == 2) || (c == 2))) return m; // 1 is not possible to place if one of the side is 2, 2x2 is also fail because that make the corner non-0
    if (DEBUG) printf("> solve %d %d, %d (last %d)\n", r, c, m, last);

    int x = m;
    if (r > c) {
        // fill bottom rows first
        int offset = 2;
        if (x % c == 0 || c ==2){
            offset = 2;
        }
        int filled_row = min(r-c, min(r - offset, x / c));
        if (filled_row > 0) {
            x -= filled_row * c;
            for (int i=1;i<=filled_row;i++) {
                for (int j=0;j<c;j++) {
                    A[r-i][j] = '*';
                }
            }

            x = solve(r - filled_row, c, x, 0);
        } else {
            if (x > 0) {
                // try to fill last row
                int can_fill = min(x, c - 2);
                if (can_fill == 0 && r == 2) {
                    can_fill = 1;
                }
                if (last > 0 && can_fill > last) {
                    can_fill = last;
                }
                if (can_fill > 0) {
                    for (int i=1;i<=can_fill;i++) {
                        A[r-1][c-i] = '*';
                    }
                    x -= can_fill;
                    // last row is filled with can_fill, if x > can_fill * (r-1), fail
                    if (x > can_fill * (r-1)) {
                        
                    } else {
                        x = solve(r-1, c, x, can_fill);
                    }
                }
            }
        }
    
    } else {
        // fill right cols first
        int offset = 2;
        if (x % r == 0 || r == 2) {
            offset = 2;
        }
        int d = c-r;
        if (d == 0) d = 1;

        int filled_col = min(d, min(c - offset, x / r));
        if (DEBUG) printf("- filled_col: %d\n", filled_col);
        if (filled_col > 0) {
            x -= filled_col * r;
            for (int i=1;i<=filled_col;i++) {
                for (int j=0;j<r;j++) {
                    A[j][c-i] = '*';
                }
            }

            x = solve(r, c - filled_col, x, 0);
        } else {
        
            if (x > 0) {
                // try to fill last col
                int can_fill = min(x, r - 2);
                if (can_fill == 0 && c == 2) {
                    can_fill = 1;
                }
                if (last > 0 && can_fill > last) {
                    can_fill = last;
                }
                if (can_fill > 0) {
                    for (int i=1;i<=can_fill;i++) {
                        A[r-i][c-1] = '*';
                    }
                    x -= can_fill;
                    if (x > can_fill * (c-1)) {
                    } else {
                        x = solve(r, c-1, x, can_fill);
                    }
                }
            }
        }
    }
    if (DEBUG) printf("< solve %d %d remain %d\n", r, c, x);
    return x;
}

int dump() {
    //puts("------------");
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            printf("%c", A[i][j]);
        }
        puts("");
    }
}


int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        scanf("%d%d%d", &R, &C, &M);
        memset(A, '.', sizeof(A));
        A[0][0]='c';
        int remain = M;
        
        if (R == 1) {
            for (int i=1;i<=M;i++) {
                A[0][C-i] = '*';
            }
            remain = 0;
        } else if (C == 1) {
            for (int i=1;i<=M;i++) {
                A[R-i][0] = '*';
            }
            remain = 0;
        } else if ( M == R*C-1) {
            memset(A, '*', sizeof(A));
            A[0][0]='c';
            remain = 0;
        } else {
            remain = solve(R, C, M, 0);
        }

        if (DEBUG) {
            puts("-------------");
            printf("(%d %d) %d\n", R, C, M);
            dump();
            printf("remain: %d\n", remain);
        }


        printf("Case #%d:\n",ti);
        if (remain > 0) {
            printf("Impossible\n");
        } else {
            dump();
        }


    }
    return 0;
}

