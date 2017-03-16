#include <iostream>
using namespace std;

string translate = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	int T; cin >> T;
	string s; getline(cin, s);
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << t+1 << ": ";
	
		getline(cin, s);
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == ' ') cout << s[i];
			else cout << translate[ s[i]-'a' ];
		cout << endl;
	}
}

