#include "bits/stdc++.h"

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;

using namespace std;

#ifdef LOCAL
#include "debug.h"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define Print(...) (void)42;
#define eprintf(...) (void)42;
#endif

int T;
set<pair<string, string> > q;
pair<string, string> mas[20];
set<string> f, s;
int n;

void load () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		q.insert (make_pair (s1, s2));
		f.insert (s1);
		s.insert (s2);
		mas[i] = make_pair (s1, s2);
	}
}

void clear () {
	q.clear ();
	f.clear ();
	s.clear ();
}

int solve () {
	int tres = 0;

	for (int i = 0; i < 1 << n; i++) {
		f.clear ();
		s.clear ();

		bool bad = false;

		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
			}
			else {
				f.insert (mas[j].first);
				s.insert (mas[j].second);
			}
		}

		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				if (!f.count (mas[j].first) || !s.count (mas[j].second)) bad = true; 
			}
		}

		if (!bad) {
			tres = max (tres, __builtin_popcount (i));
		}
	}

	return tres;
}

int main () {
#ifdef LOCAL
	freopen ("file.in", "r", stdin);
	freopen ("file.out", "w", stdout);
#else
	//freopen (".in", "r", stdin);
	//freopen (".out", "w", stdout);
#endif 

#ifdef TIMER
	timer Tm;
	Tm.start ();
#endif

	cin >> T;

	for (int i = 1; i <= T; i++) {
		load ();
		printf ("Case #%d: %d\n", i, solve ());
		clear ();
		clog << i << endl;
	}
	

#ifdef TIMER
	Tm.stop ();
	Tm.print_time (stderr);
#endif

	return 0;
}