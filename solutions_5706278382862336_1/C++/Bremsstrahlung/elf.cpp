#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string readline(ifstream*);
vector<string> split(string*, char);

int main() {
	ifstream in("A-large.in", ios_base::in);
	ofstream out("output.out", ios_base::out);

	int t = atoi(readline(&in).c_str());
	for (int i = 1; i <= t; i++) {
		string line = readline(&in);
		vector<string> tokens = split(&line, '/');
		stringstream ss(tokens[0] + " " + tokens[1]);
		long long int a, b, s;
		int x = 0, y = 0, r = 0;
		bool impossible = false;
		ss >> a;
		ss >> b;
		
		s = b;
		while (!(s % 2)) {
			s /= 2;
		}

		if (a % s == 0) {
			b = b / s;
			a = a / s;
		}
		else
			impossible = true;

		while (a) {
			if (a % 2) {
				r = x;
			}
			x++;
			a = a >> 1;
		}
		while (b) {
			y++;
			b = b >> 1;
		}

		r = y - r - 1;
		if (!impossible && r) {
			cout << "Case #" << i << ": " << r << "\n";
			out << "Case #" << i << ": " << r << "\n";
		}
		else {
			cout << "Case #" << i << ": Impossible\n";
			out << "Case #" << i << ": Impossible\n";
		}
	}

	in.close();
	out.close();

	cin.ignore();
	return 0;
}

vector<string> split(string* s, char delim) {
	vector<string> result;
	stringstream ss(*s);
	string token;
	while (getline(ss, token, delim)) {
		result.push_back(token);
	}
	return result;
}

string readline(ifstream* in) {
	string result;
	getline(*in, result);
	return result;
}