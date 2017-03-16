#include <cstdio>
#include <cstring>

using namespace std;

int T, C=1;
long double P[100010], p[100010];
int A, B;

#define min(a,b) (a < b ? a : b)

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d %d",&A,&B);
        P[0] = 1.0; //P = tdcerto
        for (int i=0;i<A;i++) {
            scanf("%Lf",p+i);
            P[i+1] = P[i]*p[i];
        }
        long double opc1, opc2, opc3;
        opc1 = opc2 = opc3 = 1e100;
        opc1 = P[A]*(B-A+1) + (1.0 - P[A])*(B-A+1+B+1);
        opc2 = 1.0*(1+B+1);

        for (int k=0;k<A;k++) {
            long double tt = P[k]*(A-k+B-k+1) + (1.0 - P[k])*(A-k+B-k+1+B+1);
//            printf("k=%d, tt = %Lf\n",k,tt);
            opc3 = min(tt,opc3);
        }

//        printf("opc1 = %Lf, opc2 = %Lf, opc3 = %Lf\n",opc1,opc2,opc3);
        long double resp = min(min(opc1,opc2),opc3);
        printf("%.6Lf\n",resp);

    }

    return 0;
}
