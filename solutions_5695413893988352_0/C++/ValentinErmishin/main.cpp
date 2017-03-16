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
string s1, s2;
int mn;
string ans1, ans2;
ll J;

int comp (ll a, ll b) {
	string A = to_string (a);
	string B = to_string (b);
	
	if (A.size () > s1.size ()) return 1e9;
	if (B.size () > s2.size ()) return 1e9;
	
	while (A.size () < s1.size ())
		A = '0' + A;
	while (B.size () < s2.size ())
		B = '0' + B;

	for (int i = 0; i < (int) A.size (); i++) {
		if (s1[i] == '?') continue;
		if (s1[i] != A[i]) return 1e9;
	}
	for (int i = 0; i < (int) B.size (); i++) {
		if (s2[i] == '?') continue;
		if (s2[i] != B[i]) return 1e9;
	}

	int v = abs (a - b);

	if (v < mn) {
		mn = v;
		ans1 = A;
		ans2 = B;
		J = b;
	}
	else if (v == mn) {
		if (b < J) {
			ans1 = A;
			ans2 = B;
			J = b;
		}
	}
	return 0;
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
		cin >> s1 >> s2;
		mn = 1e9;
		J = 1e9;
		for (int a = 0; a < 1000; a++) {
			for (int b = 0; b < 1000; b++) {
				int v = comp (a, b);
			}	
		}
		printf ("Case #%d: %s %s\n", i, ans1.c_str (), ans2.c_str ());
		clog << i << endl;
	}
	

#ifdef TIMER
	Tm.stop ();
	Tm.print_time (stderr);
#endif

	return 0;
}