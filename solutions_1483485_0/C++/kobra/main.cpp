#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

map<char,char> Al;
string s;

int main()
{
	Al['a'] = 'y';
	Al['b'] = 'h';
	Al['c'] = 'e';
	Al['d'] = 's';
	Al['e'] = 'o';
	Al['f'] = 'c';
	Al['g'] = 'v';
	Al['h'] = 'x';
	Al['i'] = 'd';
	Al['j'] = 'u';
	Al['k'] = 'i';
	Al['l'] = 'g';
	Al['m'] = 'l';
	Al['n'] = 'b';
	Al['o'] = 'k';
	Al['p'] = 'r';
	Al['r'] = 't';
	Al['s'] = 'n';
	Al['t'] = 'w';
	Al['q'] = 'z';
	Al['u'] = 'j';
	Al['v'] = 'p';
	Al['w'] = 'f';
	Al['y'] = 'a';
	Al['z'] = 'q';
	Al['x'] = 'm';
	Al[' '] = ' ';
	int N;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&N);
	getline(cin,s);
	for(int i = 0;i < N; i++)
	{
		getline(cin,s);
		for(int j = 0; j < s.size(); j++)
			s[j] = Al[s[j]];
		cout << "Case #" << i+1 << ": " << s << endl;
	}
	return 0;
}