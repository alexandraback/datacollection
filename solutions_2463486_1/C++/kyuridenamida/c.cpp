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
int isp(long long x){
	stringstream ss;
	ss << x;
	string s = ss.str();
	string t = s;
	reverse(t.begin(),t.end());
	return s == t;
}


vector<string> s;

void dfs(int sum,string r){
	if(sum>=10) return;
	if( r.size() > 25 ) return;
	string t = r;
	reverse(t.begin(),t.end());
	if(r!="")s.push_back(r+t);
	for(int i = 0 ; i < 4 ; i++){
		if( sum + i*i < 10 ){
			s.push_back(r+string(1,'0'+i)+t);
		}
	}
	for(int i = (r=="") ; i < 4 ; i++){
		dfs(sum+2*i*i,r+(char)('0'+i));
	}
}


long long F(long long x){
	ll ans = 0;
	/*vector<long long> v;
	for(int i = 0 ; i < 10000 ; i++){
		for(int j = 0 ; j < 11 ; j++){
			string s = i ? itos(i) : "";
			string t = s;
			reverse(t.begin(),t.end());
			stringstream ss;
			ss << s;
			if(j!=10)ss << j;
			ss << t;
			long long val;
			ss >> val;
			if( isp(val*val) ){
				v.push_back(val*val);
			}
		}
	}
	sort(v.begin(),v.end());
	for(int i = 0 ; i < v.size() ; i++){
		//cout << v[i] << endl;
		if( v[i] <= x ){
			cout << v[i] << endl;
			ans++;
		}
	}
	return ans;
	cout << endl;
	*/
	ans = 0;
	for(long long i = 0 ; i*i <= x ; i++){
		if( isp(i) ){ans += isp(i*i); //if(isp(i*i))cout << i<< endl;
		}
	}
	return ans;
}

int FF(long long x){
	int ans = 0;
	long long o_O = sqrt(x)+1e-9;
	for(int i = 0 ; i < s.size() ; i++){
		stringstream ss(s[i]);
		ll g;
		ss >> g;
		if( g > o_O ) break;
		//cout << g << endl;
		ans++;
	}
	return ans;
}
bool cmp(const string &a,const string &b){
	return a.size() != b.size() ? a.size() < b.size() : a < b;
}
int main(){
	dfs(0,"");
	sort(s.begin(),s.end(),cmp);
	//cout << s.size() << endl;
	//cout << FF(10) << endl;
	//return 0;
	//cout << F(10000000000000ll) << endl;
	//cout << FF(10000000000000ll) << endl;
	int T;
	cin >> T;
	while(T--){
		long long a,b;
		cin >> a >> b;
		putCase(); cout << FF(b) - FF(a-1) << endl;
	}
}