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
	ifstream in("B-small-attempt0.in", ios_base::in);
	ofstream out("output.out", ios_base::out);

	int t = atoi(readline(&in).c_str());
	for (int i = 1; i <= t; i++) {
		string line = readline(&in);
		stringstream ss(line);
		long unsigned int a, b, k, x = 0, y, r = 0;
		ss >> a;
		ss >> b;
		ss >> k;
		while (x < a) {
			y = 0;
			while (y < b) {
				if ((x & y) < k)
					r++;
				y++;
			}
			x++;
		}
		cout << "Case #" << i << ": " << r << "\n";
		out << "Case #" << i << ": " << r << "\n";
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