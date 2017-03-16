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

string f[4];

bool check(char c) {
	bool fail = false;

	for(int i = 0; i < 4; i++) {
		fail = false;
		for(int j = 0; j < 4; j++) if(f[i][j] != c && f[i][j] != 'T') {
			fail = true;
			break;
		}
		if(!fail) return true;
	}

	for(int i = 0; i < 4; i++) {
		fail = false;
		for(int j = 0; j < 4; j++) if(f[j][i] != c && f[j][i] != 'T') {
			fail = true;
			break;
		}
		if(!fail) return true;
	}

	for(int i = 0; i < 2; i++) {
		fail = false;
		int st = (i == 0 ? 0 : 3);
		int dr = -(i * 2 - 1);
		for(int j = 0; j < 4; j++) if(f[st + j * dr][j] != c && f[st + j * dr][j] != 'T') {
			fail = true;
			break;
		}
		if(!fail) return true;
	}

	return false;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; cin >> T;
	for(int tt = 1; tt <= T; tt++) {
		printf("Case #%d: ", tt);
		for(int i=0; i<4; i++) cin >> f[i];
		if(check('X'))
			puts("X won");
		else if(check('O'))
			puts("O won");
		else if((f[0]+f[1]+f[2]+f[3]).find('.') == string::npos)
			puts("Draw"); // loosers
		else
			puts("Game has not completed");
	}
	return 0;
}