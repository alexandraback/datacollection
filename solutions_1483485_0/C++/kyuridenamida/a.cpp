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

bool used[128]={};
bool use[128]={};
int main(){
	//ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	getline(cin,s);
	map<char,char> w;
	string x = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string y = "our language is impossible to understand";
		rep(i,x.size())w[x[i]] = y[i] , used[x[i]] = true , use[y[i]] = true;
	rep(i,x.size())w[x[i]] = y[i];
	x = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	y = "there are twenty six factorial possibilities";
		rep(i,x.size())w[x[i]] = y[i] , used[x[i]] = true , use[y[i]] = true;
	rep(i,x.size())w[x[i]] = y[i];
	x = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	y = "so it is okay if you want to just give up";
	rep(i,x.size())w[x[i]] = y[i] , used[x[i]] = true , use[y[i]] = true;
	
	
	for(int i = 'a' ; i <= 'z' ; i++)
		for(int j = 'a' ; j <= 'z' ; j++)
			if(used[i] == 0 && use[j] == 0 && i != j)
				w[i] = j;
	rep(_,n){
		getline(cin,s);
		for(int i = 0 ; i < s.size() ; i++)
			if(s[i] >= 'a' && s[i] <= 'z') s[i] = w[s[i]];
		
		printf("Case #%d: ",_+1);
		cout << s << endl;
		
	} 
	
}