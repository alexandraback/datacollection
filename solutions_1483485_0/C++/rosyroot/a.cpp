#include <iostream>
#include <string>

using namespace std;

char tr[26][2] = {
		'a', 'y',
		'b', 'h',
		'c', 'e',
		'd', 's',
		'e', 'o',
		'f', 'c',
		'g', 'v',
		'h', 'x',
		'i', 'd',
		'j', 'u',
		'k', 'i',
		'l', 'g',
		'm', 'l',
		'n', 'b',
		'o', 'k',
		'p', 'r',
		'q', 'z', //
		'r', 't',
		's', 'n',
		't', 'w',
		'u', 'j',
		'v', 'p',
		'w', 'f',
		'x', 'm',
		'y', 'a',
		'z', 'q' }; //

int main()
{
	int ncase;
	string str;
	string out;
	char *ch;

	cin >> ncase;
	int i, j;

	getline(cin, str);
	for (i = 0; i < ncase; i++)
	{
		getline(cin, str);
		ch = (char *)str.c_str();
		out.clear();
		for (j = 0; j < str.length(); j++)
		{
			if (ch[j] == ' ')
				out.push_back(' ');
			else
				out.push_back(tr[ch[j] - 'a'][1]);
		}

		cout << "Case #" << i + 1 << ": " << out.c_str() << endl;
	}
	return 0;
}
