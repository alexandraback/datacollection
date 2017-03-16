#include <iostream>
using namespace std;
double probs[100000];
double cor[100000];
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        int A,B; scanf("%d %d",&A,&B);
        for (int i=0; i<A; i++) scanf("%lf",&probs[i]);
        
        double ans = 1 + B + 1; // enter, type all
        
        cor[0] = 1;
        for (int i=1; i<=A; i++) {
            cor[i] = cor[i-1] * probs[i-1];
        }
        for (int i=0; i<=A; i++) {
            // delete i characters, type rest
            // what is probability first A-i characters are right?
            double here = cor[A-i] * (i + B-(A-i) + 1) + (1-cor[A-i])*(i + B-(A-i) + 1 + B+1);
            
            ans<?=here;
        }
        
        printf("Case #%d: %f\n",t,ans);
    } 
}
