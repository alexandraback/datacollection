#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

bool debug = false;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef map<string, int> msi;
typedef set<string> ss;
typedef set<pii> spii;

const double pi = 2.0*acos(0.0);

int CASES;

void init() {
  assert(scanf("%d", &CASES) == 1);
}

int print(const char *err, ...) {
  va_list pvar;
  va_start(pvar, err);
  vfprintf(stderr, err, pvar);
  return vfprintf(stdout, err, pvar);
}

int dprint(const char *err, ...) { 
  if (debug) {
    va_list pvar;
    va_start(pvar, err);
    return vfprintf(stderr, err, pvar);
  }
  return 0;
}


bool go(int R, int C, int M, vs &res) {
	res = vs(R, string(C, '*'));
	int Z = R*C-M;
	for (int w = 1; w <= C; ++w) {
		int lw = Z % w;
		int h = (Z/w)+!!lw;
		if (h > R) continue;
		if (!lw) lw += w;
		int lh = h - (lw != w);
		if (w == 1 && C != 1 && lh != 1) continue;
		if (h == 1 && R != 1 && lw != 1) continue;
		if ((w != 1 && h != 1) &&
			(lw == 1 || lh == 1)) continue;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (i < h-1 || j < lw) res[i][j] = '.';
		res[0][0] = 'c';
		return true;
	}
	return false;
}

void solve(int P) {
	int R, C, M;
	scanf("%d%d%d", &R, &C, &M);
	print("Case #%d:\n", P);
	vs res;
	if (go(R, C, M, res)) {
		for (auto &r: res)
			print("%s\n", r.c_str());
	} else if (go(C, R, M, res)) {
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j)
				print("%c", res[j][i]);
			print("\n");
		}
	} else if (R > 2 && C > 2 && M <= (R-2)*(C-2)) {
		res = vs(R, string(C, '.'));
		res[R-1][C-1] = 'c';
		for (int i = 0; i < R-2; ++i)
			for (int j = 0; j < C-2; ++j)
				if (i*(C-2)+j < M) res[i][j] = '*';
		for (auto &r: res)
			print("%s\n", r.c_str());
	} else {
		print("Impossible\n", R, C, M);
	}
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}


