#include "jam.h"

map<char, char> mapping;

void populate() {
mapping['y']  = 'a';
mapping['n']  = 'b';
mapping['f']  = 'c';
mapping['i']  = 'd';
mapping['c']  = 'e';
mapping['w']  = 'f';
mapping['l']  = 'g';
mapping['b']  = 'h';
mapping['k']  = 'i';
mapping['u']  = 'j';
mapping['o']  = 'k';
mapping['m']  = 'l';
mapping['x']  = 'm';
mapping['s']  = 'n';
mapping['e']  = 'o';
mapping['v']  = 'p';
mapping['z']  = 'q';
mapping['p']  = 'r';
mapping['d']  = 's';
mapping['r']  = 't';
mapping['j']  = 'u';
mapping['g']  = 'v';
mapping['t']  = 'w';
mapping['h']  = 'x';
mapping['a']  = 'y';
mapping['q']  = 'z';
mapping[' ']  = ' ';

}

void solve(int casenum) {
string temp;
getline(in, temp);

for(int i=0;i<temp.size();i++) {
temp[i] = mapping[temp[i]];
}

out << "Case #" << casenum << ": " << temp << endl;

}




int main() {
	cout << "!!!Hello World!!!" << endl;
    populate();
	in.open("input.txt.in");
	out.open("output.txt");
	int T;
	in >> T;
    string temp;
    getline(in, temp);
	for (int i=0;i<T;i++) {
        solve(i+1);
    }
    
    system ("pause");
	return 0;
}
