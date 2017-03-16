#include <cstdio>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
typedef double db;

const int MaxL = 100010;

db P[MaxL],F[MaxL];

int main(){
    freopen("W:\\A-small-attempt0.in","r",stdin);
    freopen("W:\\A-small-attempt0.out","w",stdout);
    int tCase;
    scanf("%d",&tCase);
    for (int ct = 1;ct <= tCase;ct++){
        int A,B;
        scanf("%d%d",&A,&B);
        F[0] = 1.0;
        for (int i = 1;i <= A;i++){
            scanf("%lf",&P[i]);
            F[i] = F[i - 1] * P[i];
        }
        db Res = 1 + B + 1;
        for (int i = A;i >= 0;i--){
            db cr = (A - i) + (B - i) + 1 + (1 - F[i]) * (B + 1);
            //printf("%d : %f| %d %d %f\n",i,cr,(A - i) + (B - i) + 1,B + 1,F[i]);
            Res = min(cr,Res);
        }
        printf("Case #%d: %.6f\n",ct,Res);
    }
    return 0;
}
