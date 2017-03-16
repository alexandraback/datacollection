#include <iostream>
#include <string>
using namespace std;
string mp = "yhesocvxduiglbkrztnwjpfmaq";
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t = 0;
	cin >> t; getchar();
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		string s;
		getline(cin, s);
		for (int i = 0; i < s.length(); ++i)
			if (s[i] == ' ')
				putchar(' ');
			else
				putchar(mp[s[i] - 'a']);
		cout << endl;
	}
}