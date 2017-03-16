/* Pranet Verma */
/* Yeh mera template hai. Apna khud banao =_= */
#include <bits/stdc++.h>
using namespace std;
#define infinity (1000000007)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define pip pair<int,pii>
#define pb push_back
#define mp make_pair
#define s(n) scanf("%d",&n)
#define s2(n,m) scanf("%d%d",&n,&m)
#define s3(n,m,l) scanf("%d%d%d",&n,&m,&l)
#define rep(i,n) for(int i=0;i<n;++i)
ll pwr(ll a,ll b,ll mod) {a%=mod;if(a<0)a+=mod;ll ans=1; while(b) {if(b&1) ans=(ans*a)%mod; a=(a*a)%mod; b/=2; } return ans; }
ll pwr(ll a,ll b) {ll ans=1; while(b) {if(b&1) ans*=a; a*=a; b/=2; } return ans; }
ll gcd(ll a,ll b) {while(b) {ll temp=a; a=b; b=temp%b; } return a; }
ll lcm(ll a,ll b) {return (a/gcd(a,b))*b; }
ll modularInverse(ll a,ll m) {/*reminder: make sure m is prime*/ assert(false); return pwr(a,m-2,m); }
const int mod=1000000007;
bool DONE[31][31];
bool DP[31][31];
int avail[31];
bool dp(int u,int left)
{
	if(left<0)
		return 0;
	if(left==0)
		return 1;
	if(u==0)
		return 0;
	if(DONE[u][left])
		return DP[u][left];
	DONE[u][left]=1;

	bool ans=dp(u-1,left);
	if(avail[u])
		ans|=dp(u-1,left-u);

	return DP[u][left]=ans;

}
int main()
{
  std::ios::sync_with_stdio(false);
  freopen("output.txt","w",stdout);
  int t;
  cin>>t;
  for(int cas=1;cas<=t;++cas)
  {
  	cout<<"Case #"<<cas<<": ";
  	int c,d,v;
  	cin>>c>>d>>v;
  	memset(avail,0,sizeof avail);
  	for(int i=0;i<d;++i)
  	{
  		int x;
  		cin>>x;
  		avail[x]=1;
  	}
  	int ans=0;
  	for(int i=1;i<=v;++i)
  	{
  		if(avail[i])
  			continue;
  		memset(DONE,0,sizeof DONE);
  		if(dp(v,i))
  			continue;
  		avail[i]=1;
  		++ans;
  	}
  	cout<<ans<<"\n";
  }
   


}