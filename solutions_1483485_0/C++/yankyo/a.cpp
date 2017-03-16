
#include <iostream>

using namespace std;

//              abcdefghijklmnopqrstuvwxyz
char trans[] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	int cases;
	string s;

	cin >> cases;

	for (int cas = 1; cas <= cases; cas++)
	{
		s = "";
		while (s.length() == 0) getline(cin, s);
		cout << "Case #" << cas << ": ";
		for (int i = 0; i < s.length(); i++)
		{
			char c = s[i];
			if (c >= 'a' && c <= 'z') cout << trans[c-'a']; else cout << c;
		}
		cout << endl;
	}

	return 0;
}
