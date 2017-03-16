#include <bits/stdc++.h>
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


void solve(int P) {
	char str[200], *s;
	scanf("%s", str);
	int f = 0;
	for (s = str+1; *s; ++s)
		if (*s != s[-1]) ++f;
	print("Case #%d: %d\n", P, f+(s[-1]=='-'));
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
