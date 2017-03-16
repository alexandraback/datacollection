#include <cstdio>

int main() {
    int _t; scanf("%d", &_t);
    for(int _i=1; _i<=_t; _i++) {
        printf("Case #%d:\n", _i);
        int r, c, m; scanf("%d %d %d", &r, &c, &m);
        //printf("%d %d %d\n", r, c, m);
        bool solved = false;
        if(r == 1 and not solved) {
            if(m <= c-2) {
                printf("c");
                for(int i=0; i<c-m-1; i++) printf(".");
                for(int i=0; i<m; i++) printf("*");
                printf("\n");
                solved = true;
            }
        }
        if(c == 1 and not solved) {    
            if(m <= r-2) {
                printf("c\n");
                for(int i=0; i<r-m-1; i++) printf(".\n");
                for(int i=0; i<m; i++) printf("*\n");
                solved = true;
            }
        }
        if(r*c == m+1 and not solved) {
            printf("c");
            for(int i=1; i<c; i++) printf("*");
            printf("\n");
            for(int i=1; i<r; i++) {
                for(int j=0; j<c; j++) printf("*");
                printf("\n");
            }
            solved = true;
        }
        for(int i=2; i<=c; i++) { // How long the row of twos goes
            for(int j=0; j<=i; j++) if(j == 0 or j >= 2) { // How long the first block goes
                for(int k=2; k<=r; k++) { // How high the first block goes
                    for(int l=0; l<=j; l++) if(l == 0 or l >= 2) { // How long the second block goes
                        for(int p=k; p<=r; p++) { // How high the second block goes
                            if((i*2 + j*(k-2) + l*(p-k)) == (r*c-m) and not solved) {
                                printf("c");
                                for(int q=1; q<i; q++) printf(".");
                                for(int q=i; q<c; q++) printf("*");
                                printf("\n");
                                for(int q=0; q<i; q++) printf(".");
                                for(int q=i; q<c; q++) printf("*");
                                printf("\n");
                                for(int q=2; q<k; q++) {
                                    for(int s=0; s<j; s++) printf(".");
                                    for(int s=j; s<c; s++) printf("*");
                                    printf("\n");
                                }
                                for(int q=k; q<p; q++) {
                                    for(int s=0; s<l; s++) printf(".");
                                    for(int s=l; s<c; s++) printf("*");
                                    printf("\n");
                                }
                                for(int q=p; q<r; q++) {
                                    for(int s=0; s<c; s++) printf("*");
                                    printf("\n");
                                }
                                solved = true;
                            }
                        }
                    }
                }
            }
        }
        if(not solved) printf("Impossible\n");
    }
}
