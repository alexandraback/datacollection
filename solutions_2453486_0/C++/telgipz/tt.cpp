#include <cstdio>
#define BSIZE 4
using namespace std;

char b[10][10];

int counter=0, cx=0, ct=0, co=0;
int bsize2;
void clearc() {
    counter=0, cx=0, ct=0, co=0;
}

int count(char x) {

    
    //printf("%c ", x);
    if (x=='X') cx++;
    if (x=='O') co++;
    if (x=='T') ct++;
    
    if ((cx==3 && ct==1)||cx==4) {
        printf("X won\n");
        if (++counter==BSIZE) clearc();
        return 1;
    }

    if ((co==3 && ct==1)||co==4) {
        printf("O won\n");
        if (++counter==BSIZE) clearc();
        return 1;
    }
    if (++counter==BSIZE) clearc();
    return 0;
}

int chk_winner() {
    for (int i=0; i<bsize2; i++) if(count(b[i/BSIZE][i%BSIZE])) return 1;
    for (int i=0; i<bsize2; i++) if(count(b[i%BSIZE][i/BSIZE])) return 1;
    for (int i=0; i<BSIZE; i++) if(count(b[i][i])) return 1;
    for (int i=0; i<BSIZE; i++) if(count(b[i][BSIZE-1-i])) return 1;
    return 0;
}

int has_dot() {
    for (int i=0; i<BSIZE; i++) {
        for (int j=0; j<BSIZE; j++) {
            if (b[i][j]=='.') {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    bsize2=BSIZE*BSIZE;
    freopen("tt.in", "r", stdin);
    freopen("tt.out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    
    for (int test=1; test<=t; test++) {
        for (int i=0; i<BSIZE; i++) {
            scanf("%s", b[i]);
        }
        printf("Case #%d: ", test);
        if (!chk_winner()) {
            if (has_dot()) {
                printf("Game has not completed\n");
            }else printf("Draw\n");
        }
    }
    return 0;
}