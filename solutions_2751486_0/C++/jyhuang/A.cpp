#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

bool is_vowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(int argc, char *argv[])
{
	int T, n;
	cin >> T;
	static char s[1000100];

	for (int ti = 1; ti <= T; ti++) {
		cin >> s >> n;
		vector<pair<int, int> > p;
		int j = -1, len = strlen(s);
		for (int i = 0; i < len; i++)
			if (is_vowel(s[i])) {
				if (j >= 0) {
					if (i - j >= n)
						p.push_back(make_pair(i, j));
				}
				j = -1;
			} else {
				if (j < 0) j = i;
			}
		if (j >= 0) {
			if (len - j >= n)
				p.push_back(make_pair(len, j));
		}

		long long ans = 0;

		for (int i = 0; i < len; i++) {
			vector<pair<int, int> >::iterator it = lower_bound(p.begin(), p.end(), make_pair(i + n, 0));
			if (it == p.end()) continue;
			// cout << it->second << ", " << it->first << endl;
			if (i <= it->second)
				ans += (long long) len - it->second - n + 1;
			else if (i + n - 1 <= it->first)
				ans += (long long) len - i - n + 1;
		}

		printf("Case #%d: %lld\n", ti, ans);
	}
	return 0;
}
