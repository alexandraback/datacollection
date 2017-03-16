// ---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
// ---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#pragma argsused

int main() {
	int c;
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A.out");
	fin >> c;
	string str;
	getline(fin, str);
	for (int i = 0; i < c; i++) {

		getline(fin, str);
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == ' ') continue;
			switch (str[j]) {
			case 'e': str[j] = 'o'; break;
			case 'y': str[j] = 'a'; break;
			case 'j': str[j] = 'u'; break;
			case 'u': str[j] = 'j'; break;
			case 'p': str[j] = 'r'; break;
			case 'm': str[j] = 'l'; break;
			case 'l': str[j] = 'g'; break;
			case 's': str[j] = 'n'; break;
			case 'c': str[j] = 'e'; break;
			case 'k': str[j] = 'i'; break;
			case 'd': str[j] = 's'; break;
			case 'x': str[j] = 'm'; break;
			case 'v': str[j] = 'p'; break;
			case 'n': str[j] = 'b'; break;
			case 'r': str[j] = 't'; break;
			case 'i': str[j] = 'd'; break;
			case 'b': str[j] = 'h'; break;
			case 't': str[j] = 'w'; break;
			case 'a': str[j] = 'y'; break;
			case 'h': str[j] = 'x'; break;
			case 'w': str[j] = 'f'; break;
			case 'f': str[j] = 'c'; break;
			case 'o': str[j] = 'k'; break;
			case 'g': str[j] = 'v'; break;
			case 'q': str[j] = 'z'; break;
			case 'z': str[j] = 'q'; break;
			default:
				;
			}
		}
		fout << str << endl;
	}
	return 0;
}
// ---------------------------------------------------------------------------
