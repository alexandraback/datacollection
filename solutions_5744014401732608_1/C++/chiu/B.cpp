#include<cstdio>


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    long long mx[51] = {0};
    mx[1] = 1;
    mx[2] = 1;

    for(int i=3; i<51; i++) {
        mx[i] = mx[i-1] * 2;
    }
    for(int ca=1; ca<=T; ca++) {
        int b, mat[50][50] = {{0}};
        long long m;
        scanf("%d%lld", &b, &m);
        printf("Case #%d: ", ca);
        if(m > mx[b]) {
            puts("IMPOSSIBLE");
            continue;
        }else
            puts("POSSIBLE");
        int i;
        for(i=2; m > mx[i]; i++) {
            for(int j=0; j<i-1; j++)
                mat[i-1][j] = 1;
        }
        int df = mx[i] - m;
        //printf("%d\n\n", df);
        if(!df) {
            for(int j=0; j<i-1; j++)
                mat[b-1][j] = 1;
        }
        while(~i) {
            i--;
            if(df < mx[i])
                mat[b-1][i-1] = 1;
            else
                df -= mx[i];
        }
        for(int i=b-1; ~i; i--) {
            for(int j=b-1; ~j; j--)
                printf("%d", mat[i][j]);
            puts("");
        }

    }

    return 0;
}
