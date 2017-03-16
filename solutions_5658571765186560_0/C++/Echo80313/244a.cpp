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
int x,r,c;

int main(int argc, char const *argv[])
{

    //FIN("in.txt");
    FIN("D-small-attempt2.in");
    //FIN("B-large.in");
    //FIN("A-large.in");
    FOUT("out");
    //s[1] = 1;

    //OI(f(9,2));
    int t;
    RI(t);
    REP(kase,t) {
        RIII(x,r,c);
        bool f = 0;
        if(x==1) {
            f = 1;
        } else if(x==2){
            f = (r*c)%2==0;
        }
         else if(x==3) {
            if(max(r,c) < x || min(r,c) < (x+1)/2 ||(r*c)%x != 0){
                    f = 0;
            }
            else f = 1;
        } else if(x==4){
            if(max(r,c) < x || min(r,c) < (x+1)/2 ||(r*c)%x != 0||min(r,c)<3){
                    f = 0;
            }
            else f = 1;
        }else {
            if(x>=7)f = 0;
        }
        printf("Case #%d: ",kase+1);
        if(f)printf("GABRIEL\n");
        else printf("RICHARD\n");
    }
}
