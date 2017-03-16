#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <ctime>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
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

void putCase(){
	static int x = 1;
	cout << "Case #" << x++ << ": ";
}

ll dp[100][100];
ll v[10010];
ll s[10010];
ll E,R,N;

ll f(){
	memset(s,0,sizeof(s));
	for(int i = N-1 ; i >= 0 ; i--)
		s[i] = max(v[i],s[i+1]);
	ll ans = 0;
	ll cur = E;
	priority_queue< pair<ll,ll> > Q;
	
	for(int i = 0 ; i < N ; i++){
		cur = min(cur,E);
		if( s[i] == v[i] ){
			ans += cur * v[i];
			cur = 0;
		}else{
			Q.push(make_pair(v[i],i));
			
			vector< pair<ll,ll> > get;
			ll sp = min(cur,max(0ll,(cur+R)-E));
			if(sp){
				while(Q.size()){
					ll vv = Q.top().first;
					ll pp = Q.top().second;
					ll dist = i - pp;
					ll ceiling = E - R*(dist);
					if( ceiling > 0 ){
						ll u = min((ll)sp,ceiling);
						ans += vv*u;
						sp -= u;
						get.push_back(mp(vv,pp));
						Q.pop();
					}else{
						Q.pop();
					}
				}
				for(int i = 0 ; i < get.size() ; i++)
					Q.push(get[i]);
			}
		}
		cur += R;
	}
	return ans;
}

ll dfs(int day,int energy){
	if( day >= N ) return 0;
	energy = min((int)E,energy);
	if( dp[day][energy] != -1 ) return dp[day][energy];
	
	ll ans = 0;
	for(int i = 0 ; i <= energy ; i++){
		ans = max(ans,dfs(day+1,energy-i+R)+i*v[day]);
	}
	//cout << day << " " << energy << " " << ans << "[" << E << "]" <<" " << energy << endl;
	return dp[day][energy] = ans;
} 
int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> E >> R >> N;
		for(int i = 0 ; i < N ; i++) cin >> v[i];
		/*E = rand() % 10 + 1;
		R = rand() % 10 + 1;
		N = rand() % 20 + 1;
		*/
		//for(int i = 0 ; i < N ; i++) v[i] = rand() % 50 + 1;
		//memset(dp,-1,sizeof(dp));
		//int ans1 = dfs(0,E);
		ll ans2 = f();
		/*if( ans1 != ans2 ){
			cout << ans1 << " " << ans2 << endl;
			cout << "[" << E << "," << R << "," << N << "]" << endl;
			rep(i,N)cout << v[i] << " ";cout << endl;
			memset(dp,-1,sizeof(dp));
		}*/
		putCase();
		cout << ans2 << endl;
	}
}