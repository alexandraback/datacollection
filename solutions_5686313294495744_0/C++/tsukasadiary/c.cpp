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

int N, dp[1 << 20];
int fid[22], sid[22];
string ft[22], st[22];

map< string, int > id_map;

void solve() {
	minit(dp, 0);
	
	for_(S,0,1<<N) {
		lint vf = 0, vs = 0;
		
		for_(i,0,N) {
			if (S >> i & 1) {
				vf |= 1L << fid[i];
				vs |= 1L << sid[i];
			}
		}
		
		for_(i,0,N) {
			if (S >> i & 1) continue;
			
			bool flag = (vf >> fid[i] & 1) && (vs >> sid[i] & 1);
			
			for_(j,0,N) {
				if (!flag) break;
				
				if (S >> j & 1) {
					if (fid[i] == fid[j] && sid[i] == sid[j]) flag = false;
				}
			}
			
			maxUpdate(dp[S | (1 << i)], dp[S] + (flag ? 1 : 0));
		}
	}
	
	cout << dp[(1 << N) - 1];
}

void small() {
	cin >> N;
	
	id_map.clear();
	
	int id = 0;

	for_(i,0,N) {
		cin >> ft[i] >> st[i];
		
		if (id_map.count(ft[i]) == 0) {
			id_map[ft[i]] = id;
			++id;
		}
		
		if (id_map.count(st[i]) == 0) {
			id_map[st[i]] = id;
			++id;
		}
	}
	
	for_(i,0,N) {
		fid[i] = id_map[ft[i]];
		sid[i] = id_map[st[i]];
	}
	
	solve();
}

int main() {
	int T;
	cin >> T;
	
	for_(t,0,T) {
		cout << "Case #" << t+1 << ": ";
		small();
		cout << endl;
	}
}