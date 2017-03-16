#include <iostream>
#include <string>

using namespace std;

string key1 = "ynficwlbkuomxsevzpdrjgthaq", key2 = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	int n = 0;
	cin >> n;

	string str = "";
	getline(cin, str);

	for(int i = 0; i < n; i++) {
		getline(cin, str);
		int len = str.length();
		for(int j = 0; j < len; j++)
		{
			if(str[j] != ' ') str[j] = key2[str[j] - 'a'];
		}

		cout << "Case #" << i+1 << ": " << str << endl;
	}

	return 0;
}