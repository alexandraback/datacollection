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

char ul[10] = {'Z', '-', 'W', '-', 'U', '-', 'X', '-', 'G', '-'};
char nul[10] = {'-', 'O', '-', 'T', '-', 'F', '-', 'S', '-', '-'};
int cnt[26];

int pos(char c) { return c - 'A'; }

string dig[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void solve() {
	minit(cnt, 0);
	
	string S;
	cin >> S;
		
	int sz = S.size();	
	for_(i,0,sz) cnt[pos(S[i])]++;
	
	vector< int > ans;
	
	// ZERO, TWO, FOUR, SIX, EIGHT
	for_(i,0,10) {
		if (ul[i] == '-') continue;
		
		int c = cnt[pos(ul[i])];
		for_(j,0,c) ans.push_back(i);
		
		int m = dig[i].size();
		for_(j,0,m) cnt[pos(dig[i][j])] -= c;
	}
	
	// ONE, THREE, FIVE, SEVEN
	for_(i,0,10) {
		if (nul[i] == '-') continue;
		
		int c = cnt[pos(nul[i])];
		for_(j,0,c) ans.push_back(i);
				
		int m = dig[i].size();
		for_(j,0,m) cnt[pos(dig[i][j])] -= c;
	}
	
	// NINE
	int c = cnt[pos('I')];
	for_(j,0,c) ans.push_back(9);
	
	sort(allof(ans));
	
	int L = ans.size();
	for_(i,0,L) cout << ans[i];
}

int main() {
	int T;
	cin >> T;
	
	for_(t,0,T) {
		cout << "Case #" << t+1 << ": ";
		solve();
		cout << endl;
	}
}