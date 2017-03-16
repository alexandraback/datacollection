#include <bits/stdc++.h>
using namespace std;

char a[55][55];

void runTest(){
    //init
    int r, c, m;
    scanf("%d%d%d", &r, &c, &m);
    //printf("%d %d %d\n", r, c, m);

    // M + 1 = R*C
    if (r * c == m + 1 || r == 1 || c == 1){
        //return;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (m > 0){
                    printf("*");
                    m--;
                }
                else if ( i == r-1 && j == c-1) printf("c");
                    else printf(".");
            }
            printf("\n");
        }
        return;
    }

    //A
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) a[i][j] = '.';
        a[i][c] = 0;
    }
    a[0][0] = 'c';

    int rr = r, cc = c, mm = m;
    while (mm >= cc || mm >= rr){
        if (rr > cc){
            rr--;
            for (int j = 0; j < cc; j++) a[rr][j] = '*';
            mm -= cc;
        }
        else{
            cc--;
            for (int i = 0; i < rr; i++) a[i][cc] = '*';
            mm -= rr;
        }
    }

    //printf("%d, %d, %d\n", rr, cc, mm);

    //
    bool ok = true;
    //
    if (mm > 0){
        if (rr <= 2 || cc <= 2) ok = false;
        else{
            for (int i = rr - 1; i >= 2 && mm > 0; i--) a[i][cc-1] = '*', mm--;
            for (int j = cc - 2; j >= 2 && mm > 0; j--) a[rr-1][j] = '*', mm--;
            if (mm > 0) ok = false;
        }
    }
    else{
        if (rr <= 1 || cc <= 1) ok = false;
    }

    if (ok){
        for (int i = 0; i < r; i++) printf("%s\n", a[i]);
        //printf("%d %d %d -> %d\n",r,c,m,mm);
    }
    else printf("Impossible\n");
}

int main(){
    freopen("C.inp","r",stdin);
    freopen("C.out","w",stdout);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++){
        printf("Case #%d:\n", i);
        fprintf(stderr, "Test %d\n", i);
        runTest();
    }
    return 0;
}
