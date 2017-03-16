#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int>& a, vector<int>& b)
{
	vector< pair<int, pair<int, int> > > e;
	for (int i = 0; i < n; ++i) {
		e.push_back(make_pair(a[i], make_pair(i, 1)));
		e.push_back(make_pair(b[i], make_pair(i, 2)));
	}
	sort(e.begin(), e.end());
	int cstar = 0;
	vector<int> done(n), half(n);
	for (int i = 0; i < 2 * n; ++i) {
		int need = e[i].first;
		for (int j = 0; j < i && need > cstar; ++j) {
			int level = e[j].second.first;
			if (!half[level] && !done[level]) {
				++cstar;
				half[level] = 1;
			}
		}
		if (need > cstar) {
			return -1;
		}
		int level = e[i].second.first;
		if (e[i].second.second == 2) {
			cstar += half[level] ? 1 : 2;
			done[level] = 1;
		}
	}
	return count(half.begin(), half.end(), 1) + count(done.begin(), done.end(), 1);
}

int main()
{
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}
		cout << "Case #" << test << ": ";
		int result = solve(n, a, b);
		if (result == -1) {
			cout << "Too Bad";
		} else {
			cout << result;
		}
		cout << endl;
	}
}
