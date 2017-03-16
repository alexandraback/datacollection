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

int A, B, K;

ll res[40][2][2][2];

ll Res(int z, int a, int b, int k) {
	if (z == -1) return 1;
	ll &r = res[z][a][b][k];
	if (r == 0) {
		r = 0;
		int Z = 1<<z;
		//		printf("Res(%d %d %d %d)\n", z, a, b, k);
		for (int aa = 0; aa <= (a | !!(A & Z)); ++aa) 
			for (int bb = 0; bb <= (b | !!(B & Z)); ++bb) {
				int kk = aa && bb;
				if (kk > (k | !!(K & Z))) continue;
				/*
				printf("   %d %d %d %d: aa %d bb %d -> kk %d, add R(%d, %d, %d, %d)\n",
					   z, a, b, k, aa, bb, kk, z-1, 						   a | (aa < !!(A&Z)), 
						   b | (bb < !!(B&Z)), 
						   k | (kk < !!(K&Z)));
				*/

				r += Res(z-1, 
						   a | (aa < !!(A&Z)), 
						   b | (bb < !!(B&Z)), 
						   k | (kk < !!(K&Z)));

				
			}
	}
	return r;
}

void solve(int P) {
	scanf("%d%d%d", &A, &B, &K);
	--A; --B; --K;
	memset(res, 0, sizeof(res));
	print("Case #%d: %lld\n", P, Res(30, 0, 0, 0));
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
