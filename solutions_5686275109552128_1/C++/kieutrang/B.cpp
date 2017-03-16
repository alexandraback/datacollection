#include<cstdio>
#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<cstring>
#include<ctime>
#include<map>
#define REP(i,N) for(int i=0;i<N;i++)
#define foru(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define ford(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define inp(a,n) cin >> n; REP(i,n) cin >> a[i]
#define inp2(x,y,n) cin >> n; REP(i,n) cin >> x[i] >> y[i]
#define out(a,n) REP(i,n) cout << a[i] << ' '
#define read freopen("","r",stdin)
#define write freopen("","w",stdout)
#define fi first
#define se second
#define sz size()
#define pb push_back
#define pf push_front
#define ins insert
#define be begin()
#define en end()
#define iall begin(),end()
#define sqr(a) (a)*(a)
#define setp(x) cout.precision(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const float eps=1e-8;
const ll lloo=1e18;
const int oo=1e9;
int D;
int p[1000];
int get(int x, int y) {
    if (x%y==0) return x/y;
    return x/y+1;
}
int solve(int x) {
    int sum=0;
    REP(i,D) if (p[i]>x) sum+=get(p[i]-x,x);
    return sum;
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("result.out","w",stdout);
    int T;
    cin >> T;
    foru(test,1,T) {
        cin >> D;
        int smax=0;
        REP(i,D) {
            cin >> p[i];
            smax=max(smax,p[i]);
        }
        int res=smax;
        REP(sp,smax+1) {
            int l=1;
            int r=smax;
            while (l+1<r) {
                int mid=(l+r)/2;
                if (solve(mid)<=sp) r=mid;
                else l=mid+1;
            }
            int pres;
            if (solve(l)<=sp) pres=l;
            else pres=r;
            res=min(res,pres+sp);
        }
        cout << "Case #" << test << ": " << res << endl;
    }
}
