#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

char table[26] = {
	'y', //'a'
	'h', //'b'
	'e', //'c'
	's', //'d'
	'o', //'e'
	'c', //'f'
	'v', //'g'
	'x', //'h'
	'd', //'i'
	'u', //'j'
	'i', //'k'
	'g', //'l'
	'l', //'m'
	'b', //'n'
	'k', //'o'
	'r', //'p'
	'z', //'q'
	't', //'r'
	'n', //'s'
	'w', //'t'
	'j', //'u'
	'p', //'v'
	'f', //'w'
	'm', //'x'
	'a', //'y'
	'q'  //'z'
};

int main(int argc, char *argv[]){
	unsigned int T;
	
	char line[256];

	if (argc >= 2){
		freopen(argv[1], "r", stdin);
		string outstr(argv[1]);
		int dot_pos = outstr.find_last_of('.');
		outstr = outstr.substr(0, dot_pos) + ".out";
		freopen(outstr.c_str(), "w", stdout);
	}

	cin >> T;
	cin.getline(line, 256);
	for (unsigned int k = 0; k < T; k++){
		
		cout << "Case #" << k + 1 << ": ";
		
		cin.getline(line, 256);
		
		char *c = line;
		do {
			if (*c >= 'a' && *c <= 'z')
				*c = table[*c - 'a'];
			cout << *c;
			c++;
		} while (*c != 0); 
		cout << endl;
	}
	return 0;
}
