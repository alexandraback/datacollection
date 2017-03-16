#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100000 + 10;
int a,b;
double p[MAXN];
double q[MAXN];

int main(){
    int T; scanf("%d",&T);
    for( int Case = 1; Case <= T; Case++ ){
        scanf("%d%d",&a,&b);
        for( int i = 0; i < a; i++ ) 
            scanf("%lf",p+i);
        
        q[0] = 1;
        for( int i = 0; i < a; i++ ){
            q[i+1] = q[i] * p[i];
        }
        
        double ans3 = 1 + (b+1);
        double ans = ans3;
        //printf("ans3=%.6lf\n",ans3);

        for( int x = 0; x <= a; x++ ){
            double tmp = (q[a-x])*(x+x+b-a+1) + (1-q[a-x])*(x+x+b-a+1+b+1);
            //printf("succ: %.6lf %d  succ: %.6lf %d\n",q[a-x],(x+x+b-a+1),1-q[a-x],x+x+b-a+1+b+1);

            //printf("ans x=%d  = %.6lf\n",x,tmp);
            ans = min(ans,tmp);
        }

        printf("Case #%d: %.6lf\n",Case,ans);
    }
    return 0;
}
