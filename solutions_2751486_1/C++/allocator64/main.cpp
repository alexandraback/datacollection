#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

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
		unsigned n;
		uint64 res = 0;
		cin >> s >> n;
		vector<uint64> pos;
		unsigned idx = 0;
		unsigned sum = 0;
		for (; idx < n - 1; ++idx)
			if (!isvov(s[idx]))
				++sum;
		for (; idx < s.size(); ++idx) {
			if (!isvov(s[idx]))
				++sum;
			if (sum == n)
				pos.push_back(idx);
			if (!isvov(s[idx - n + 1]))
				--sum;
		}
		pos.push_back(s.size());
		// copy(pos.begin(), pos.end(), ostream_iterator<uint64>(cout, " ")); cout << "\n";
		for (unsigned i = 0; i < pos.size() - 1; ++i)
			res += (pos[i] - n + 2) * (pos[i + 1] - pos[i]);
		cout << res << endl;
	}
	return 0;
}