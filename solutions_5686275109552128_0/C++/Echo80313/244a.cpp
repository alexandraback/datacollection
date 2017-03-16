#include<bits/stdc++.h>
#define REP(i,n) for(int (i)=0;i<(int)(n);++(i))
#define REPIT(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PB push_back
#define FT first
#define SD second
#define ZERO(x) memset(x,0,sizeof(x))
#define NEG(x) memset(x,-1,sizeof(x))
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d%d",&(x),&(y))
#define RIII(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define OIII(x,y,z) printf("%d %d %d\n",(x),(y),(z))
#define OII(x,y) printf("%d %d\n",(x),(y))
#define OI(x) printf("%d\n",(x))
#define OL(x) cout<<(x)<<endl
#define OLL(x,y) cout<<(x)<<" "<<(y)<<endl
#define OLLL(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define RS(s) scanf("%s",(s))
#define MP(x,y) make_pair((x),(y))
#define FIN(f) freopen(f,"r",stdin)
#define FOUT(f) freopen(f,"w",stdout)
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> PII;
const int MOD = 1e9+7;
const int maxn =  25111;
const int INF = 1<<30;
int n,m;
int a[1111];
int cnt[1111];
int s[1111][1111];

int main(int argc, char const *argv[])
{

    //FIN("in.txt");
    FIN("B-small-attempt7.in");
    //FIN("A-large.in");
    FOUT("out");
    //s[1] = 1;

    //OI(f(9,2));
    int t;
    RI(t);
    REP(kase,t) {
        //ZERO(cnt);
        RI(n);
        REP(i,n)RI(a[i]);
        int ans = 0;
        //int cc = 0;
        REP(i,n)ans = max(ans,a[i]);
        int ma = ans;
        for(int tar = 1;tar<=ma;++tar) {
            int cc = 0;
            for(int i=0;i<n;++i) {
                cc+=a[i]/tar - (a[i]%tar==0?1:0);
            }
            //OI(cc+tar);
            ans = min(ans,cc+tar);
        }

        printf("Case #%d: %d\n",kase+1,ans);
    }
}
