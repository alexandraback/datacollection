#include <iostream>
#include <string>

using namespace std;

int main()
{
	int c;
	cin >> c;
	for (int cc = 1; cc <= c; cc++)
	{
		string s;
		cin >> s;
		string t;
		t += s[0];
		for (int i = 1; i < s.length(); i++)
			if (s[i] >= t[0])
				t = s[i] + t;
			else
				t += s[i];
		cout << "Case #" << cc << ": " << t << endl;
	}
}