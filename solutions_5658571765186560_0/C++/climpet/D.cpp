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

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
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


VV(pii) pols[7];

set<vector<pii>> st;
const int dd[5] = {0, -1, 0, 1, 0};

void normalize(vector<pii> &v){
	sort(ALL(v));
	int my = INT_MAX, mx = INT_MAX;
	for(auto &p : v){
		my = min(my, p.first);
		mx = min(mx, p.second);
	}
	for(auto &p : v){
		p.first -= my;
		p.second -= mx;
	}
}
void rot(vector<pii> &v){
	for(auto &p : v){
		p = pii(+p.second, -p.first);
	}
	normalize(v);
}

void dfs(vector<pii> &v){
	{
		auto w = v;
		bool ok = true;
		for(int i = 0; i < 4; ++i){
			rot(w);
			if(st.count(w)){
				ok = false;
				break;
			}
		}
		if(!ok){ return; }
		st.insert(w);
		pols[w.size()].push_back(move(w));
	}
	
	if(v.size() < 6){
		for(int i = v.size(); i--; ){
			for(int j = 0; j < 4; ++j){
				pii p(v[i].first + dd[j], v[i].second + dd[j + 1]);
				if(find(ALL(v), p) == v.end()){
					v.push_back(p);
					dfs(v);
					v.pop_back();
				}
			}
		}
	}
}

void prepare(){
	vector<pii> v(1);
	dfs(v);
}

bool check(int n, int r, int c, vector<pii> v){
	VV(char) vis;
	queue<pii> q;
	for(int z = 0; z < 2; ++z){
		for(int y0 = 1; y0 <= r; ++y0)
		for(int x0 = 1; x0 <= c; ++x0){
			initvv(vis, r + 2, c + 2);
			for(int i = 0; i <= r + 1; ++i){
				vis[i][0] = vis[i][c + 1] = 1;
			}
			for(int j = 0; j <= c + 1; ++j){
				vis[0][j] = vis[r + 1][j] = 1;
			}
			for(cauto p : v){
				int y = y0 + p.first, x = x0 + p.second;
				if(y <= 0 || y > r || x <= 0 || x > c){ goto fail; }
				if(vis[y][x]){ goto fail; }
				vis[y][x] = 1;
			}
			
			for(int y1 = 1; y1 <= r; ++y1)
			for(int x1 = 1; x1 <= c; ++x1){
				if(vis[y1][x1]){ continue; }
				q = queue<pii>();
				q.emplace(y1, x1);
				vis[y1][x1] = 1;
				int cnt = 1;
				while(!q.empty()){
					int y = q.front().first, x = q.front().second;
					q.pop();
					for(int d = 0; d < 4; ++d){
						int ny = y + dd[d], nx = x + dd[d + 1];
						if(!vis[ny][nx]){
							vis[ny][nx] = 1;
							q.emplace(ny, nx);
							++cnt;
						}
					}
				}
				if(cnt % n){ goto fail; }
			}

			return true;

			fail: ;
		}

		if(!z){ rot(v); }
	}
	return false;
}

bool solve2(){
	int n, r, c;
	cin >> n >> r >> c;
	if(r > c){ swap(r, c); }
	if(n > 6){ return false; }
	if(n > c){ return false; }
	if(n > 2 * r){ return false; }
	if(r * c % n){ return false; }
	
	VV(char) f;
	VV(char) vis;
	for(cauto v : pols[n]){
		if(!check(n, r, c, v)){
			return false;
		}
	}
	return true;
}

string solve(){
	return solve2() ? "GABRIEL" : "RICHARD";
}


}
int main(){
	cout << fixed << setprecision(15);
	cerr << fixed << setprecision(6);
	prepare();

	int T = 0;
	cin >> T;
	for(int cnum = 1; cnum <= T; ++cnum){
		fprintf(stderr, "%4d / %d\n", cnum, T);
		cout << "Case #" << cnum << ": " << flush;
		auto ans = solve();
		cout << ans << endl;
	}
}
