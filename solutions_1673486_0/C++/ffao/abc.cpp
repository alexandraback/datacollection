#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
 
int A, B, T;
int teste = 0;

double prob[100000];

int main() {
    for (scanf("%d", &T); T; --T) {
        printf("Case #%d: ", ++teste);
        
        scanf("%d %d", &A, &B);
        double all = 1;
        for (int i = 0; i < A; i++) {
            scanf("%lf", &prob[i]);
            all *= prob[i];
        }
        
        double best = B+2;
        
        for (int dec = 0; dec <= A; dec++) {
            double ex = all*(2*dec+B-A+1) + (1-all)*(2*dec+B-A+B+2);
            //printf("exp: %lf\n",ex);
            best = min(best,ex);
            if (dec != A) all /= prob[A-1-dec];
        }
        
        printf("%lf\n", best);
        
    }
}
