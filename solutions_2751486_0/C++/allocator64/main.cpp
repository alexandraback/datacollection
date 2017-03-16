#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long uint64;

bool isvov(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	ios_base::sync_with_stdio(0);
	int test_cases;
	cin >> test_cases;
	for (int test_num = 1; test_num <= test_cases; ++test_num) {
		cout << "Case #" << test_num << ": ";
		string s;
		int n;
		long long res = 0;
		cin >> s >> n;
		for (unsigned i = 0; i < s.size(); ++i) {
			for (unsigned j = i; j < s.size(); ++j) {
				bool ok = 0;
				unsigned pos = i;
				int cnt = 0;
				while (pos <= j) {
					if (!isvov(s[pos])) {
						++cnt;
						if (cnt >= n)
							ok = 1;
					} else
						cnt = 0;
					++pos;
				}
				if (ok)
					++res;
			}
		}
		cout << res << endl;
	}
	return 0;
}