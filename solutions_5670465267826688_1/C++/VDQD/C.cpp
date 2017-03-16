#include <bits/stdc++.h>
using namespace std;

const int maxL = 10000 + 10;

int L;
long long X;
char s[maxL];
int val[256];
int d[8][8]; //-1,1,-i,i,-j,j,-k,k
int R[maxL];

void init(){
    //
    memset(val, 0, sizeof val);
    val['i'] = 3; val['j'] = 5; val['k'] = 7;
    for (int i = 0; i < 8; i++){
        if (i > 1){
            d[i][i] = 0; //-1
            d[i][i^1] = 1;
        }
        //
        d[0][i] = d[i][0] = i^1;
        d[1][i] = d[i][1] = i;
    }
    d[3][5] = d[2][4] = 7; d[2][5] = d[3][4] = 6; //i*j = k
    d[5][3] = d[4][2] = 6; d[5][2] = d[4][3] = 7; //j*i =-k
    d[3][7] = d[2][6] = 4; d[2][7] = d[3][6] = 5; //i*k =-j
    d[7][3] = d[6][2] = 5; d[7][2] = d[6][3] = 4; //k*i = j
    d[5][7] = d[4][6] = 3; d[4][7] = d[5][6] = 2; //j*k = i
    d[7][5] = d[6][4] = 2; d[7][4] = d[6][5] = 3; //k*j =-i
}

int getR(int i){
    if (i == L*X) return 1;
    long long p = (X - i/L - 1) % 4;
    int res = R[i%L];
    for (int i = 0; i < p; i++) res = d[res][R[0]];
    return res;
}

bool solve(){
    //InitR
    R[L] = 1;
    for (int i = L-1; i >= 0; i--) R[i] = d[val[s[i]]][R[i+1]];
    //findz
    //char Z[256]; Z[1] = '1'; Z[3] = 'i'; Z[5] = 'j'; Z[7] = 'k';
    //for (int i = L; i >= 0; i--){ if (R[i] % 2 == 0) printf("-");printf("%c\n", Z[(R[i]|1)]);}
    int si = 1, sj, sk;
    for (int i = 0; i < L*X && i < 4*L; i++){
        si = d[si][val[s[i%L]]];
        if (si == 3){ //i
            //printf("i = %d\n", i);
            sj = 1;
            for (int j = i + 1; j < L*X && j < 4*L + i; j++){
                sj = d[sj][val[s[j%L]]];
                if (sj == 5){
                    //printf("i = %d, j = %d\n", i, j);
                    sk = getR(j+1);
                    if (sk == 7) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    freopen("C-large.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int t, cases = 0; scanf("%d", &t);
    init();
    while (t--){
        scanf("%d%lld", &L, &X);
        scanf("%s", s);
        bool res = solve();
        printf("Case #%d: ", ++cases);
        if (res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
