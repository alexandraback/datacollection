#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double E = 2.71828182846;

const int N = 20;
int n;
string s1[N], s2[N];

int go () {
	int r = 0;
	int m = 2<<n;

	for (int i = 0; i < m; i++) {
		int res = 0;
		set < string > fake1;
		set < string > fake2;
		set < string > ori1;
		set < string > ori2;
		for (int j = 0; j < n; j++) {
			if (i & 1<<j) {
				ori1.insert(s1[j]);
				ori2.insert(s2[j]);
			} else {
				fake1.insert(s1[j]);
				fake2.insert(s2[j]);
				res ++;
			}
		}

		bool f = 1;
		for (set<string>::iterator it1 = fake1.begin(); f and it1 != fake1.end(); it1++) {
			if (ori1.count((*it1))) {
			} else {
				f = 0;
			}
		}
		for (set<string>::iterator it2 = fake2.begin(); f and it2 != fake2.end(); it2++) {
			if (ori2.count((*it2))) {
			} else {
				f = 0;
			}
		}

		if (f) {
			r = max (r, res);
		}

	}

	return r;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	int t;	cin >> t;
	for (int T = 1; T <= t; T++) {
		cout << "Case #" << T << ": ";
		cin >> n;
		for (int i = 0; i < n; i++) cin >> s1[i] >> s2[i];
		cout << go ();
		cout << endl;
	}

	return 0;
}
