#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
#include <cassert>
using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SS stringstream
#define DBG1(a) rep(_X,sz(a)){printf("%d ",a[_X]);}puts("");
#define DBG2(a) rep(_X,sz(a)){rep(_Y,sz(a[_X]))printf("%d ",a[_X][_Y]);puts("");}
#define bitcount(b) __builtin_popcount(b)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

#define delete(a,n) a.erase(remove(all(a),n),a.end())
template<typename T, typename S> vector<T>& operator<<(vector<T>& a, S b) { a.push_back(b); return a; }
template<typename T> void operator>>(vector<T>& a, int b) {while(b--)if(!a.empty())a.pop_back();}
bool isprime(int n){ if(n<2)return false;  for(int i=2;i*i<=n;i++)if(n%i==0)return false;  return true;} 
ll b_pow(ll x,ll n){return n ? b_pow(x*x,n/2)*(n%2?x:1) : 1ll;}
string itos(int n){stringstream ss;ss << n;return ss.str();}


int sup[300] = {};
int mxx[300] = {};
int dp[200][200]={};

int v[300];
int N,S,p;


int dfs(int pos , int rem){
	if(dp[pos][rem]!=-1) return dp[pos][rem];
	if(rem < 0) return -10000000;
	
	if(pos == N){
		return rem == 0 ? 0 : -10000000;
	}
	
	int ans = 0;
	int val = v[pos];
	if(!sup[val]){
		ans = max(ans,dfs(pos+1,rem)+((val+2)/3 >= p));
	}else{
		ans = max( dfs(pos+1,rem-1) + (mxx[val] >= p) , dfs(pos+1,rem) + ((val+2)/3>=p));
	}
	return dp[pos][rem] = ans;
	
}
int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	
	for(int i = 0 ; i <= 10 ; i++){
		for(int j = 0 ; j <= 10 ; j++){
			for(int k = 0 ; k <= 10 ; k++){
				int mx = max(i,max(j,k));
				int mi = min(i,min(j,k));
				int dif = mx-mi;
				if(dif == 2) sup[i+j+k] = true , mxx[i+j+k] = max(mxx[i+j+k],mx);
				
			}
		}
	}
	//rep(i,31) cout << i << " " << sup[i] << endl;
	rep(_,T){
		memset(dp,-1,sizeof(dp));
		cin >> N >> S >> p;
		int ans = 0;
		rep(i,N) cin >> v[i];
		printf("Case #%d: %d\n",_+1,dfs(0,S));
	}
	
}