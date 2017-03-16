#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int kasus,r,c,m;
char jawab[55][55];

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d %d %d",&r,&c,&m);
        printf("Case #%d:\n",l);
        
        if (r == 1) {
            for (int i=1;i<=m;++i) printf("*");
            for (int i=1;i<c-m;++i) printf(".");
            printf("c\n");
        } else if (c == 1) { 
            for (int i=1;i<=m;++i) printf("*\n");
            for (int i=1;i<r-m;++i) printf(".\n");
            printf("c\n");
        } else if (c == 2) {
            if ((m % 2 && m != r*c-1) || (m == r*c-2)) {
                printf("Impossible\n");
            } else {
                for (int i=0;i<r-1;++i) {
                    if (m) {
                        m -= 2;
                        printf("**\n");
                    } else {
                        printf("..\n");
                    }
                }
                
                if (m) printf("*c\n");
                else printf(".c\n");
            }
        } else if (r == 2) {
            if ((m % 2 && m != r*c-1) || (m == r*c-2)) {
                printf("Impossible\n");
            } else {
                for (int i=0;i<c-1;++i) {
                    if (m) {
                        m -= 2;
                        jawab[0][i] = jawab[1][i] = '*';
                    } else {
                        jawab[0][i] = jawab[1][i] = '.';
                    }
                }
                
                if (m) jawab[0][c-1] = '*';
                else jawab[0][c-1] = '.';
                jawab[1][c-1] = 'c';
                
                for (int i=0;i<r;++i) {
                    for (int j=0;j<c;++j) printf("%c",jawab[i][j]);
                    printf("\n");
                }
            }        
        } else {
            memset(jawab,'.',sizeof(jawab));
            jawab[r-1][c-1] = 'c';
            for (int i=0;i<r-2 && m;++i) {
                for (int j=0;j<c-2 && m;++j) {
                    if (m) {
                        --m;
                        jawab[i][j] = '*';
                    }
                }
            }
            
            if (m <= 2*(r+c-6)) {
                if (m % 2) {
                    jawab[r-3][c-3] = '.';
                    ++m;
                }
                
                for (int i=0;i<r-3 && m;++i) {
                    m -= 2;
                    jawab[i][c-2] = jawab[i][c-1] = '*';
                }
                
                for (int j=0;j<c-3 && m;++j) {
                    m -= 2;
                    jawab[r-2][j] = jawab[r-1][j] = '*';
                }
            } else {
                m -= 2*(r+c-6);
                for (int i=0;i<r-3;++i) {
                    jawab[i][c-2] = jawab[i][c-1] = '*';
                }
                
                for (int j=0;j<c-3;++j) {
                    jawab[r-2][j] = jawab[r-1][j] = '*';
                }

                //kanan bawah harusnya seperti ini
                //*..
                //...
                //..c
                
                if (m == 7) {
                    for (int i=r-3;i<r;++i) {
                        for (int j=c-3;j<c;++j) {
                            if (jawab[i][j] == '.') jawab[i][j] = '*';
                        }
                    }
                } else if (m == 2) {
                    jawab[r-2][c-3] = jawab[r-1][c-3] = '*';
                } else if (m == 4) {
                    jawab[r-2][c-3] = jawab[r-1][c-3] = '*';
                    jawab[r-3][c-2] = jawab[r-3][c-1] = '*';
                } else {
                    printf("Impossible\n");
                    continue;
                }
            }
            
            for (int i=0;i<r;++i) {
                for (int j=0;j<c;++j) printf("%c",jawab[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
