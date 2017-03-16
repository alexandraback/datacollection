#include <iostream>
#include <vector>
#include <cstddef>
#include <limits>
#include <functional>
#include <algorithm>
#include <cstdio>

using namespace std;

#pragma warning(disable : 4996)

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	size_t cases; cin >> cases;
	for (size_t _ = 0; _ < cases; ++_) {
		size_t n, m = numeric_limits<size_t>::max(), s = 0; 
		cin >> n;
		vector<size_t> v(n);
		for (auto & x : v) {
			cin >> x;
			s += x;
		}
		for (size_t i = 1; i <= s; ++i) {
			size_t d = 0;
			for (auto x : v) {
				if (x > i) {
					x -= i;
					d += (x % i == 0 ? 0 : 1) + x / i;
				}
			}
			m = min(m, d + i);
		}
		cout << "Case #" << (_ + 1) << ": " << m << endl;
	}
	return 0;
}