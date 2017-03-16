/*
 * Eli Karasik
 * CodeJam 2012 - Qualification - A
 *
 * C++ - compile with any free compiler
 */


#include <iostream>
#include <string>

using namespace std;

char mapping[26];

void setMap(char i, char o) {
	mapping[o-'a'] = i;
}

char getMap(char i) {
	if (i == ' ') {
		return i;
	}
	return mapping[i-'a'];
}

int main() {

	setMap('a','y');
	setMap('b','n');
	setMap('c','f');
	setMap('d','i');
	setMap('e','c');
	setMap('f','w');
	setMap('g','l');
	setMap('h','b');
	setMap('i','k');
	setMap('j','u');
	setMap('k','o');
	setMap('l','m');
	setMap('m','x');
	setMap('n','s');
	setMap('o','e');
	setMap('p','v');
	setMap('q','z'); //only option
	setMap('r','p');
	setMap('s','d');
	setMap('t','r');
	setMap('u','j');
	setMap('v','g');
	setMap('w','t');
	setMap('x','h');
	setMap('y','a');
	setMap('z','q');
	

	int t;
	cin >> t;

	int i,j;
	string current;
	getline(cin,current);
	for (i = 0; i < t; i++) {
		getline(cin,current);
		for (j = 0; j < current.length(); j++) {
			current.replace(j,1,1,getMap(current.at(j)));
		}
		cout << "Case #"<< (i+1) << ": " << current << endl;
	}
}