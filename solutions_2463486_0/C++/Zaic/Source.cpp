#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>

using namespace std;

#ifdef ILIKEGENTOO
#define Eo(x) { cerr << #x << " = " << (x) << endl; }
#define E(x) { cerr << #x << " = " << (x) << "   "; }
#else
#define Eo(x)
#define E(x)
#endif
#define EO(x) Eo(x)
#if defined ILIKEGENTOO || !(defined __GXX_EXPERIMENTAL_CXX0X__)
template<typename T, size_t N> struct array { T val[N]; T& operator[](size_t n) { if(n >= N) assert(false); return val[n]; } T* begin() { return &val[0]; } T* end() { return &val[0]+N; } };
#else
#include <array>
#endif
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

typedef double real;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pip;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const real eps = 1e-8;
const real pi = acos(-1.0);
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

map<int64, int64> pysch;

bool isPalindrome(int64 val) {
	string s = to_string(val);
	for(int i = 0; i < s.length() / 2; i++) if(s[i] != s[s.length() - i - 1]) return false;
	return true;
}

int64 f(int64 val) {
	if(val <= 0) return 0;
	auto it = pysch.upper_bound(val);
	return it->second - 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for(int64 i = 1; i < 10 * 1000 * 1000 + 1807; i++) {
		if(!isPalindrome(i)) continue;
		int64 sq = int64(i) * i;
		if(!isPalindrome(sq)) continue;
		int64 val = pysch.size() + 1;
		pysch[sq] = val;
	}

	int T; cin >> T;
	for(int tt = 1; tt <= T; tt++) {
		Eo(tt);
		printf("Case #%d: ", tt);
	
		int64 a, b; cin >> a >> b;
		cout << f(b) - f(a - 1) << endl;
	}
	return 0;
}