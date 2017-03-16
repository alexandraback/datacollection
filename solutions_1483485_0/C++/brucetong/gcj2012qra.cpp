//Problem: GCJ 2012 Qualification Round A
//Name: Speaking in Tongues
//Author: Bruce K. B. Tong

#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define SMALL
//#define LARGE

void init(char code[]) {
	//Googlerese => English
	code[' '] = ' ';
	code['a'] = 'y';
	code['b'] = 'h';
	code['c'] = 'e';
	code['d'] = 's';
	code['e'] = 'o';
	code['f'] = 'c';
	code['g'] = 'v';
	code['h'] = 'x';
	code['i'] = 'd';
	code['j'] = 'u';
	code['k'] = 'i';
	code['l'] = 'g';
	code['m'] = 'l';
	code['n'] = 'b';
	code['o'] = 'k';
	code['p'] = 'r';
	code['q'] = 'z';
	code['r'] = 't';
	code['s'] = 'n';
	code['t'] = 'w';
	code['u'] = 'j';
	code['v'] = 'p';
	code['w'] = 'f';
	code['x'] = 'm';
	code['y'] = 'a';
	code['z'] = 'q';
}

void print_decoded_message(char code[], string str) {
	for (int i = 0; i < str.length(); i++)
		printf("%c", code[str[i]]);
	printf("\n");
}

int main() {
	freopen("A-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("A-small-attempt0.in", "rt", stdin);
		freopen("A-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("A-large-practice.in", "rt", stdin);
		freopen("A-large-practice.out", "wt", stdout);
	#endif

	int T;			//1 <= T <= 30
	string str;		//max = 100
	char code['z'+1];
	
	init(code);

	cin >> T;
	getline(cin, str);

	for (int i = 1; i <= T; i++) {
		getline(cin, str);

		cout << "Case #" << i << ": ";
		print_decoded_message(code, str);
	}
	
	return 0;
}