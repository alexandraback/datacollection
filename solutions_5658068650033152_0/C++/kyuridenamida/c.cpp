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

int H,W;
int d[22][22];
int c[22][22];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int dfs(int x,int y){
	if( x < 0 || y < 0 || y > H+1 || x > W + 1 || c[y][x] || d[y][x] ) return 0;
	c[y][x] = true;
	rep(i,4)dfs(x+dx[i],y+dy[i]);
}
int main(){
	int T;
	cin >> T;
	while(T--){
		int K;
		cin >> H >> W >> K;
		int ans = 1e9;
		for(int i = 0 ; i < (1<<H*W) ; i++){
			for(int k = 0 ; k <= H+1 ; k++){
				for(int j = 0 ; j <= W+1 ; j++){
					d[k][j] = c[k][j] = 0;
				}
			}
			for(int j = 0 ; j < H*W ; j++){
				if( i >> j & 1 ){
					d[1+(j/W)][1+(j%W)] = 1;
				}
			}
			dfs(0,0);
			int cntcnt = 0;
			for(int k = 1 ; k <= H ; k++){
				for(int j = 1 ; j <= W ; j++){
					cntcnt += (c[k][j] == 0);
				}
			}
			if( cntcnt == K ) ans = min(ans,__builtin_popcount(i));
		}
		
		putCase();
		cout << ans << endl;
		cerr << T << endl;
	}
	
}