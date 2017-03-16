#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <array>
#include <ctime>
#include <functional>
using namespace std;

char c[256];

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	c[' '] = ' ';
	c['y'] = 'a';
	c['n'] = 'b';
	c['f'] = 'c';
	c['i'] = 'd';
	c['c'] = 'e';
	c['w'] = 'f';
	c['l'] = 'g';
	c['b'] = 'h';
	c['k'] = 'i';
	c['u'] = 'j';
	c['o'] = 'k';
	c['m'] = 'l';
	c['x'] = 'm';
	c['s'] = 'n';
	c['e'] = 'o';
	c['v'] = 'p';
	c['z'] = 'q';
	c['p'] = 'r';
	c['d'] = 's';
	c['r'] = 't';
	c['j'] = 'u';
	c['g'] = 'v';
	c['t'] = 'w';
	c['h'] = 'x';
	c['a'] = 'y';
	c['q'] = 'z';
	int cases;
	in >> cases;
	in.get();
	for (int i = 1; i <= cases; ++i) {
		string str;
		getline(in, str);
		for (int j = 0; j < str.size(); ++j) {
			str[j] = c[str[j]];
		}
		out << "Case #" << i << ": " << str << endl;
	}
}