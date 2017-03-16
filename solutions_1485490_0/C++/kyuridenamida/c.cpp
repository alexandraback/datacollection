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

int output(int t){
}
int N,M;
long long a[101] , b[101] , A[101] , B[101];

map< pair< pair<int,long long> , pair<int,long long> > , long long > memo;

pair< pair<int,long long> , pair<int,long long> > co(int x,long long X,int y,long long Y){
	return make_pair( make_pair(x,X) , make_pair(y,Y) );
}

long long dfs(const int x,const long long X,const int y,const long long Y){
	//cout << memo.size() << endl;
	if( x == N || y == M ) return 0;
	if( memo.count(co(x,X,y,Y)) )return memo[co(x,X,y,Y)];
	//cout << x << " " << X << " " << y << " " << Y << endl;
	long long ans = 0;
	if( A[x] == B[y] && min(X,Y) > 0){
		long long profit = min(X,Y);
		ans = max( ans , dfs(x,X-profit,y,Y-profit) + profit );
	}else{
		ans = max( dfs(x+1,a[x+1],y,Y) , dfs(x,X,y+1,b[y+1]) );
	}
	return memo[co(x,X,y,Y)] = ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	int T,t=0;
	cin >> T;
	while(T--){
		t++;
		memo.clear();
		cin >> N >> M;
		for(int i = 0 ; i < N ; i++){
			cin >> a[i] >> A[i];
		}
		for(int i = 0 ; i < M ; i++){
			cin >> b[i] >> B[i];
		}
		cout << "Case #" << t << ": " << dfs(0,a[0],0,b[0]) << endl;
	}
	
}