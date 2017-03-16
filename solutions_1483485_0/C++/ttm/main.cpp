#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char conv[256];
	conv[100] = 'o';
	conv[101] = 'o';

conv[106] = 'u';

conv[112] = 'r';

conv[109] = 'l';

conv[121] = 'a';

conv[115] = 'n';

conv[108] = 'g';

conv[106] = 'u';

conv[121] = 'a';

conv[108] = 'g';

conv[99] = 'e';

conv[107] = 'i';

conv[100] = 's';

conv[107] = 'i';

conv[120] = 'm';

conv[118] = 'p';

conv[101] = 'o';

conv[100] = 's';

conv[100] = 's';

conv[107] = 'i';

conv[110] = 'b';

conv[109] = 'l';

conv[99] = 'e';

conv[114] = 't';

conv[101] = 'o';

conv[106] = 'u';

conv[115] = 'n';

conv[105] = 'd';

conv[99] = 'e';

conv[112] = 'r';

conv[100] = 's';

conv[114] = 't';

conv[121] = 'a';

conv[115] = 'n';

conv[105] = 'd';

conv[114] = 't';

conv[98] = 'h';

conv[99] = 'e';

conv[112] = 'r';

conv[99] = 'e';

conv[121] = 'a';

conv[112] = 'r';

conv[99] = 'e';

conv[114] = 't';

conv[116] = 'w';

conv[99] = 'e';

conv[115] = 'n';

conv[114] = 't';

conv[97] = 'y';

conv[100] = 's';

conv[107] = 'i';

conv[104] = 'x';

conv[119] = 'f';

conv[121] = 'a';

conv[102] = 'c';

conv[114] = 't';

conv[101] = 'o';

conv[112] = 'r';

conv[107] = 'i';

conv[121] = 'a';

conv[109] = 'l';

conv[118] = 'p';

conv[101] = 'o';

conv[100] = 's';

conv[100] = 's';

conv[107] = 'i';

conv[110] = 'b';

conv[107] = 'i';

conv[109] = 'l';

conv[107] = 'i';

conv[114] = 't';

conv[107] = 'i';

conv[99] = 'e';

conv[100] = 's';

conv[100] = 's';

conv[101] = 'o';

conv[107] = 'i';

conv[114] = 't';

conv[107] = 'i';

conv[100] = 's';

conv[101] = 'o';

conv[111] = 'k';

conv[121] = 'a';

conv[97] = 'y';

conv[107] = 'i';

conv[119] = 'f';

conv[97] = 'y';

conv[101] = 'o';

conv[106] = 'u';

conv[116] = 'w';

conv[121] = 'a';

conv[115] = 'n';

conv[114] = 't';

conv[114] = 't';

conv[101] = 'o';

conv[117] = 'j';

conv[106] = 'u';

conv[100] = 's';

conv[114] = 't';

conv[108] = 'g';

conv[107] = 'i';

conv[103] = 'v';

conv[99] = 'e';

conv[106] = 'u';

conv[118] = 'p';

conv['q'] = 'z';
conv['z'] = 'q';

	int cases;
	cin >> cases;
	string line;
	getline(cin, line);
	for (int i = 1; i <= cases; ++i) {
		getline(cin, line);
		cout << "Case #" << i << ": ";
		for (int j = 0; j < line.length(); ++j) {
			if (line[j] == ' ') cout << ' ';
			else {
				char tmp = conv[(int)line[j]];
				cout << tmp;
			}
		}
		cout << endl;
	}

	return 0;
}