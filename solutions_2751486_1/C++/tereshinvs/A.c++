#include <iostream>
#include <string>

using namespace std;

bool isvowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	int t;
	cin >> t;

	for (int q = 0; q < t; q++) {
		string s;
		int m;
		cin >> s >> m;
		int last = -1, cur = 0;
		long long res = 0;
		for (int i = 0; i < s.size(); i++) {
			if (isvowel(s[i]))
				cur = 0;
			else
				cur++;
			if (cur >= m)
				last = i;
			if (last >= 0)
				res += (long long)(last - m + 2);
		}
		cout << "Case #" << q + 1 << ": " << res << endl;
	}
}