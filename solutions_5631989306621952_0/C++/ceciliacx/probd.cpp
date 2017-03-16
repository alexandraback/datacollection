#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

string addNextLetter(string str, char ch) {
	if (str.length() == 0)
		str += ch;
	else {
		if (ch >= str[0])
			str = ch + str;
		else
			str = str + ch;
	}
	return str;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	cin >> N;
	for (int prob = 1; prob <= N; prob++) {
		char input[1005];
		cin >> input;
		int i = 0;
		string res = "";
		while (input[i]) {
			res = addNextLetter(res, input[i++]);
		}
		cout << "Case #" << prob << ": " << res << endl;
	}
	return 0;
}
