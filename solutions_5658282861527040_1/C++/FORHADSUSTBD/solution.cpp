//#pragma comment(linker, "/STACK:60000000")

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <assert.h>

using namespace std;

//Type Definition
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi>vvi;
typedef vector<string> vs;
typedef map<string,int> msi;
typedef map<int,int>mii;

#define ERR 1e-9
#define PI 3.141592653589793

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)

#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define MP(a,b) make_pair(a,b)
#define Clear(x,with) memset(x,with,sizeof(x))
#define SZ(x) (int)x.size()
#define pb push_back
#define popcount(i) __builtin_popcount(i)
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define two(X) (1<<(X))
#define twoL(X) (((ll)(1))<<(X))
#define setBit(mask,i) (mask|two(i))
#define contain(S,X) (((S)&two(X))!=0)
#define fs first
#define sc second
#define CS c_str()
#define EQ(a,b) (fabs(a-b)<ERR)
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin());
#define Find(x,y) ((int)x.find(y))

//For debugging
#define debug_array(a,n) for(ll i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(ll i=0;i<row;i++) {for(ll j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define debug(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;

//Important Functions
template<class T> void setmax(T &a, T b) { if(a < b) a = b; }
template<class T> void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T Mod(T n,T m) {return ((n%m)+m)%m;} //For Positive Negative No.
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
ll toInt(string s){ll r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
ll Pow(ll B,ll P){	ll R=1;	while(P>0)	{if(P%2==1)	R=(R*B);P/=2;B=(B*B);}return R;}
ll BigMod(ll B,ll P,ll M){	ll R=1;	while(P>0)	{if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}	return R;}
void binprint(ll mask,ll n){ll i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);Reverse(s);s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
//void ASCII_Chart(){ll i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}


//int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

//#include<conio.h> //for using getch();

struct edge
{
    int cost,node;
    edge(int _cost=0,int _node=0)
    {
        cost=_cost;
        node=_node;
    }
    bool operator<(const edge &b)const
    {
        return cost>b.cost; // Min Priority Queue
    }
};
bool comp(edge a,edge b)
{
    return a.cost < b.cost;
} //Asc Sort by cost

#define INF (1<<28)
#define SIZE 1100

ll dp[33][3][3][3],A,B,K;

ll rec(int pos, int chkA,int chkB,int chkK) {

    if(pos==-1) {
        return (chkK && chkA && chkB);
    }

    ll &ret = dp[pos][chkA][chkB][chkK];

    if(ret!=-1) return ret;

    ret = 0;

    int i,j;
    REP(i,2) REP(j,2) {

        if(i==1 && chkA==0 && !contain(A,pos)) continue;
        if(j==1 && chkB==0 && !contain(B,pos)) continue;

        int tchkA = chkA;
        if(i==0 && contain(A,pos)) tchkA = 1;

        int tchkB = chkB;
        if(j==0 && contain(B,pos)) tchkB = 1;

        int val = i & j;

        if(chkK) {
            ret += rec(pos-1,tchkA,tchkB,chkK);
        } else {
            if(contain(K,pos)) {
                if(val == 0) ret += rec(pos-1,tchkA,tchkB,1);
                else ret += rec(pos-1,tchkA,tchkB,chkK);
            } else {
                if(val==0) ret += rec(pos-1,tchkA,tchkB,chkK);
            }
        }
    }

    return ret;
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);

    int i,j,test,Case=1,cnt,cost;

    scanf("%d",&test);
    while(test--) {

        cin>>A>>B>>K;

        Clear(dp,-1);
        ll ans = rec(30,0,0,0);

        printf("Case #%d: %lld\n",Case++,ans);

    }

    return 0;
}
