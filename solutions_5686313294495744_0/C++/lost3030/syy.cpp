#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
//const ll INF=(_I64_MAX)/2;
//#pragma comment(linker, "/STACK:102400000,102400000")
const int inf = 0x3f3f3f3f;
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define minn(a) memset(a, 0xC0, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define FILL(a,b) memset(a, b, sizeof(a))
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
#define fi first
#define se second
typedef pair <int, int> PII;
typedef pair <ll , ll > PX ;

int n;
string a[22],b[22];

void work() {
    cin>>n;
    int i,j;
    rep(i,n) {
        cin>>a[i]>>b[i];
    }
    int ans = 0;

    rep(i,(1<<n)) {
        map<string,int> x;
        map<string,int> y;
        rep(j,n) {
            if(i&(1<<j)) {
                x[a[j]] = 1;
                y[b[j]] = 1;
            }
        }
        bool fag = 1;
        int zz = 0;
        rep(j,n) {

            if(!(i&(1<<j))) {
                if(a[j] == b[j]) fag = 0;
                if(x[a[j]] != 1 || y[b[j]] != 1) fag = 0;
                zz++;
            }
        }
        if (fag) {
            ans = max(ans,zz);
        }

    }
    cout<<ans<<endl;

}

int main() {
#ifdef LOCAL
    freopen( "in.txt", "r" , stdin);
 freopen ("out.txt","w",stdout );
#endif



    int T,cas=1;
    cin>>T;
    while(T--) {
        printf("Case #%d: ",cas++);
        work();
    }



    return 0;
}



