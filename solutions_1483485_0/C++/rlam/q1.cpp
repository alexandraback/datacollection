#include <iostream>
#include <string>
using namespace std;

int main()
{
	int case_num = 0;
	int i = 0;
	int j = 0;
	string s = "";
	char mapping[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

	cin >> case_num;
	getline (cin, s);
	for (i = 0; i < case_num; i++) {

		getline (cin, s);

		for (j = 0; j < s.length(); j++) {
			if (s[j] != ' ') {
				s[j] = mapping[s[j]-'a'];
			}
		}

		cout << "Case #" << i + 1 << ": " << s << endl;
	}
}

