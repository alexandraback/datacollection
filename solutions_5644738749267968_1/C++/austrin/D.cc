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
typedef vector<double> vd;

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

int deceit(vd A, vd B) {
	int p = 0;
	while (!A.empty()) {
		if (A.back() > B.front()) {
			vd::iterator it = A.begin();
			while (*it < B.front()) ++it;
			++p;
			A.erase(it);
			B.erase(B.begin());
		} else {
			A.erase(A.begin());
			B.pop_back();
		}
	}
	return p;
}

int war(vd A, vd B) {
	int p = 0;
	while (!A.empty()) {
		if (A.back() > B.back()) {
			++p;
			A.pop_back();
			B.erase(B.begin());
		} else {
			A.pop_back();
			B.pop_back();
		}
	}
	return p;
}

void solve(int P) {
	int N;
	scanf("%d", &N);
	vd A(N), B(N);
	for (int i = 0; i < N; ++i)
		scanf("%lf", &A[i]);
	for (int i = 0; i < N; ++i)
		scanf("%lf", &B[i]);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	print("Case #%d: %d %d\n", P, deceit(A, B), war(A, B));
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
