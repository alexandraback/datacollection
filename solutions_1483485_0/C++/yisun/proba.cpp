#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

fstream in, out;

int t;

char table[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

char lookup(char x) {
	if (x == ' ') {
		return ' ';
	} else {
		return table[((int)x) - ((int)'a')];
	}
}

int main() {
	in.open("proba.in", fstream::in);
	out.open("proba.out", fstream::out);

	in >> t;
	char line[200];
	in.getline(line, 200);
    for (int i = 0; i < t; i++) {
		in.getline(line, 200);
		string input(line);
		string output;
		for (int i = 0; i < input.length(); i++) {
			output.push_back(lookup(input[i]));
		}

		out << "Case #" << i + 1 << ": " << output << endl;
	}
    
	in.close();
	out.close();

	return 0;
}
