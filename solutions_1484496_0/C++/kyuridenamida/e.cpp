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
int main(){
	int T,t=0;
	cin >> T;
	while(T--){
		t++;
		int n;
		cin >> n;
		int v[20]={};
		rep(i,n) cin >> v[i];
		map<int,vector<int> > o;
		for(int i = 1 ; i < (1<<n) ; i++){
			int anss = 0;
			for(int j = 0 ; j < n ; j++){
				if( i >> j & 1){
					anss += v[j];
				}
			}
			o[anss].push_back(i);
		}
		int f = false;
		printf("Case #%d:\n",t);
		EACH(it,o){
			if( it->second.size() > 1){
				vector<int> a,b;
				for(int j = 0 ; j < n ; j++) if( it->second[0] >> j & 1) a.push_back(v[j]);
				for(int j = 0 ; j < n ; j++) if( it->second[1] >> j & 1) b.push_back(v[j]);
				for(int j = 0 ; j < a.size() ; j++) cout << a[j] << (j==a.size()-1?"\n":" ");
				for(int j = 0 ; j < b.size() ; j++) cout << b[j] << (j==b.size()-1?"\n":" ");
				f = true;
				break;
			}
		}
		if( !f ) cout << "Impossible" << endl; 
		
	}
	
}