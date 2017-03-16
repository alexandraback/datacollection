#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXFARMS = 1e7+10;

int main() {
    int t=1,T;
    for(scanf("%d",&T);t<=T;++t) {
        double C,F,X;
        scanf("%lf%lf%lf",&C,&F,&X);
        double best = LINF;
        double acc = 0;
        double CPS = 2;        
        for(int nFarms=0;nFarms<=MAXFARMS;++nFarms) {
            double time = acc;
            time += X / CPS;
            acc += C / CPS;
            CPS += F;
            best = min(best, time);
        }
        printf("Case #%d: %.7f\n",t,best);
    }        
    return 0;
}
