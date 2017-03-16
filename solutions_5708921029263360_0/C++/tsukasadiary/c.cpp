// tsukasa_diary's programing contest code template
#include <bits/stdc++.h>
using namespace std;
#define TSUKASA_DIARY_S_TEMPLATE
// define
#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define for_rev(i,a,b) for(int i=(a);i>=(b);--i)
#define allof(a) (a).begin(),(a).end()
#define minit(a,b) memset(a,b,sizeof(a))
#define size_of(a) int((a).size())
#define cauto const auto
// typedef
typedef long long lint;
typedef double Double;
typedef pair< int, int > pii;
template< typename T > using Vec = vector< T >;
template< typename T > using Matrix = Vec< Vec< T > >;
template< typename T > using USet = unordered_set< T >;
template< typename T, class C > using MyUSet = unordered_set< T, C >;
template< typename T, typename F > using UMap = unordered_map< T, F >;
template< typename T, typename F, class C > using MyUMap = unordered_map< T, F, C >;
// hash
class PiiHash { public: size_t operator () (const pii& p) const { return (p.first << 16) | p.second; } };
// popcount
inline int POPCNT(int x) { return __builtin_popcount(x); }
inline int POPCNT(lint x) { return __builtin_popcount(x); }
// inf
const int iINF = 1L << 30;
const lint lINF = 1LL << 60;
// eps
const Double EPS = 1e-9;
const Double PI = acos(-1);
// inrange
template< typename T >
inline bool in_range(T v, T mi, T mx) { return mi <= v && v < mx; }
template< typename T >
inline bool in_range(T x, T y, T W, T H) { return in_range(x,0,W) && in_range(y,0,H); }
// neighbor clockwise
const int DX[4] = {0,1,0,-1}, DY[4] = {-1,0,1,0};
const int DX_[8] = {0,1,1,1,0,-1,-1,-1}, DY_[8] = {-1,-1,0,1,1,1,0,-1};
// variable update
template< typename T > inline void modAdd(T& a, T b, T mod) { a = (a + b) % mod; }
template< typename T > inline void minUpdate(T& a, T b) { a = min(a, b); }
template< typename T > inline void maxUpdate(T& a, T b) { a = max(a, b); }
// converter
template< typename F, typename T >
inline void convert(F& from, T& to) {
	stringstream ss;
	ss << from; ss >> to;
}

struct Unit { int j, p, s; };

int J, P, S, K;
vector< Unit > units;
int cntJP[11][11], cntPS[11][11], cntSJ[11][11];

vector< Unit > ans;

void dfs(int i, vector< Unit >& cur) {
	if (i == (int)units.size()) {
		if (ans.size() < cur.size()) ans = cur;
		return;
	}
	
	// use
	Unit u = units[i];
	
	if (cntJP[u.j][u.p] < K && cntPS[u.p][u.s] < K && cntSJ[u.s][u.j] < K) {
		cntJP[u.j][u.p]++;
		cntPS[u.p][u.s]++;
		cntSJ[u.s][u.j]++;
		
		cur.push_back(u);
		dfs(i + 1, cur);
		cur.pop_back();
		
		cntJP[u.j][u.p]--;
		cntPS[u.p][u.s]--;
		cntSJ[u.s][u.j]--;
	}
	
	// not use
	dfs(i + 1, cur);
	
	return;
}

void solve() {
	cin >> J >> P >> S >> K;
	
	units.clear();
	
	minit(cntJP, 0);
	minit(cntPS, 0);
	minit(cntSJ, 0);
	
	for_(j,0,J) for_(p,0,P) for_(s,0,S) {
		units.push_back(Unit{j, p, s});
	}
	
	ans.clear();
	vector< Unit > cur;
	dfs(0, cur);
	
	int A = ans.size();
	cout << A << endl;
	for_(i,0,A) cout << ans[i].j + 1 << " " << ans[i].p + 1 << " " << ans[i].s + 1 << endl;
}

int main() {
	int T;
	cin >> T;
	
	for_(i,0,T) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}	
