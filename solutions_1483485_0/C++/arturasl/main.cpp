#include      <iostream>
#include      <fstream>
#include      <map>
#include      <string>

using namespace std;

map<char, char> mapSBox;

void makeSBox() {
	//mapSBox[' '] = ' ';
	//mapSBox['y'] = 'a';
	//mapSBox['e'] = 'o';
	//mapSBox['q'] = 'z';

	//ifstream fpFrom("test_input"), fpTo("test_output");
	//char chFrom, chTo;

	//while (fpFrom >> chFrom && fpTo >> chTo) {
		//mapSBox[chFrom] = chTo;
	//}

	//for (map<char, char>::const_iterator it = mapSBox.begin(); it != mapSBox.end(); ++it) {
		//cout << "mapSBox['" << it->first << "'] = '" << it->second << "';";
	//}

	//fpFrom.close();
	//fpTo.close();

	mapSBox[' '] = ' ';mapSBox['a'] = 'y';mapSBox['b'] = 'h';mapSBox['c'] = 'e';mapSBox['d'] = 's';mapSBox['e'] = 'o';mapSBox['f'] = 'c';mapSBox['g'] = 'v';mapSBox['h'] = 'x';mapSBox['i'] = 'd';mapSBox['j'] = 'u';mapSBox['k'] = 'i';mapSBox['l'] = 'g';mapSBox['m'] = 'l';mapSBox['n'] = 'b';mapSBox['o'] = 'k';mapSBox['p'] = 'r';mapSBox['q'] = 'z';mapSBox['r'] = 't';mapSBox['s'] = 'n';mapSBox['t'] = 'w';mapSBox['u'] = 'j';mapSBox['v'] = 'p';mapSBox['w'] = 'f';mapSBox['x'] = 'm';mapSBox['y'] = 'a';
}

int main(int argc, char **argv) {
	makeSBox();
	int nTests;
	freopen("input", "r", stdin);
	cin >> nTests;
	cin.ignore(256, '\n');
	string strLine;

	for (int nTest = 1; nTest <= nTests; ++nTest) {
		getline(cin, strLine);
		for (string::iterator it = strLine.begin(); it != strLine.end(); ++it) {
			*it = mapSBox[*it];
		}

		cout << "Case #" << nTest << ": " << strLine << endl;
	}

	return 0;
}
