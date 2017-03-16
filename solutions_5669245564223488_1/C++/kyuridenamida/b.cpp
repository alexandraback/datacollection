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

int type(string s){
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
	if( s.size() >= 2 ) return 1;
	else return 0;
}
long long mod = 1000000007ll;;
long long f(long long x){
	if( x == 0 ) return 1;
	return f(x-1) * x % mod;
}

vector<int> counter;
vector<int> done;
long long get = 1;
int dfs(int x,const vector< vector<int> > &graph){
	if( done[x]++ ) return 0;
	get *= f(counter[x]);
	get %= mod;
	for(int i = 0 ; i < graph[x].size() ; i++){
		dfs(graph[x][i],graph);
	}
}

int main(){
	int T;
	cin >> T;
	while(T--){
		long long N;
		cin >> N;
		vector<int> s;
		for(int i = 0 ; i < N ; i++) s.push_back(i);
		vector<string> d(N);
		set<char> h;
		long long cnt = 1;
		bool error = false;
		counter = vector<int>(26,0);
		vector<int> ind(26),oud(26);
		vector< vector<int> > graph(26,vector<int>());
		int occur[128] = {};
		int danger[26] = {};
		for(int i = 0 ; i < N ; i++){
			cin >> d[i];
			d[i].erase(unique(d[i].begin(),d[i].end()),d[i].end());
			string s = d[i];
			sort(s.begin(),s.end());
			s.erase(unique(s.begin(),s.end()),s.end());
			for(int j = 0 ; j < s.size() ; j++) occur[s[j]]++;
			if( s.size() != d[i].size() ) error = true;
		}
		for(int i = 0 ; i < N ; i++){
			for(int j = 1 ; j+1 < d[i].size() ; j++){
				if( occur[d[i][j]] >= 2 ) error = true;
			}
		}
		for(int i = 0 ; i < N ; i++){
			int t = type(d[i]);
			if( t == 1 ){
				graph[d[i][0]-'a'].push_back(d[i][d[i].size()-1]-'a');
			}
			if( t == 0 ) counter[d[i][0]-'a']++;
		}
		for(int i = 0 ; i < 26 ; i++){
			oud[i] = graph[i].size();
			for(int j = 0 ; j < graph[i].size() ; j++){
				ind[graph[i][j]]++;
			}
		}
		vector<int> startPoint;
		vector<int> exist(26);
		done = vector<int>(26);
		int cntr = 0;
		for(int i = 0 ; i < 26 ; i++){
			if( oud[i] > 1 || ind[i] > 1){
				error = 1;
			}
			if( oud[i] || ind[i] || counter[i] ) exist[i] = 1;
			if( ind[i] == 0 && oud[i] == 1 ){
				get = 1;
				dfs(i,graph);
				cnt *= get;
				cnt %= mod;
				startPoint.push_back(i);
				cntr++;
			}
		}
		for(int i = 0 ; i < 26 ; i++){
			if( !ind[i] && !oud[i] && counter[i] ){
				done[i] = true;
				cnt *= f(counter[i]);
				cnt %= mod;
				cntr++;
			}
			if( exist[i] && !done[i] ) error = 1;
		}
		cnt *= f(cntr);
		cnt %= mod;
		if(error) cnt = 0;
		putCase();
		cout << cnt << endl;
	}
}