#include <iostream>
#include <vector>
using namespace std;
long long f(long long n) {
	return n * (n+1) / 2;
}
long long solve() {
	string s;
	long long n;
	cin >> s >> n;
	long long l = s.length();
	int p = -1;
	vector<pair<int,int> > a;
	for (int i = 0; i < l; ++ i) {
		if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') {
			if (p+1 < i && i-p-1 >= n) a.push_back(make_pair(p+1, i-p-1));
			p = i;
		}
	}
	if (p+1 < l && l-p-1 >= n) a.push_back(make_pair(p+1, l-p-1));
	if (a.size() == 0) return 0;
	
	long long r = f(l);
	r -= f(a.front().first);
	for (unsigned i = 1; i < a.size(); ++ i) {
		r -= f(a[i].first - (a[i-1].first + a[i-1].second));
	}
	r -= f(l - (a.back().first+a.back().second));

	for (unsigned i = 0; i < a.size(); ++ i) {
		r -= a[i].second * (n-1) - f(n-2);
	}

	r -= a.front().first * (n-1);
	r -= (n-1) * (n-1) * (a.size() - 1);
	for (unsigned i = 1; i < a.size(); ++ i) {
		int x = a[i].first - (a[i-1].first + a[i-1].second);
		r -= 2 * (n-1) * x;
	}
	r -= (l - (a.back().first+a.back().second)) * (n-1);
	return r;
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
}
