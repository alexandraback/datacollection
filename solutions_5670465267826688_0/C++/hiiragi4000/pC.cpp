#include<stdio.h>
#include<string.h>
#include<algorithm>
#define I 2
#define J 3
#define K 4
#define N 120010
using namespace std;
typedef long long ll;

int c00[9][9];
int *c0[9];
int **c;

void init(){
    for(int i=0; i<=8; i++) c0[i] = c00[i] + 4;
    c = c0 + 4;
    c[1][1] = 1, c[1][I] = I, c[1][J] = J, c[1][K] = K;
    c[I][1] = I, c[I][I] =-1, c[I][J] = K, c[I][K] =-J;
    c[J][1] = J, c[J][I] =-K, c[J][J] =-1, c[J][K] = I;
    c[K][1] = K, c[K][I] = J, c[K][J] =-I, c[K][K] =-1;
    for(int i=1; i<=K; i++) for(int j=1; j<=K; j++){
        c[i][-j] = c[-i][j] = -c[i][j];
        c[-i][-j] = c[i][j];
    }
}
char s[N];

int main(){
    init();
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++){
        int n;
        long long m;
        scanf("%d%I64d%s", &n, &m, s);
        for(int i=0; i<=n-1; i++){
            if(s[i] == '1') s[i] = 1;
            else if(s[i] == 'i') s[i] = I;
            else if(s[i] == 'j') s[i] = J;
            else s[i] = K;
        }
        int p0 = 1;
        for(int i=0; i<=n-1; i++) p0 = c[p0][s[i]];
        int p = 1;
        for(int i=1; i<=m%4; i++) p = c[p][p0];
        if(p != -1){
            printf("Case #%d: NO\n", kase);
            continue;
        }
        m = min(m, 8 + m%4);
        for(int i=1; i<=m-1; i++) memcpy(s+i*n, s, n);
        n = m*n;
        int p1 = 1;
        bool yes = false;
        for(int i=0; i<=n-1; i++){
            p1 = c[p1][s[i]];
            if(p1 == I){
                int p2 = 1;
                for(int j=i+1; j<=n-1; j++){
                    p2 = c[p2][s[j]];
                    if(p2 == J){
                        yes = true;
                        break;
                    }
                }
                break;
            }
        }
        printf("Case #%d: %s\n", kase, yes ? "YES" : "NO");
    }
    return 0;
}
