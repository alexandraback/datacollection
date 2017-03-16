#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t n; cin >> n;
	for (size_t i = 0; i < n; ++i) {
		string s; cin >> s;
		deque<char> v;
		for (auto c : s)
			if (v.empty() || c >= v.front())
				v.push_front(c);
			else
				v.push_back(c);
		cout << "Case #" << (i + 1) << ": " <<
			string(v.begin(), v.end()) << endl;
	}
	return 0;
}
