#pragma comment(linker, "/STACK:66777216")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <assert.h>
#include <memory.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(a) (int)a.size()
#define fill(a, x) memset (a, x, sizeof(a))

#ifdef _DEBUG
	#define Eo(x) {cout << "# " << #x << " = " << (x) << endl;}
	#define E(x) {cout << "# " << #x << " = " << (x) << " ";}
	#define Ou(x) {cout << "# " << (x) << endl;}
#else
	#define Eo(x)
	#define E(x)
	#define Ou(x)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void sIO();
void iIO();
void fIO(string fn);
void TM();

int n, s, a[222], __, k, ss;
double cur, sc;
bool w[222];

int main() {
	sIO();
	scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		scanf("%d", &n);
		s = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			s += a[i];
		}
		cur = s * 2. / n;
		printf("Case #%d: ", _);
		fill(w, 0);
		ss = s;
		sc = 0;
		k = n;
		for (int i = 0; i < n; ++i)
			if (a[i] > cur) {
				w[i] = true;
				--k;
				//ss -= a[i];
				sc -= (cur - a[i]) / s;
			}
		sc /= k;
		//cur = ss * 2. / k;
		for (int i = 0; i < n; ++i)
			if (w[i]) printf("0.00000000000 "); else printf("%.16f ", ((cur - a[i]) / ss - sc) * 100);
		printf("\n");
	}
    return 0;
} 

inline void sIO() {
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
}

inline void iIO() {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
}

inline void fIO(string fn) {
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#else
	freopen ((fn + ".in").c_str(), "r", stdin);
	freopen ((fn + ".out").c_str(), "w", stdout);
#endif
}

inline void TM() {
#ifdef _DEBUG
	cout << endl << "# Time: " << clock() / 1000. << endl;
#endif
}