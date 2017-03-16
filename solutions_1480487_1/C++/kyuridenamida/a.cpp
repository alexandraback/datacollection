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
int X , a[210] = {};
double res[210] = {};
int n;

int ok(double par,int idx){
	double target = a[idx] + par * X;
	
	long double sum = par;
	for(int i = 0 ; i < n ; i++){
		if( i == idx) continue;
		if( target < a[i] ) continue;
		long double p = (target - a[i]) / X;
		sum += p;
	}
	
	return sum <= 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	int T,t=0;
	cin >> T;
	while(T--){
		t++;
		cin >> n;
		X = 0;
		int Y = 0;
		int zero = 0;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			X += a[i];
		}
		
		for(int i = 0 ; i < n ; i++){
			long double l = 0 , r = 1;
			for(int _ = 0 ; _ < 512 ; _++){
				long double m = (l+r)/2.0;
				if( ok(m,i) ){
					l = m;
				}else{
					r = m;
				}
			}
			res[i] = l;
		}
		double sum = 0;
		for(int i = 0 ; i < n ; i++){
			sum += res[i];
		}
		//cout << ">>>" << sum << endl;
		printf("Case #%d:",t);
		for(int i = 0 ; i < n ; i++){
			printf(" %.10lf", res[i] * 100 );
		}
		puts("");
	}
	
}