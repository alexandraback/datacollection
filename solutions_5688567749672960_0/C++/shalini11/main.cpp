/* Code Jam Template */
#include <bits/stdc++.h>
using namespace std;
#define MOD 					1000000007
#define pb(x) 					push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define FF 						first
#define SS 						second
#define s(n) 					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
//special macro for reading a character of input
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
/*
Use these macros when comparing variables of different data types.
For e.g. comparing int and long long will give error when used with std::max, use maX instead.
*/
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
typedef long long ll;
typedef unsigned long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<ll> vl;
typedef vector<PII> VII;
typedef vector<TRI> VT;

/*Main code begins now*/
int dp[1000005];
int rev(int n )
{
    int r=0;
    int tmp1=n,c1=n;
    while(n)
    {
        r=r*10+n%10;
        n/=10;
    }
    int tmp2=r;
    while(tmp1&&tmp2)
    {
        tmp1/=10;tmp2/=10;
    }
    //cout<<r<<endl<<c1<<endl;
    if(tmp1) return c1;
    return min(c1,r);
}
void precompute() {
    /*
    Code that is common to all test cases and should be run before solving for any case, like Prime-NUmber Generation :)
    */
    int i;
    for(i=1;i<=1000000;i++) dp[i]=INT_MAX;
dp[1]=1;
for(i=2;i<=10;i++) dp[i]=i;

for(i=11;i<=1000000;i++)
{
   // cout<<rev(i);
    dp[i]=min(dp[i-1],dp[rev(i)])+1;
}
//cout<<dp[11];
}

int n;
void read() {
    /*
    Read Global variables here
    */
   cin>>n;
}



void solve() {

    /*
    Main logic goes here
    */

    cout<<dp[n]<<endl;
}

int main(){
   freopen("A.in", "r", stdin);
	freopen("output.in", "w", stdout);
	precompute();
	//cout<<primecount[1];
	//cout<<cat[2];
	int t;
	s(t);
   // cout<<t;
	for(int T = 1; T <= t; T++) {
	    read();
	    printf("Case #%d: ",T);
        solve();
  	}
	return 0;
}
