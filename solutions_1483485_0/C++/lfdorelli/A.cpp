#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;

#define F first
#define S second
#define pb push_back
#define mp make_pair

int mc(char c) {
	return c - 'a';
}	

int main (void)
{

	char map[256];

	map[' '] =  ' ';
	map['a'] = 'y';
	map['b'] = 'h';
	map['c'] = 'e';
	map['d'] = 's';
	map['e'] = 'o';
	map['f'] = 'c';
	map['g'] = 'v';
	map['h'] = 'x';
	map['i'] = 'd';
	map['j'] = 'u';
	map['k'] = 'i';
	map['l'] = 'g';
	map['m'] = 'l';
	map['n'] = 'b';
	map[('o')] = 'k';
	map[('p')] = 'r';
	map[('q')] = 'z';
	map[('r')] = 't';
	map[('s')] = 'n';
	map[('t')] = 'w';
	map[('u')] = 'j';
	map[('v')] = 'p';
	map[('w')] = 'f';
	map[('x')] = 'm';
	map[('y')] = 'a';
	map[('z')] = 'q';

	string in, out;


	int t;
	int caso = 1;
	cin >> t;
	scanf("\n");
	while(t--) {
		getline(cin, in);

		int S = in.size();
		printf("Case #%d: ", caso++);
		for(int i = 0; i < S; i++ ){
			printf("%c", map[in[i]]);
		}
		printf("\n");
	}
	return 0;
}
