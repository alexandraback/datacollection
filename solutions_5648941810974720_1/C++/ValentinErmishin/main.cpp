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
string nm[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[26];
string s;

void load () {
	cin >> s;
	for (int i = 0; i < (int) s.size (); i++) {
		cnt[s[i] - 'A']++;
	}
}

void clear () {
	for (int i = 0; i < 26; i++) cnt[i] = 0;
}

void add (int x) {
	for (int i = 0; i < (int) nm[x].size (); i++) {
		cnt[nm[x][i] - 'A']--;
	}
}

void sub (int x) {
	for (int i = 0; i < (int) nm[x].size (); i++) {
		cnt[nm[x][i] - 'A']++;
	}
}

bool check () {
	for (int i = 0; i < 26; i++) {
		if (cnt[i] < 0) return false;
	}
	return true;
}

string solve () {
	string res;
	while (0==0) {
		if (!cnt['Z' - 'A']) break;
		add (0);
		if (!check ()) {
			sub (0);
			break;
		}
		res += '0';
	}
	while (0==0) {
		if (!cnt['W' - 'A']) break;
		add (2);
		if (!check ()) {
			sub (2);
			break;
		}
		res += '2';
	}
	while (0==0) {		
		if (!cnt['X' - 'A']) break;
		add (6);
		if (!check ()) {
			sub (6);
			break;
		}
		res += '6';
	}
	while (0==0) {
		if (!cnt['G' - 'A']) break;
		add (8);
		if (!check ()) {
			sub (8);
			break;
		}
		res += '8';
	}
	while (0==0) {
		if (!cnt['S' - 'A']) break;
		add (7);
		if (!check ()) {
			sub (7);
			break;
		}
		res += '7';
	}
	while (0==0) {
		if (!cnt['H' - 'A']) break;
		add (3);
		if (!check ()) {
			sub (3);
			break;
		}
		res += '3';
	}
	while (0==0) {		
		if (!cnt['R' - 'A']) break;
		add (4);
		if (!check ()) {
			sub (4);
			break;
		}
		res += '4';
	}
	while (0==0) {
		if (!cnt['O' - 'A']) break;
		add (1);
		if (!check ()) {
			sub (1);
			break;
		}
		res += '1';
	}
	while (0==0) {
		if (!cnt['V' - 'A']) break;
		add (5);
		if (!check ()) {
			sub (5);
			break;
		}
		res += '5';
	}	
	while (0==0) {
		if (!cnt['N' - 'A']) break;
		add (9);
		if (!check ()) {
			sub (9);
			break;
		}
		res += '9';
	}
	sort (res.begin (), res.end ());
	return res;
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
		printf ("Case #%d: %s\n", i, solve ().c_str ());
		clear ();
		clog << i << endl;
	}
	

#ifdef TIMER
	Tm.stop ();
	Tm.print_time (stderr);
#endif

	return 0;
}