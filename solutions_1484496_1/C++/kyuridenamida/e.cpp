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
#include <tr1/unordered_map>
#include <sys/time.h>
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

int n;
long long v[510]={};

tr1::unordered_map<long long,bool> memo[510];
int flag;
int c = 0;
vector<long long> A[2];
long long summ[510] = {};
clock_t start;
long long X[2] ;
int breaku = 0;
void dfs(int pos){
	if( (double)(clock()- start) / CLOCKS_PER_SEC >= 30){
		return;
	}
	if( breaku == 1 ) return;
	int s = 0;
	if( X[1^c] < X[0^c] ){
		c^= 1;
		s = 1;
	}
	if( X[1^c] - X[0^c] > summ[pos] ){
		if( s ){
			c ^= 1;
		}
		return ;
	}
	//cout << X[1^c] - X[0^c] << endl;
	if( flag == 1 && X[1^c] - X[0^c] == 0 ){
		//cout << X[1^c] << " " << X[0^c] << endl;
		for(int i = 0 ; i < A[0].size() ; i++) cout << A[0][i] << (A[0].size()-1 == i ? "\n" : " ");
		for(int i = 0 ; i < A[1].size() ; i++) cout << A[1][i] << (A[1].size()-1 == i ? "\n" : " ");
		
		breaku = 1;
		return;
	}
	if( flag == 1 ){
		if( memo[pos][ X[1^c] - X[0^c] ] ){
			if( s ){
				c ^= 1;
			}
			return ;
		}else memo[pos][ X[1^c] - X[0^c] ] = true;
	}
	if( pos >= n ){
		if( s ){
			c ^= 1;
		}
		return; 
	}
	dfs(pos+1);
	
	int t = flag;
	flag = 1;
	A[0^c].push_back(v[pos]);
	X[0^c] += v[pos];
	dfs(pos+1);
	X[0^c] -= v[pos];
	A[0^c].pop_back();
	
	A[1^c].push_back(v[pos]);
	X[1^c] += v[pos];
	dfs(pos+1);
	X[1^c] -= v[pos];
	A[1^c].pop_back();
	flag = t;
	if( s ){
		c ^= 1;
	}
	return;
}
/*
	
*/
int main(){
	int T,t=0;
	cin >> T;
	while(T--){
		for(int i = 0 ; i < 510 ; i++) memo[i].clear();
		for(int i = 0 ; i < 510 ; i++) summ[i] = 0;
		
		start = clock();
		t++;
		cin >> n;
		rep(i,n) cin >> v[i];
		sort(v,v+n);
		reverse(v,v+n);
		for(int i = n-1 ; i >= 0  ; i--){
			summ[i] = summ[i+1] + v[i];
		}
		X[0] = 0;
		X[1] = 0;
		A[0].clear();
		A[1].clear();
		c = 0;
		breaku = 0;
		printf("Case #%d:\n",t);
		dfs(0);
		if( !breaku ) cout << "Impossible" << endl; 
		cerr << "DONE " << t << endl;
		
	}
	
}