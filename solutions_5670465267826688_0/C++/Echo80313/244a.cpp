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
string s;
char mul(char a,char b,bool& neg) {
    if(a=='1')return b;
    if(b=='1')return a;
    if(a==b){
        neg = !neg;
        return '1';
    }
    if(a=='i') {
        if(b=='j') {
            return 'k';
        }
        else if(b=='k') {
            neg = !neg;
            return 'j';
        }
    }
    if(a=='j') {
        if(b=='i') {
                neg = !neg;
            return 'k';
        }
        else if(b=='k') {
            //neg = !neg;
            return 'i';
        }
    }
    if(a=='k') {
        if(b=='i') {
            return 'j';
        }
        else if(b=='j') {
            neg = !neg;
            return 'i';
        }
    }
}
string w;
bool suf[11111];
int main(int argc, char const *argv[])
{

    //FIN("in.txt");
    FIN("C-small-attempt1.in");
    //FIN("B-large.in");
    //FIN("A-large.in");
    FOUT("out");
    //s[1] = 1;

    //OI(f(9,2));
    int t;
    RI(t);
    REP(kase,t) {
        RII(n,m);
        ZERO(suf);
        cin>>s;
        w = "";
        for(int i=0;i<m;++i)w+=s;
        char cf = '1';
        bool n3 = 0;
        for(int i=w.size()-1;i>=0;--i) {
            cf = mul(w[i],cf,n3);
            if(cf=='k'&&!n3)suf[i] = 1;
        }
        char cur = '1';
        bool n1 = 0;
        bool f = 0;
        for(int i=0;i<w.size()-2;++i) {
            cur = mul(cur,w[i],n1);
            //printf("%c %d\n",cur,n1);
            if(cur=='i' && !n1) {
                //OI(i);
                char cur2 = '1';
                bool n2 = 0;
                for(int j=i+1;j<w.size()-1;++j) {
                    cur2 = mul(cur2,w[j],n2);
                    if(cur2=='j'&&!n2) {
                        //OI(j);
                        if(suf[j+1])f = 1;
                    }
                }
            }
        }
        printf("Case #%d: ",kase+1);
        if(f)printf("YES\n");
        else printf("NO\n");
    }
}
