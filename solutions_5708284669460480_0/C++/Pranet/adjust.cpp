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
int n;
int cnt[26];
int total;
int f[201];
int F[201][26];
int s;
bool DONE[201][201];
double DP[201][201];
double dp(int u,int k)
{
	if(u==s)
		return 0;
	if(DONE[u][k])
		return DP[u][k];
	DONE[u][k]=true;
	double o1=0;

	for(int i=0;i<26;++i)
	{
		if(cnt[i]==0)
			continue;

		double prob=(double)cnt[i]/total;
		if(k==n-1)
		{
			if(F[k][i]==n)
			{
				o1+=prob*(1+dp(u+1,f[n-1]));
			}
			else
				o1+=prob*dp(u+1,F[k][i]);
		}
		else
		{

			o1+=prob*dp(u+1,F[k][i]);
		}
	}
	return DP[u][k]=o1;
}
int main()
{
  std::ios::sync_with_stdio(false);
  // freopen("output.txt","w",stdout);
  int t;
  cin>>t;
  for(int i=1;i<=t;++i)
  {

	memset(DONE,0,sizeof DONE);
  	cout<<"Case #"<<i<<": ";
  	int k,l;
  	cin>>k>>l>>s;
  	string keyboard;
  	cin>>keyboard;
  	string target;
  	cin>>target;
  	memset(cnt,0,sizeof cnt);
  	total=0;
  	/* do the keyboard */
  	for(int i=0;i<keyboard.size();++i)
  	{
  		cnt[keyboard[i]-'A']+=1;
  		++total;
  	}

  	/* do the target */
  	for(int i=1;i<target.size();++i)
  	{
  		int j=f[i-1];
  		while(j && target[i]^target[j])
  			j=f[j-1];
  		j+=(target[i]==target[j]);
  		f[i]=j;
  	}

  	for(int i=0;i<target.size();++i)
  	{
  		for(int j='A';j<='Z';++j)
  		{
  			int k=i;
  			while(k && target[k]^j)
  				k=f[k-1];
  			k+=(target[k]==j);
  			F[i][j-'A']=k;
  		}
  	}

  	/* see if target is even typeable */
  	bool isTypeable=true;
  	for(int i=0;i<target.size();++i)
  	{
  		if(cnt[target[i]-'A']==0)
  			isTypeable=false;
  	}

  	n=target.size();
  	if(s<n)
  		isTypeable=false;

  	if(isTypeable==false)
  	{
  		cout<<"0.0\n";
  		continue;
  	}
  	/* now i know its typeable: find max number of times i can get it in len s */
  	int nextTime=n-f[n-1];
  	int all=1;
  	int left=s-n;
  	while(left>0 && left>=nextTime)
  		{
  			left-=nextTime;
  			++all;
  		}
  	double e=dp(0,0);
  	cout<<setprecision(6)<<fixed<<all-e<<"\n";
  }
  


}