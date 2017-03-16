#include <vector>
using namespace std;

int r, c, m;
char res[100][100];

int isBlank(int i1 , int j1, int i2, int j2) {
    if (i1<r && j1<c && i2<r && j2<c) {
        if (res[i1][j1]=='.' && res[i2][j2]=='.')
            return 1;
    }
    return 0;
}
int isNot(int i1, int j1, int i2, int j2) {
    if (i1<r && j1<c && i2<r && j2<c) {
        if (res[i1][j1]==0 && res[i2][j2]==0)
            return 1;
    }
    return 0;
}

int main() {
    int t;

    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    fscanf(in, "%d", &t);
    for (int l=1; l<=t; l++) {
        fill(res[0], res[0]+100*100, 0);

        fscanf(in, "%d %d %d", &r, &c, &m);
        fprintf(out, "Case #%d:\n", l);
        if (r==1 && c==1) {
            res[0][0] = 'c';
        } else if ((r==1 && c>1) || (r>1 && c==1)) {
            int blank = r*c-m;
            for (int i=0; i<r; i++) {
                for (int j=0; j<c; j++) {
                    blank>0?res[i][j] = '.':res[i][j] = '*';
                    blank--;
                }
            }
            res[0][0] = 'c';
        } else {
            int blank = r*c-m;
            if ((r==2 || c==2) && blank>1 && blank%2==1) {
                fprintf(out, "Impossible\n");
                continue;
            } else {
                int blank = r*c - m;
                if (blank==1) {
                    for (int i=0; i<r; i++) {
                        for (int j=0; j<c; j++) {
                            res[i][j] = '*';
                        }
                    }
                    res[0][0] = 'c';
                } else if (blank==2 || blank==3 || blank==5 || blank==7) {
                    fprintf(out, "Impossible\n");
                    continue;
                } else {                   
                    if (blank%2==0) {
                        res[0][0] = res[0][1] = res[1][0] = res[1][1] = '.';
                        blank -= 4;
                    } else {
                        res[0][0] = res[0][1] = res[0][2] = '.';
                        res[1][0] = res[1][1] = res[1][2] = '.';
                        res[2][0] = res[2][1] = res[2][2] = '.';
                        blank -= 9;
                    }
                    int did;
                    do {
                        did = 0;
                        for (int i=0; i<r; i++) {
                            for (int j=0; j<c; j++) {
                               
                                if (blank == 0) {
                                    if (res[i][j] == 0) {
                                        res[i][j] = '*';
                                    }
                                } else {
                                    if (isBlank(i, j, i, j+1) && isNot(i+1, j, i+1, j+1)) {
                                        res[i+1][j] = res[i+1][j+1] = '.';
                                        blank -= 2;
                                        did = 1;
                                    }
                                    if (isBlank(i, j, i+1, j) && isNot(i, j+1, i+1, j+1)) {
                                        res[i][j+1] = res[i+1][j+1] = '.';
                                        blank -= 2;
                                        did = 1;
                                    }
                                }
                            }
                        }
                    } while(did);
                    if (blank && blank!=2) {
                        fprintf(out, "zzzzzzzzzzzzzzzzzzzzzzzzzz\n");
                    }
                    if (blank) {
                        res[r-1][c-2] = res[r-2][c-1] = '.';
                        res[r-1][c-1] = '*';
                        blank = 0;
                    }
                    if ((r*c-m)%2==0)
                        res[0][0] = 'c';
                    else
                        res[1][1] = 'c';
                }
            }
        }
        int cnt = 0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (res[i][j]!='*' && res[i][j]!='.' && res[i][j]!='c')
                    fprintf(out, "laksdjflsajflkjfkljdfklasjflkasjfklsfjasklfjasklfjk\n");
                if (res[i][j]=='*') cnt++;
                fprintf(out, "%c", res[i][j]);
            }
            fprintf(out, "\n");
        }
        if (cnt != m)
            printf("%d, %d: %d\n", cnt, m, l);
    }
    return 0;
}
