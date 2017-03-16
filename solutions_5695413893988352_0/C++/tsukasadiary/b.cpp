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

void dfs(size_t i, string S, vector< string >& all, string cur) {
	if (i == S.size()) {
		all.push_back(cur);
		return;
	}
	
	if (S[i] == '?') {
		for_(dig,0,10) {
			char add = ('0' + dig);
			dfs(i + 1, S, all, string(cur + add));
		}
	} else {
		dfs(i + 1, S, all, string(cur + S[i]));
	}
}

set< int > makeSet(vector< string > v) {	
	set< int > res;
	
	for (string s: v) {
		stringstream ss(s);
		int a;
		ss >> a;
		res.insert(a);
	}
	
	return res;
}

string toStr(int c, int len) {
	stringstream ss;
	ss << c;
	
	string res;
	ss >> res;
	
	while ((int)res.size() < len) {
		res = '0' + res;
	}
	
	return res;
}

void small() {
	string C, J;
	cin >> C >> J;
	
	vector< string > allC, allJ;
	
	dfs(0, C, allC, "");
	dfs(0, J, allJ, "");
	
	set< int > sC = makeSet(allC);
	set< int > sJ = makeSet(allJ);
	
	int min_diff = 101010, min_c = 101010, min_j = 101010;
	
	for (int c : sC) for (int j : sJ) {
		if (min_diff > abs(c - j)) {
			min_diff = abs(c - j);
			min_c = c;
			min_j = j;
		} else if (min_diff == abs(c - j)) {
			if (min_c > c) {
				min_c = c;
			} else if (min_c == c) {
				if (min_j > j) {
					min_j = j;
				}
			}
		}
	}
	
	cout << toStr(min_c, C.size()) << " " << toStr(min_j, C.size());
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