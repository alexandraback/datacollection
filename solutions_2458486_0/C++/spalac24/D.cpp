using namespace std;
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iterator>
#include <bitset>
#include <cstdlib>
#include <set>

template <class T> string toStr (T x){stringstream ss;ss << x;return ss.str();}
template <class T> long long toInt (T x){stringstream ss; ss << x; long long r; ss >> r; return r;}


#define FOR(i,a,b) for(int i = (a); i <(b); ++i)
#define foreach(x,v) for(typeof (v).begin() x = v.begin(); x != v.end(); ++x)
#define sz(x) (int)(x).size()
#define DEBUG
#ifdef DEBUG
#define REACH  cout<<" reached line "<<__LINE__<<endl
#define D(x) cout<<#x " is "<<(x)<<endl
#else
#define REACH
#define D(x)
#endif	
#define D2(x) cout<<#x " is "<<(x)<<endl
typedef unsigned long long ull; 
typedef vector<int> vi;
const int MAXN = 25;
int opens [MAXN];
vector<int> has [MAXN];
const int MAXS = 1<<20;
int seen [MAXS];
map<int,int> m;
vi memo [MAXS];

int n,k,all;
vi f (int mask) {
	if (seen[mask]) return memo[mask];
	map<int,int> ma = m;
	for (int i = 0; i < n; ++i) {
		if (!(mask&(1<<i))) continue;
		ma[opens[i]]--;
		for (int j = 0; j < (int)has[i].size(); ++j) {
			ma[has[i][j]]++;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (mask&(1<<i)) continue;
		if (ma[opens[i]] == 0) continue;
		if (ma[opens[i]] < 0) {
			D(mask);
			assert(false);
		}
		int nm = mask|(1<<i);
		vi r = f(nm);
		if (seen[nm] == 1) {
			r.push_back(i);
			seen[mask] = 1;
			return memo[mask] = r;
		}
	}
	seen[mask] = -1;
	return memo[mask] = vector<int>();
}

int main (){
	ios::sync_with_stdio(false);
	int cases;
	cin>>cases;
	for (int cas = 1; cas <= cases; ++cas) {
		cout<<"Case #"<<cas<<":";
		cin>>k>>n;
		//		D(k); D(n);

		memset(seen,0,sizeof seen);
		fill(memo,memo+(1<<n),vector<int>());
		all = (1<<n)-1;
		memo[all] = vector<int>();
		seen[all] = 1;
		m.clear();
		for (int i = 0; i < k; ++i) {
			int x;
			cin>>x;
			m[x]++;
		}
		//		REACH;
		for (int i = 0; i < n; ++i) {
			cin>>opens[i];
			int ki;
			cin>>ki;
			has[i].clear();
			has[i].resize(ki);
			while(ki--) {
				cin>>has[i][ki];
			}
		}
		//	    REACH;
   
		vi v = f(0);
		bool p = seen[0]==1;
		reverse(v.begin(),v.end());
		map <int,int> ke = m;
		
		for (int i = 0; i < n and p; ++i) {
			assert(ke[opens[v[i]]] > 0);
			if (ke[opens[v[i]]] <= 0) p = false;
			ke[opens[v[i]]]--;
			for (int j = 0; j < has[v[i]].size(); ++j) {
				ke[has[v[i]][j]]++;
			}
		}
		if (p){
		for (int i = 0; i < n; ++i) cout<<" "<<(v[i]+1);
		cout<<endl;}
		if (!p)
			cout<<" IMPOSSIBLE"<<endl;
	}
}
