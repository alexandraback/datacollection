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
int c[1111];
char s[1111];
int main(int argc, char const *argv[])
{

    //FIN("in.txt");
    //FIN("A-small-attempt0.in");
    FIN("A-large.in");
    FOUT("out");
    int t;
    RI(t);
    REP(kase,t) {
        RI(n);
        RS(s);
        REP(i,n+1) {
            c[i] = s[i] - '0';
        }
        int cur = c[0];
        int ans = 0;
        for(int i=1;i<=n;++i) {
            if(cur < i) {
                ans += i-cur;
                cur = i;
            }
            cur+= c[i];
            //ans += c[i];
        }
        printf("Case #%d: %d\n",kase+1,ans);
    }
}
