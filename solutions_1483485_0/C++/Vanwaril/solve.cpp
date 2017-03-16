#include <iostream>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

map<char, char> tr;


int main()
{
	tr['a'] = 'y';
	tr['b'] = 'h';
	tr['c'] = 'e';
	tr['d'] = 's';
	tr['e'] = 'o';
	tr['f'] = 'c';
	tr['g'] = 'v';
	tr['h'] = 'x';
	tr['i'] = 'd';
	tr['j'] = 'u';
	tr['k'] = 'i';
	tr['l'] = 'g';
	tr['m'] = 'l';
	tr['n'] = 'b';
	tr['o'] = 'k';
	tr['p'] = 'r';
	tr['q'] = 'z';
	tr['r'] = 't';
	tr['s'] = 'n';
	tr['t'] = 'w';
	tr['u'] = 'j';
	tr['v'] = 'p';
	tr['w'] = 'f';
	tr['x'] = 'm';
	tr['y'] = 'a';
	tr['z'] = 'q';
	int N;
	string newline;
	
	cin>>N;
	getline(cin,newline);
	// Case-independent stuff?
	
	// Cases:
	for(int t=1; t<=N; t++)
	{
		// Each Case:
		string str;
		
		// random variables
		
		// input variables
		getline (cin, str);
		
		// compute
		for(int i=0; i<str.size(); i++)
			if(str[i] != ' ') str[i] = tr[str[i]];
		
		printf("Case #%d: %s\n", t, str.c_str());
	}
	return 0;
}
