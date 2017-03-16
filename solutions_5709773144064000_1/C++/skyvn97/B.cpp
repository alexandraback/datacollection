#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const int cnt=(int)3e6;
inline void minimize(double &x,const double &y) {
    if (x>y) x=y;
}
double process(void) {
    double c,f,x;
    double sum=0.0;
    cin>>c>>f>>x;
    double res=x/2.0;
    double spd=2.0;
    FOR(i,1,cnt) {
        sum+=c/spd;
        spd+=f;
        minimize(res,sum+x/spd);
    }
    return (res);
}
int main(void) {
#ifndef GCJ
    freopen("tmp.txt","r",stdin);
#endif
    int t;
    cin>>t;
    FOR(i,1,t) printf("Case #%d: %.9lf\n",i,process());
    return 0;
}
