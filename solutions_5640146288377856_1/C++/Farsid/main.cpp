/*
Farsid
BUET
CSE
10
*/

#define filer() freopen("far.in","r",stdin)
#define filew() freopen("far.in","w",stdout)

#include <set>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include <map>
#include<ctime>
#define SET(a, x) memset((a), (x), sizeof(a))
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define i64 ll
#define MAX
#define xx first
#define yy second
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<ll> VL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;

const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("my_out.out","w",stdout);
    int i,j,k ,T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        int R,C,W;
        cin>>R>>C>>W;
        int ans=(C/W)*R;
        //cout<<ans<<endl;
        if(C%W)ans+=(W);
        else ans+=(W-1);
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
/*Test Cases


*/
