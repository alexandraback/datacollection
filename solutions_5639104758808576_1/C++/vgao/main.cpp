#include <iostream>
#include <string>
#include <cstddef>
#include <cstdio>

#pragma warning(disable : 4996)

using namespace std;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	size_t n; cin >> n;
	for (size_t i = 0; i < n; ++i) {
		size_t m, c = 0, a = 0; string s;
		cin >> m >> s;
		for (size_t j = 0; j <= m; ++j) {
			if (c < j) {
				a += j - c;
				c = j;
			}
			c += s[j] - '0';
		}
		cout << "Case #" << (i + 1) << ": " << a << endl;
	}
	return 0;
}