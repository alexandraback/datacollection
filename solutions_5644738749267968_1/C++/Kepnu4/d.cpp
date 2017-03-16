#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <numeric>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

int n;

double a[2005], b[2005];

void load() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < n;i++) {
		cin >> b[i];
	}
}

int calc1 () {
	int res = 0;
	set <double> s;
	for (int i = 0;i < n;i++) {
		s.insert (b[i]);
	}

	for (int i = n - 1;i >= 0;i--) {
		if (s.lower_bound (a[i]) == s.end()) {
			res++;
			s.erase (s.begin());
		} else {
			s.erase (s.lower_bound (a[i]));
		}
	}
	return res;
}

int calc2() {
	int res = 0;
	int j = 0;
	for (int i = 0;i < n;i++) {
		if (a[i] > b[j]) {
			res++;
			j++;
		}
	}
	return res;
}

void solve(int test) {      	
	sort (a, a + n);
	sort (b, b + n);
	printf ("Case #%d: %d %d\n", test, calc2(), calc1());
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		cerr << "solving " << i << endl;
 		load();
 		solve(i);
 	}

 	return 0;
}