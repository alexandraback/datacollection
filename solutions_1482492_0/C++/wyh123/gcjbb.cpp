#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>

using namespace std;

#define eps 1e-8
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define fi first
#define se second
typedef pair<double, double> pdd;
typedef vector<pdd> vp;
#define mp make_pair
#define pb push_back

double d;
int n,a;
vp v;

double solve(double ans, double s){
    double ss,tt,ds,dt,dv,tmp;
    ds=v[1].se-v[0].se;
    dt=v[1].fi-v[0].fi;
    dv=ds/dt;
    tmp=2*dv+sqrt(4*dv*dv+8*s*v[0].se);
    tmp/=(2*s);
    if(tmp>ans) return ans;
    ss=v[0].se +dv*tmp;
    tt=(d-ss)/dv;
    double now=tmp+tt;
    return now;
}

int main(){
    int T;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    cin >> T;
    for (int cas=1; cas<=T; cas++) {
        cin >> d >> n >> a;
        v=vp(n);
        for(int i = 0; i < n; i++)
            cin>>v[i].fi>>v[i].se;
        cout << "Case #" << cas << ":" << endl;
        double s;
        for(int i=0; i<a; i++){
            cin >> s;
            double ans=2*d/s;
            ans=sqrt(ans);
            if(n==1) printf("%.10lf\n",ans);
                else
                    if(n==2){
                        ans=solve(ans, s);
                        printf("%.10lf\n",ans);
                    }
        }
    }
    return 0;
}


