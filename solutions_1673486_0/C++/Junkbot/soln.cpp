#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;

int T;

int A, B;
double probCum[MAX_N];

int main() {
    scanf("%d",&T);

    for(int t=1;t<=T;t++) {
        probCum[0] = 1.0;

        scanf("%d %d",&A,&B);
        B++;

        for(int i=0;i<A;i++) {
            double temp;
            scanf("%lf",&temp);
            probCum[i+1] = probCum[i] * temp;
        }

        double best = min( probCum[A]*(B-A) + (1 - probCum[A]) * (B-A+B),
                           (double)B+1 );

        for(int i=0;i<=A;i++) {
            best = min(best, probCum[i]*(B-i + A-i) + (1 - probCum[i])*(A-i+B-i+B));
        }

        printf("Case #%d: %lf\n",t,best);
    }
    return 0;
}
