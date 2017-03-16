#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cc, cn; cin >> cn;

	for (int cc = 1; cc <= cn; cc++)
	{
		string s; cin >> s;
		int cnt = 0;

		for (int i = 1; i < s.length(); i++)
			cnt += s[i] != s[i - 1];
		cnt += s[s.length() - 1] != '+';

		cout << "Case #" << cc << ": " << cnt << endl;
	}

	return 0;
}