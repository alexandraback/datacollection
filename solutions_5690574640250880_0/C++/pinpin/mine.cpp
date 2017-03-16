#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

bool is_possible(int R, int C, int M)
{
    if (M == 0) {
        return true;
    } else if (M == (R*C-1)) {
        return true;
    } else if (R == 1) {
        return (M <= (C-2));
    } else if (R == 2) {
        return ((M <= (R*C-4)) && ((M % 2) == 0));
    } else if (C == 1) {
        return (M <= (R-2));
    } else if (C == 2) {
        return ((M <= (R*C-4)) && ((M % 2) == 0));
    } else {
        int n_m = (R*C - M);

        if (n_m <= 3 || (n_m == 5) || (n_m == 7))
            return false;
        return true;
    }
}

int print_sol_sol(int R, int C, int RR, int CC)
{
    int i, j;
    int cnt = 0;

    for(i=0;i<R;i++) {
        for(j=0;j<C;j++) {
            printf("%c", ((i == 0) && (j == 0)) ? 'c' :
                         ((i < RR) && (j < CC)) ? '.' : '*'); 
            if (((i == 0) && (j == 0)) || ((i < RR) && (j < CC))) {
            } else {
                cnt++;
            }
        }
        printf("\n");
    }
    return cnt;
}

void print_sol(int R, int C, int M)
{
    int i, j;

    if (M == 0) {
        assert(print_sol_sol(R, C, R, C) == M);
    } else if (M == (R*C-1)) {
        assert(print_sol_sol(R, C, 1, 1) == M);
    } else if (R == 1) {
        assert(print_sol_sol(R, C, R, C-M) == M);
    } else if (R == 2) {
        assert(print_sol_sol(R, C, 2, C-M/2) == M);
    } else if (C == 1) {
        assert(print_sol_sol(R, C, R-M, C) == M);
    } else if (C == 2) {
        assert(print_sol_sol(R, C, R-M/2, 2) == M);
    } else {
        int n_m = R*C - M;

        if (n_m == 4) {
            assert(print_sol_sol(R, C, 2, 2) == M);
        } else if (n_m == 6) {
            assert(print_sol_sol(R, C, 2, 3) == M);
        } else if (n_m == 9) {
            assert(print_sol_sol(R, C, 3, 3) == M);
        } else if ((n_m == 8) && (R >= 4)) {
            assert(print_sol_sol(R, C, 4, 2) == M);
        } else if ((n_m == 8) && (C >= 4)) {
            assert(print_sol_sol(R, C, 2, 4) == M);
        } else if (((n_m % C) != 1) && (C*2 <= n_m)) {
            for(i=0;i<R;i++) {
                for(j=0;j<C;j++) {
                    printf("%c", ((i == 0) && (j == 0)) ? 'c' :
                                 ((i*C+j)  < n_m) ? '.' : '*'); 
                }
                printf("\n");
            }
        } else if (((n_m % R) != 1) && (R*2 <= n_m)) {
            for(i=0;i<R;i++) {
                for(j=0;j<C;j++) {
                    printf("%c", ((i == 0) && (j == 0)) ? 'c' :
                                 ((j*R+i)  < n_m) ? '.' : '*'); 
                }
                printf("\n");
            }
        } else if ((C > 3) && ((n_m % C) == 1) && (C*3 <= n_m)) {
            for(i=0;i<R;i++) {
                for(j=0;j<C;j++) {
                    printf("%c", ((i == 0) && (j == 0)) ? 'c' :
                                 (i <  (n_m/C-1)) ? '.' :
                           ((i == (n_m/C-1)) && (j != (C-1))) ? '.' :
                           ((i == (n_m/C)) && (j < 2)) ? '.' : '*'); 
                }
                printf("\n");
            }
        } else if ((M == 3)  && (R >= 4) && (C >= 4)) {
            for(i=0;i<R;i++) {
                for(j=0;j<C;j++) {
                    printf("%c", ((i == 0) && (j == 0)) ? 'c' :
                                 ((i == (R-1)) && (j == (C-2))) ? '*' :
                                 ((i == (R-2)) && (j == (C-1))) ? '*' :
                                 ((i == (R-1)) && (j == (C-1))) ? '*' : '.');
                }
                printf("\n");
            }
        } else {
            int CC;
            bool flg = false;

            CC = C - 1;
            while ((CC >= 2) && (n_m/CC <= R)) {
                if (((n_m % CC) != 1) && (n_m/CC >= 2)) {
                    flg = true;
                    for(i=0;i<R;i++) {
                        for(j=0;j<C;j++) {
                            printf("%c", ((i == 0) && (j == 0)) ? 'c' :
                                         ((j < CC) && ((CC*i+j) < n_m)) ? '.' : '*');
                        }
                        printf("\n");
                    }
                    break;
                }
                CC--;
            }
            if (!flg) {
                printf("here\n");
            }
        }
    }
}

int
main(void)
{
    int T;
    int t, i, j, n;
    int R, C, M;
    
    cin >> T;

    for(t=1;t<=T;t++) {
        cin >> R >> C >> M;

        //         printf("%d,%d,%d\n", R,C,M);

        printf("Case #%d:\n", t);

        if (is_possible(R, C, M)) {
            print_sol(R, C, M);
        } else {
            printf("Impossible\n");
        }
    }
    
    return 0;
}
