#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define forsn(i, s, n) for (int i = s; i < n; i++)

string solve(const string &s)
{
	string r;

	for (char c : s)
		r = max(c + r, r + c);

	return r;
}

int main()
{
	int t;
	cin >> t;

	forsn(z, 1, t + 1)
	{
		string s;
		cin >> s;

		printf("Case #%d: %s\n", z, solve(s).c_str());
	}

	return 0;
}
