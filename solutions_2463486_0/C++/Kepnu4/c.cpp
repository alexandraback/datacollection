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

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

long long A, B;

void load() {
	scanf ("%lld%lld", &A, &B);
}

bool palin (long long a) {
 	vector <int> cur;
 	while (a > 0) {
 	 	cur.push_back (a % 10);
 	 	a /= 10;
 	}

 	for (int i = 0;i < (int)cur.size();i++) {
 	 	if (cur[i] != cur[cur.size() - i - 1]) return false;
 	}
 	return true;
}

pair <long long, long long> getpaling (long long a) {
 	long long t = a;

 	vector <int> cur;
 	while (t > 0) {
 	 	cur.push_back (t % 10);
 	 	t /= 10;
 	}

 	pair <long long, long long> res = make_pair (a, a);

 	for (int i = 0;i < (int)cur.size();i++) {
 	 	if (i > 0) {
 	 	 	res.first = res.first * 10 + cur[i];
 	 	}
 	 	res.second = res.second * 10 + cur[i];
 	}

 	return res;
}

void solve(int test) {

	int ans = 0;

	for (int i = 1;;i++) {
		pair <long long, long long> a = getpaling (i);

		a.first *= a.first;
		a.second *= a.second;

		if (a.first > B) break;

		//cerr << i << " " << a.first << " " << a.second << endl;

	 	if (a.first >= A && a.first <= B && palin (a.first)) {
	 		ans++;
	 		//cerr << a.first << " " << i << endl;
	 	}

	 	if (a.second >= A && a.second <= B && palin (a.second)) {
	 	 	ans++;
	 	 	//cerr << a.second << " " << i << endl;
	 	}
	}

	printf ("Case #%d: %d\n", test, ans);
}

int main() {
 	freopen ("a.in", "r", stdin);
 	freopen ("a.out", "w", stdout);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}
