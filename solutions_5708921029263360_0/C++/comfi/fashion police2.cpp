
#include <bits/stdc++.h>
using namespace std;

#define inf (1<<30)-1
#define INF (1LL<<62)-1
#define MOD 1000000007LL
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define PI acos(-1)
#define MEM(x,y) memset(x,y,sizeof (x))
#define debug cout<<"A"<<'\n'
#define REP(i,a,b) for (int i=(a); i<=(b); i++)
#define PER(i,a,b) for (int i=(a); i>=(b); i--)
#define REPL(i,a,b) for (LL i=(a); i<=(b); i++)
#define PERL(i,a,b) for (LL i=(a); i>=(b); i--)
#define print(x) cout<<x<<'\n'
#define dprint(a,x) cout<<setprecision(x)<<fixed<<a<<'\n'
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int>PII;
typedef pair<LL,LL>PLL;
typedef set<int> SI;
typedef set<LL> SL;
typedef set<string> SS;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef map<LL,LL> MLL;
typedef queue<int> QI;

/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

template <class T> inline T bigmod(T p,T e,T M)
{
    T ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T, class X> inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0);}
template <class T, class X> inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template <class T, class X> inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i)));}

inline LL power(LL a, LL b)
{
	LL multiply=1;
	REP(i,1,b)
	{
		multiply*=a;
	}
	return multiply;
}
inline LL ABS(LL a){return (a>=0)?a:-a;}

/*end of header*/
struct triple
{
    int a,b,c;
}d;
int main()
{
    freopen("fashionsmall.in","r",stdin);
    freopen("fashionsmall.out","w",stdout);
    int t=0,T,j,p,s,k,flag;
    vector<triple>cloth;
    map<PII,int>mp1,mp2,mp3;
    cin>>T;
    while(++t<=T)
    {
        cin>>j>>p>>s>>k;
        cloth.clear();
        mp1.clear();
        mp2.clear();
        mp3.clear();
        REP(x,1,j)
        {
            REP(y,1,p)
            {
                REP(z,1,s)
                {
                    flag=1;
                    if(mp1.find(MP(x,y))!=mp1.end())
                    {
                        if(mp1[MP(x,y)]==k)flag=0;
                    }
                    if(mp2.find(MP(y,z))!=mp2.end())
                    {
                        if(mp2[MP(y,z)]==k)flag=0;
                    }
                    if(mp3.find(MP(z,x))!=mp3.end())
                    {
                        if(mp3[MP(z,x)]==k)flag=0;
                    }
                    if(flag==1)
                    {
                        d.a=x;d.b=y;d.c=z;
                        cloth.PB(d);
                        if(mp1.find(MP(x,y))!=mp1.end())mp1[MP(x,y)]++;
                        else mp1[MP(x,y)]=1;
                        if(mp2.find(MP(y,z))!=mp2.end())mp2[MP(y,z)]++;
                        else mp2[MP(y,z)]=1;
                        if(mp3.find(MP(z,x))!=mp3.end())mp3[MP(z,x)]++;
                        else mp3[MP(z,x)]=1;
                    }
                }
            }
        }
        cout<<"Case #"<<t<<": "<<cloth.size()<<'\n';
        REP(i,0,cloth.size()-1)cout<<cloth[i].a<<' '<<cloth[i].b<<' '<<cloth[i].c<<'\n';
    }
    return 0;
}
