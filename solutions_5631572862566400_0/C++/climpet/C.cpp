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
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#endif

using namespace std;


namespace{

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T, class U=T>
void initvv(vector<vector<T> > &v, int a, int b, const U &t = U()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8


void prepare(){
//	ios::sync_with_stdio(false);
	
}


LL solve(){
	int n;
	cin >> n;
	vint f(n);
	VV(int) rG(n);
	for(int i = 0; i < n; ++i){
		cin >> f[i];
		--f[i];
		rG[f[i]].push_back(i);
	}
	
	int gen = 0;
	vint tm(n, -1);
	
	int res1 = 0, res2 = 0;
	for(int s = 0; s < n; ++s){
		if(tm[s] != -1 || f[f[s]] != s){ continue; }
		tm[s] = gen;
		tm[f[s]] = gen;
		int sum = 0;
		for(int z = 0; z < 2; ++z){
			int u = z ? s : f[s];
			queue<int> q;
			q.push(u);
			q.push(-1);
			int cnt = 1;
			while(q.size() > 1){
				u = q.front();
				q.pop();
				if(u == -1){
					q.push(-1);
					++cnt;
				}
				else{
					for(int v : rG[u]){
						if(tm[v] == -1){
							tm[v] = gen;
							q.push(v);
						}
					}
				}
			}
			sum += cnt;
		}
		
		res1 = max(res1, sum);
		++gen;
	}
	
	for(int s = 0; s < n; ++s){
		if(tm[s] != -1){ continue; }
		int u = s;
		while(tm[u] == -1){
			tm[u] = gen;
			u = f[u];
		}
		if(tm[u] == gen){
			int c = 1;
			for(int v = f[u]; u != v; v = f[v]){
				++c;
			}
			res2 = max(res2, c);
		}
		++gen;
	}
	
	return max(res1, res2);
}


}
int main(){
	cout << fixed << setprecision(15);
	cerr << fixed << setprecision(6);
	prepare();

	string str = "_";
	getline(cin, str);
	int T = strtol(str.c_str(), 0, 10);
	for(int cnum = 1; cnum <= T; ++cnum){
		fprintf(stderr, "%4d / %d\n", cnum, T);
		cout << "Case #" << cnum << ": " << flush;
		auto ans = solve();
		cout << ans << endl;
	}
}
