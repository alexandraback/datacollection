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

int arr[123][123];
int mrow[123], mcol[123];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; cin >> T;
	for(int tt = 1; tt <= T; tt++) {
		printf("Case #%d: ", tt);
		int n, m; cin >> n >> m;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> arr[i][j];
		memset(mrow, 0xC8, sizeof(mrow));
		memset(mcol, 0xC8, sizeof(mcol));

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				mrow[i] = max(mrow[i], arr[i][j]);
				mcol[j] = max(mcol[j], arr[i][j]);
			}
		}

		bool ok = true;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(arr[i][j] != min(mrow[i], mcol[j]))
					ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}