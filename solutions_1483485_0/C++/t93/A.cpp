#include <iostream>
#include <string>

using namespace std;

string alp = "abcdefghijklmnopqrstuvwxyz";
string map = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	int t;
	string x;

	cin >> t;
	cin.get();

	for (int c = 0; c < t; c++)
	{
		getline(cin, x);
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] != ' ')
				x[i] = map[x[i]-'a'];
		}
		cout << "Case #" << c+1 << ": " << x << "\n";
	}
}
