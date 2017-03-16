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

int done[1<<20];
int need[20];
int keys[40];
vector<int> inside[20];
int N,K;
int flag = 0;

vector<int> tried;

int dfs(int bit){
	if(flag)return 0;
	if( done[bit] ) return 0;
	else done[bit] = 1;
	if( bit == (1<<N) - 1 ){
		for(int j = 0 ; j < tried.size() ; j++)
			cout << tried[j]+1 << (j+1==tried.size()?"\n":" ");
		flag = 1;
		return 0;
	}else{
		int mykeys[40] = {};
		rep(i,40) mykeys[i] = keys[i];
		for(int i = 0 ; i < N ; i++){
			if( (bit >> i & 1) ) {
				mykeys[need[i]]--;
				for(int j = 0 ; j < inside[i].size() ; j++){
					mykeys[inside[i][j]]++;
				}
			}
		}
		for(int i = 0 ; i < N ; i++){
			if( !(bit>>i&1) && mykeys[need[i]] ){
				
				tried.push_back(i);
				dfs(bit|(1<<i));
				tried.pop_back();
			}
		}
	}
}

map<int,int> dic;
int toCorrectNum(int k){
	if( dic.count(k) ) return dic[k];
	int t = dic.size();
	return dic[k] = t;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		dic.clear();
		memset(keys,0,sizeof(keys));
		memset(done,0,sizeof(done));
		cin >> K>> N;
		for(int i = 0 ; i < K ; i++){
			int k;
			cin >> k;
			keys[toCorrectNum(k)]++;
		}
		
		for(int i = 0 ; i < N ; i++){
			cin >> need[i];
			need[i] = toCorrectNum(need[i]);
			int C;
			cin >> C;
			inside[i].clear();
			for(int j = 0 ; j < C ; j++){
				int x;
				cin >> x;
				inside[i].push_back(toCorrectNum(x));
			}
		}
		flag = 0;
		putCase();
		dfs(0);
		if( !flag ){
			cout << "IMPOSSIBLE" << endl;
		}
	}
}