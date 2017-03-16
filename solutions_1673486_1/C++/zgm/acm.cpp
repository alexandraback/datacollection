#include<cstdio>
#include<cmath>
#include<cstring>
#include<time.h>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    int T, A, B; double p[100000];
    scanf("%d",&T);
    for(int cs=1; cs<=T; cs++){
        scanf("%d%d",&A,&B);
        for(int i=0; i<A; i++) scanf("%lf",&p[i]);
        double exp = B+2, pp = 1;
        for(int i=0; i<A; i++){
            double s = (A-i+B-i+1)*pp+(A-i+B-i+1+B+1)*(1-pp);
            //printf("%.6f\n",s);
            exp = min( exp, s );
            pp *= p[i];
        }
        //printf("%.6f\n",(B-A+1)*pp+(B-A+1+B+1)*(1-pp));
        exp = min( exp, (B-A+1)*pp+(B-A+1+B+1)*(1-pp) );
        printf("Case #%d: %.6f\n",cs,exp);
    }
    return 0;
}
