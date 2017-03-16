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

int game1(deque<double> a,deque<double> b){
	int c = 0;
	set<double> A;
	for(int i = 0 ; i < a.size() ; i++) A.insert(a[i]);
	for(int i = 0 ; i < b.size() ; i++){
		if( b[i] > (*A.rbegin()) ){
			A.erase(*A.begin());
		}else{
			set<double>::iterator low = A.lower_bound(b[i]);
			A.erase(*low);
			c++;
		}
	}
	return c;
}

int game2(deque<double> a,deque<double> b){
	int c = 0;
	for(int i = 0 ; i < a.size() ; i++){
		if( a[i] < b.front() ){
			b.pop_front();
		}else{
			c++;
			b.pop_back();
		}
	}
	return c;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		deque<double> a(n),b(n);
		for(int i = 0 ; i < a.size() ; i++) cin >> a[i];
		for(int i = 0 ; i < a.size() ; i++) cin >> b[i];
		sort(a.rbegin(),a.rend());
		sort(b.rbegin(),b.rend());
		//for(int i = 0 ; i < a.size() ; i++) cout << a[i] << " " << b[i] << endl;
		putCase();
		cout << game1(a,b) << " " << game2(a,b) << endl;
	}
}