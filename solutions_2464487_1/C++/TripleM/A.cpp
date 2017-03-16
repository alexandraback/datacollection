#include <iostream>
using namespace std;
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        long long R,K; scanf("%I64d %I64d",&R,&K);
        
        long long low = 1, high = 2000000000000000001LL;
        
        // [low,high)
        while (high-low>1) {
            long long N = low + (high-low)/2;
            
            //printf("To paint %I64d rings we need %I64d\n",N,2*N*N+(2*R-1)*N);
            // can we paint N rings?
            // need 2n^2 + (2r-1)n <= K
            
            // 2n + (2r-1) <= K/n
            
            long long rhs = K/N;
            rhs -= 2*N;
            rhs>?=-1;
            rhs -= (2*R-1);
            rhs>?=-1;
            if (rhs>=0) {
                low = N;
            } else {
                high = N;
            }
        }
        printf("Case #%d: %I64d\n",t,low); 
    }
}
