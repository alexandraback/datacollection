#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int T;
	string s1, s2;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt)
	{
		cin >> s1;
		int n = s1.size();
		s2 = "";
		for (int i = 0; i < n; ++i)
			s2 = max(s2 + s1[i], s1[i] + s2);
		cout << "Case #" << tt << ": " << s2 << endl;
	}
	return 0;
}

