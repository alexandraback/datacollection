#include <cstdio>
#include <algorithm>
#include <vector>

#define all(x) x.begin (), x.end ()
#define pb push_back

using namespace std;

typedef long long int64;

typedef vector<int64> vint64;

int64 a, b;
vint64 s;

inline bool ok (const int64& x) {
	int t [21], j = 0;
	
	for (int64 i = x; i > 0; i /= 10)
		t [++j] = i % 10;
	
	for (int i = 1; i <= j; ++i)
		if (t [i] != t [j + 1 - i])
			return false;
	
	return true;
}

inline void preProcess () {
	for (int64 i = 1; i <= 10000000; ++i) {
		int64 j = i * i;
		
		if (ok (i) && ok (j))
			s.pb (j);
	}
}

int main () {
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);
	
	preProcess ();
	
	int task; scanf ("%d\n", &task);
	for (int t = 1; t <= task; ++t) {
		scanf ("%I64d %I64d\n", &a, &b);
		printf ("Case #%d: %d\n", t, upper_bound (all (s), b) - lower_bound (all (s), a));
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
