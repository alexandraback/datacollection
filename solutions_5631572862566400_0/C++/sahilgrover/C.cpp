#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define all(a)  a.begin(), a.end()
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const double eps = 1e-8;
#define EQ(a,b) (fabs((a)-(b))<eps)
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
const int mod = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;

ll power(ll a,ll n){
	if(n==0){
		return 1;
	}
	ll b = power(a,n/2);
	b = b*b%mod;
	if(n%2) b= b*a%mod;
	return b;
}

int add(int a,int b){ return (a+b)%mod;}
int mul(int a,int b){ return (ll)a*b%mod;}

int F[20];
int dp[1<<10][10][10][2][2];
int n;

int f(int mask,int l, int r, int c1, int c2){
	// printf("%d %d %d %d %d\n",mask,l,r,c1,c2);
	int a = c1 , b = c2;
	if(F[l]==r)	a=1;
	if(F[r]==l)	b=1;
	if(mask==((1<<n)-1)){
		if(a+b==2)	return n;
		else return 0;
	}
	int &ret = dp[mask][l][r][c1][c2];
	if(ret!=-1)	return ret;
	ret = 0;
	// int x = __builtin_popcount(mask);
	if(a+b==2)	ret = max(ret,__builtin_popcount(mask));
	// if((F[l]==r || F[r]==l) && x!=2)	return ret;
	REP(i,n){
		if( (  c1==1 && (mask&(1<<i))==0) || (c1==0 && (mask&(1<<i))==0 && i==F[l]) ) {
			if(F[i]==l)	ret = max(ret,f(mask|(1<<i),i,r,1,c2));
			else ret = max(ret,f(mask|(1<<i),i,r,0,c2));
		} 
		if( (  c2==1 && (mask&(1<<i))==0) || (c2==0 && (mask&(1<<i))==0 && i==F[r]) ) {
			if(F[i]==r)	ret = max(ret,f(mask|(1<<i),l,i,c1,1));
			else ret = max(ret,f(mask|(1<<i),l,i,c1,0) );
		} 
	}
	return ret;
}


int main(){
 // 	freopen("nice.in","r",stdin);
 // freopen("nice.out","w",stdout);
	int t;
	scanf("%d",&t);
	REP(tt,t){
		scanf("%d",&n);
		REP(i,n){
			scanf("%d",&F[i]);F[i]--;
		}
		int ans = 1;
		FILL(dp,-1);
			// ans = max(ans,f(3,1,0,0,1));

		REP(i,n){
			ans = max(ans,f((1<<i)|(1<<F[i]),i,F[i],1,0));
			if(F[F[i]]==i)
				ans = max(ans,f((1<<i)|(1<<F[i]),i,F[i],1,1));

		}
		printf("Case #%d: %d\n",tt+1,ans);
	}
	return 0;
}


