#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int n;
double a[MAX],b[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lf",&a[i]);
    FOR(i,1,n) scanf("%lf",&b[i]);
    sort(a+1,a+n+1,greater<double>());
    sort(b+1,b+n+1);
    //FOR(i,1,n) printf("%.5lf ",a[i]); printf("\n");
    //FOR(i,1,n) printf("%.5lf ",b[i]); printf("\n");
}
bool ok(int x) {
    if (x==0) return (true);
    vector<double> va,vb;
    FORD(i,x,1) va.push_back(a[i]);
    FOR(i,1,x) vb.push_back(b[i]);
    REP(i,x) if (va[i]<vb[i]) return (false);
    return (true);
}
int firstq(void) {
    FORD(i,n,0) if (ok(i)) return (i);
}
int secondq(void) {
    int ret=0;
    set<double> s;
    FOR(i,1,n) s.insert(b[i]);
    FOR(i,1,n) {
        set<double>::iterator it=s.upper_bound(a[i]);
        if (it==s.end()) {
            ret++;
            s.erase(s.begin());
        }
        else s.erase(it);
    }
    return (ret);
}
int main(void) {
#ifndef GCJ
    freopen("tmp.txt","r",stdin);
#endif
    int t;
    scanf("%d",&t);
    FOR(i,1,t) {
        init();
        printf("Case #%d: %d %d\n",i,firstq(),secondq());
    }
}
