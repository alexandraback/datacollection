#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>

using namespace std;

int main(int argc, char *argv[]){
	map<char, char> coder;
	coder[' '] =  ' ';
	coder['a'] =  'y';
	coder['b'] =  'h';
	coder['c'] =  'e';
	coder['d'] =  's';
	coder['e'] =  'o';
	coder['f'] =  'c';
	coder['g'] =  'v';
	coder['h'] =  'x';
	coder['i'] =  'd';
	coder['j'] =  'u';
	coder['k'] =  'i';
	coder['l'] =  'g';
	coder['m'] =  'l';
	coder['n'] =  'b';
	coder['o'] =  'k';
	coder['p'] =  'r';
	coder['q'] =  'z';
	coder['r'] =  't';
	coder['s'] =  'n';
	coder['t'] =  'w';
	coder['u'] =  'j';
	coder['v'] =  'p';
	coder['w'] =  'f';
	coder['x'] =  'm';
	coder['y'] =  'a';
	coder['z'] =  'q';

	int T;
	cin >> T;
	char line1[101];
	cin.getline(line1, 101);
	coder['z'] = 'q';
	for (int i = 0; i < T; i++){
		cin.getline(line1, 101);
		cout << "Case #" << (i+1) << ": ";
		int size = cin.gcount() - 1;
		for (int j = 0; j < size; j++){
			cout << coder[line1[j]];
		}
		cout << endl;
	}
}
