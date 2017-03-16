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

template< typename T >
Matrix< T > operator + (const Matrix< T >& a, const Matrix< T >& b) {
	int n = size_of(a), m = size_of(a[0]);
	Matrix< T > res(n, Vec< T >(m, T()));
	for_(i,0,n) for_(j,0,m) res[i][j] = a[i][j] + b[i][j];
	return res;
}

template< typename T >
Matrix< T > operator - (const Matrix< T >& a, const Matrix< T >& b) {
	int n = size_of(a), m = size_of(a[0]);
	Matrix< T > res(n, Vec< T >(m, T()));
	for_(i,0,n) for_(j,0,m) res[i][j] = a[i][j] - b[i][j];
	return res;
}

template< typename T >
Matrix< T > operator * (const Matrix< T >& a, const Matrix< T >& b) {
	int n = size_of(a), m = size_of(b), l = size_of(b[0]);
	Matrix< T > res(n, Vec< T >(m, T()));
	for_(i,0,n) for_(k,0,l) for_(j,0,m) res[i][j] = a[i][k] * b[k][j];
	return res;
}

template< typename T >
Matrix< T > MatrixI(int n) {
	Matrix< T > res(n, Vec< T >(n, T()));
	for_(i,0,n) res[i][i] = T(1);
	return res;
}

template< typename T >
Matrix< T > POW(Matrix< T >& a, lint k) {
	int n = size_of(a);
	Matrix< T > res = MatrixI< T >(n);
	
	while (k > 0) {
		if (k & 1) res = res * a;
		a = a * a;
		k >>= 1;
	}
	
	return res;
}

int B, M;
Vec< pii > edges;

bool dfs(int i, Matrix< int >& mat) {
	if (i == (int)edges.size()) {
		Vec< int > p(B, 0);
		p[0] = 1;
		for_(i,0,B) for_(j,i+1,B) if (mat[i][j]) p[j] += p[i];
		return (p[B-1] == M);
	}
	
	pii p = edges[i];
	mat[p.first][p.second] = 1;
	if (dfs(i + 1, mat)) return true;
	mat[p.first][p.second] = 0;
	
	if (dfs(i + 1, mat)) return true;
	
	return false;
}

void solve() {
	cin >> B >> M;
	
	edges.clear();
	for_(i,0,B) for_(j,i+1,B) edges.push_back(pii(i,j));
	
	Matrix< int > mat(B, Vec< int >(B, 0));
	
	if (dfs(0, mat)) {
		cout << "POSSIBLE" << endl;
		for_(i,0,B) for_(j,0,B) cout << mat[i][j] << (j < B - 1 ? "" : "\n");
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}

int main() {
	int T;
	cin >> T;
	
	for_(i,0,T) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}	
}
