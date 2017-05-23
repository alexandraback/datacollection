#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

string s;
int T;

ll Solve(string s)
{
	if (s == "1") return 1;

	int nd = s.length() / 2;
	ll add = 0;
	for (int i = s.length() - nd; i < s.length(); i++)
		add = 10ll * add + (s[i] - '0');
	if (add == 0) {
		for (int i = s.length() - 1; i >= 0; i--)
			if (s[i] == '0') s[i] = '9';
			else { s[i]--; break; }
		if (s[0] == '0') s.erase(s.begin(), s.begin() + 1);
		return 1 + Solve(s);
	} else {
		for (int i = s.length() - nd; i < s.length(); i++)
			s[i] = i + 1 == s.length()? '1': '0';
		string rev = s; reverse(rev.begin(), rev.end());
		if (rev < s) return Solve(rev) + add;
		else { s[s.length() - 1] = '0'; return Solve(s) + add; }
	}
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		cin >> s;
		printf("Case #%d: %lld\n", tc, Solve(s));
	}
	return 0;
}