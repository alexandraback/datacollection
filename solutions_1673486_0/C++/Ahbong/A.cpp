#include <cstdio>

int T, A, B;
double acc[100000], allacc[100000];

int main()
{
    scanf("%d", &T);
    for(int z=1; z<=T; ++z) {
        scanf("%d %d", &A, &B);
        for(int i=0; i<A; ++i) {
            scanf("%lf", &acc[i]);
        }
        allacc[0] = acc[0];
        for(int i=1; i<A; ++i) {
            allacc[i] = allacc[i-1] * acc[i];
        }
        double best = (B-A+1)*allacc[A-1] + (2*B-A+1)*(1.0-allacc[A-1]);
        for(int i=0; i<A; ++i) {
            double tmp;
            if(i>0) {
                tmp = (B+A-2*i+1)*allacc[i-1] + (2*B+A-2*i+2)*(1-allacc[i-1]);
            }
            else {
                tmp = B+A+1;
            }
            if(tmp<best) {
                best = tmp;
            }
        }
        double giveup = 2 + B;
        if(giveup<best) {
            best = giveup;
        }
        printf("Case #%d: %.6lf\n",z , best);
    }
    return 0;
}
