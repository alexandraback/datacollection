

/*

ID: jbsu321
PROG: test
LANG: C++

*/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <list>
#include <bitset>
#include <ctime>

#define ms(a,b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define CL(a) a.clear()
#define pi (2*acos(0))
#define oo 1<<29
#define dd double
#define ll long long
#define ff float
#define MP make_pair
#define EPS 10E-10
#define fr first
#define sc second
#define MAXX 100
#define SZ(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define intlim 2147483648
#define rtintlim 46340
#define llim 9223372036854775808
#define rtllim 3037000499
#define pall pair<ll,ll>
#define padd pair<dd,dd>
#define paii pair<int,int>
#define ull unsigned long long
#define csprint printf("Case #%lld: ", C++)
#define bpc __builtin_popcount

#define REP(i,N)  for(i=0;i<N;i++)
#define REV(i,N)  for(i=N;i>=0;i--)
#define FOR(i,p,k) for (i=p; i<k;i++)


#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define vi          vector<int>
#define vd          vector<double>
#define vll         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fs          first
#define sc          second
#define pii         pair < int , int >

#define EQ(a,b)     (fabs(a-b)<ERR)


#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)

#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define read()      freopen("test.txt","r",stdin)

#define icin3(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)
#define icin2(a,b) scanf("%lld%lld", &a, &b)
#define icin1(a) scanf("%lld", &a)

#define dcin3(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define dcin2(a,b) scanf("%lf%lf",&a,&b)
#define dcin1(a) scanf("%lf",&a)

using namespace std;

//ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}
int BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;} /// (B^P)%M
//ll Gcd(ll a,ll b){ if(b==0)return a; Gcd(b,a%b); return;}

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

//ll fact[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};


ll ncr(ll a, ll b)
{
    ll res = 1;
    b=max(b,a-b);
    for(ll i=b+1 , j=1 ;i<=a ; i++,j++)
        res=((res*i)/j);

    return res;
}

ll npr(ll a, ll b)
{
    ll res = 1;
    for(ll i=a-b+1; i<=a; i++)
        res*=i;

    return res;
}

string decimal_to_binary(ll cur)
{
    string v;
    while(cur)
    {
        v.pb((cur%2)+'0');
        cur/=2;
    }
    return v;
}

long long lcm(ll x, ll y)
{
    ll r;

    return ((r/x)*y);
}

ll power(ll a, ll b)
{
    ll ans = 1;
    for(int i=0; i<b; i++)ans*=a;
    return ans;
}

//void factorial(ll mm){fact[0]=fact[1]=1;fact[2]=2;for(int i=3; i<1001; i++)fact[i]=(i*fact[i-1])%mm;}
ll vagerMod(ll a, ll b, ll mm){return ((a%mm)*(BigMod(b,mm-2,mm)))%mm;}

//9,9+90*2,9+90*2+900*3,9+90*2+900*3+9000*4,9+90*2+900*3+9000*4+90000*5,9+90*2+900*3+9000*4+90000*5+900000*6,9+90*2+900*3+9000*4+90000*5+900000*6+9000000*7,9+90*2+900*3+9000*4+90000*5+900000*6+9000000*7+90000000*8
ll arrToNumberOfDigits[]={9,9+90*2,9+90*2+900*3,9+90*2+900*3+9000*4,9+90*2+900*3+9000*4+90000*5,9+90*2+900*3+9000*4+90000*5+900000*6,9+90*2+900*3+9000*4+90000*5+900000*6+9000000*7,9+90*2+900*3+9000*4+90000*5+900000*6+9000000*7+90000000*8};



//int loop1[]={1,1,1,0,0,-1,-1,-1};
//int loop2[]={-1,0,1,-1,1,1,0,-1};

//int color[1000000];
//int cpp[1000000];

pall MV(ll a, ll b, ll c, ll d){pall aa;aa.fr=c-a;aa.sc=d-b;return aa;}
ll CP(ll a, ll b, ll c, ll d){return (a*d-b*c);}

//void kmp()
//{
//    ll k;
//    k=par[0]=0;
//    for(ll i=1; i<SZ(str); i++)
//    {
//        while(k>0&&str[k]!=str[i])k=par[k-1];
//        if(str[i]==str[k])k++;
//        par[i]=k;
//    }
//}

string cut_leading_zero(string a)
{
    string s;
    int i;
    if(a[0]!='0')   return a;
    REP(i,SZ(a)-1)  if(a[i]!='0')   break;
    FOR(i,i,SZ(a))  s+=a[i];
    return s;
}

ll T, C=1, N;
bool col[1000][1000];

bool not_possible(int n, int x1, int y1, int x2, int y2, bool p)
{
    return 0;
}

void process()
{
    cin>>T;
    while(T--)
    {
        int n, x, y;
        cin>>n>>x>>y;
        col[0][0]=1;csprint;
        if(not_possible(1,-2,0,2,0,(x>0)))
        {
            cout<<"1.0"<<endl;
        }
        else cout<<"0.0"<<endl;
    }
    return;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    process();
    return 0;
}













