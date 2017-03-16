/**
 * @author: Ruben S. Andrist
 * @version: 0.1
 * @date: 2014-04-11
 * Contact: lasrach[at]gmail.com
 */

#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int cases = 0;
    scanf(" %d", &cases);
    for (int caseno = 1; caseno <= cases; caseno++) {
        printf("Case #%d:\n", caseno);

        int R, C, M;
        scanf(" %d %d %d", &R, &C, &M);

        // impossible number of mines
        if (M >= R*C) {
            printf("Impossible\n");
            continue;
        }

        // special case all but one mined
        if (M == R*C-1) {
            for (int i=0; i<R; i++) {
                for (int j=0; j<C; j++) {
                    printf((i==0&&j==0)?"c":"*");
                }
                printf("\n");
            }
            continue;
        }

        // special case one row
        if (R == 1) {
            printf("c");
            for (int j=1; j<C; j++) {
                printf((j<C-M)?".":"*");
            }
            printf("\n");
            continue;
        }

        // special case one column
        if (C == 1) {
            printf("c\n");
            for (int i=1; i<R; i++) {
                printf((i<R-M)?".\n":"*\n");
            }
            continue;
        }

        // things that do not work
        int spaces = R*C-M;
        //printf("SPACES = %d\n", spaces);

        if (spaces < 4 || spaces==5 || spaces==7) {
            printf("Impossible\n");
            continue;
        }
        if ((R==2||C==2) && (spaces%2==1)) {
            printf("Impossible\n");
            continue;
        }

        // special case two rows
        if (R == 2) {
            printf("c");
            for (int j=1; j<C; j++) {
                printf((j<spaces/2)?".":"*");
            }
            printf("\n");
            for (int j=0; j<C; j++) {
                printf((j<spaces/2)?".":"*");
            }
            printf("\n");
            continue;
        }

        // special case two columns
        if (C == 2) {
            printf("c.\n");
            for (int i=1; i<R; i++) {
                printf((i<spaces/2)?"..\n":"**\n");
            }
            continue;
        }

        // special case 4, 6
        if (spaces==4 || spaces==6) {
            for (int i=0; i<R; i++) {
                for (int j=0; j<C; j++) {
                    if (i==0 && j==0) {
                        printf("c");
                    }else if (i<2 && j<spaces/2) {
                        printf(".");
                    }else{
                        printf("*");
                    }
                }
                printf("\n");
            }
            continue;
        }

        // generic case (more than two rows and cols)
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (i==0 && j==0) {
                    printf("c");
                }else if (i==2 && j==2){
                    printf((spaces>(R+C)*2-4||(spaces%2==1))?".":"*");
                }else if (i<3 && j<3) {
                    printf(".");
                }else if (i<2) {
                    printf((j<(spaces-2)/2)?".":"*");
                }else if (j<2){
                    printf((i<(spaces-2*(C-2))/2)?".":"*");
                }else{
                    printf(((i-2)*(C-2)+(j-2)<spaces-2*C-2*R+4)?".":"*");
                }
            }
            printf("\n");
        }

    }
    return 0;
}

// vim: set ff=unix ai tw=80 ts=4 sts=4 sw=4 et:
