#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int cn; cin >> cn;
	for (int cc=1; cc<=cn; cc++)
	{
		int len;
		string s;
		cin >> len >> s;

		int fn = 0;
		int sum = 0;
		for (int i=0; i<s.length(); i++)
		{
			int t = s[i] - '0';
			fn = max(fn, i - sum);
			sum += t;
		}

		cout << "Case #" << cc << ": " << fn << endl;
	}
	return 0;
}
