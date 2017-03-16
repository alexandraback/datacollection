#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string theLastWord(string &str) {
	if (str.length() == 1) return str;
	stringstream ss;
	ss << str[0];
	string ret;
	ss >> ret;
	for (int i = 1; i < str.length(); ++i) {
		if (str[i] >= ret[0]) {
			string newStr;
			stringstream ss;
			ss << str[i];
			ss >> newStr;
			newStr.append(ret);
			ret = newStr;
		} else {
			stringstream ss;
			ss << str[i];
			string tmp;
			ss >> tmp;
			ret.append(tmp);
		}
	}
	return ret;
}

int main( int argc, char** argv ) {
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; ++i) {
		string str;
		cin >> str;
		cout << "Case #" << i + 1 << ": " << theLastWord(str) << endl;
	}
	return 0;
}
