#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

const int Max = 128;

int F[Max][128];

int getSur(int x){
    if (x >= 2 && (x - 2) % 3 == 0)
        return (x - 2) / 3 + 2;
    if (x >= 3 && (x - 3) % 3 == 0)
        return (x - 3) / 3 + 2;
    if (x >= 4 && (x - 4) % 3 == 0)
        return (x - 4) / 3 + 2;
    return -1;
}
int normal(int x){
    if (x >= 1 && (x - 1) % 3 == 0)
        return (x - 1) / 3 + 1;
    if (x >= 2 && (x - 2) % 3 == 0)
        return (x - 2) / 3 + 1;
    if (x % 3 == 0)
        return x / 3;
    return -1;
}

int main(){
    freopen("W:\\B-small-attempt0.in","r",stdin);
    freopen("W:\\B-small-attempt0.out","w",stdout);
    int tCase;
    scanf("%d",&tCase);
    for (int ct = 1;ct <= tCase;ct++){
        int N,S,p;
        scanf("%d%d%d",&N,&S,&p);
        memset(F,0,sizeof(F));
        for (int i = 1;i <= N;i++){
            int x;
            scanf("%d",&x);
            int f = getSur(x);
            int g = normal(x);
            if (g > -1){
                int d = g >= p;
                for (int j = 0;j <= S;j++)
                    F[i][j] = max(F[i][j],F[i - 1][j] + d);
            }
            if (f > -1){
                int d = f >= p;
                for (int j = 1;j <= S;j++)
                    F[i][j] = max(F[i][j],F[i - 1][j - 1] + d);
            }
            for (int j = 1;j <= S;j++)
                F[i][j] = max(F[i][j],F[i][j - 1]);
        }
        printf("Case #%d: %d\n",ct,F[N][S]);
    }
    return 0;
}
