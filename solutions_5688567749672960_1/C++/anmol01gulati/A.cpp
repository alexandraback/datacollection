#include <bits/stdc++.h>
using namespace std;

#define s(n)            scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define ss(n)           scanf("%s",n)
#define pls(x)          cout << x << " "
#define pln(x)          cout << x << "\n"
#define pis(x)          printf("%d ", x)
#define pin(x)          printf("%d\n", x)
#define pnl             printf("\n")
#define dbn             cerr << "\n"
#define dbg(x)          cerr << #x << " : " << x << " "
#define dbs(x)          cerr << x << " "
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define rep(i,n)        FOR(i,0,n-1)
#define foreach(c,v)    for(__typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp              make_pair
#define FF              first
#define SS              second
#define pb              push_back
#define fill(a,v)       memset(a,v,sizeof(a))
#define all(x)          x.begin(),x.end()
#define sz(v)           ((int)(v.size()))
#define INF             (int)1e9
#define LINF            (long long)1e18
#define EPS             1e-9
#define INDEX(arr,ind)  (lower_bound(all(arr),ind)-arr.begin())

typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<pii> vii;

const int MAXN = 200015;
const int MOD  = 1000000007;
/*Main code begins now */
lli N;
vector<string> S;
lli reverse(lli n){
	vi A;
	while(n) {
		A.pb(n%10);
		n/=10;
	}
	n = sz(A);
	lli ret = 0;
	rep(i,n){
		ret = A[i] + ret*10LL;
	}
	return ret;
}
int totalSize(lli n){
	vi A;
	while(n) {
		A.pb(n%10);
		n/=10;
	}
	n = sz(A);
	return n;
}
lli solve(){
	lli n = 1;
	lli ans = 1;
	int digits = totalSize(n);
	int D = totalSize(N);
	while(digits<D){
		ans += (int)pow(10,digits/2) + (int)pow(10,(digits+1)/2) -1;
		if(digits == 1) ans-=1;
		n = (int)pow(10,digits);
		digits = totalSize(n);
	}
	if(N == n) return ans;
	digits = totalSize(n);
	lli left = N - n;
	lli ret;
	FOR(i,1,digits-1){
		lli t = reverse((N-1)/(int)pow(10,digits-i));
		ret = 0;
		ret =t + 1;
		ret += N-reverse(n + t);
		left = min(left,ret);
	}
	ans +=left;
	return ans;
	
}
int main(){
	int t,n;
	s(t);
	rep(z,t){
		printf("Case #%d: ",z+1);
		sl(N);
		printf("%lld\n",solve());
	}
	return 0;
}