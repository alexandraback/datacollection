#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

map<char, char> dict;

void init_map()
{
	dict['y'] = 'a';
	dict['n'] = 'b';
	dict['f'] = 'c';
	dict['i'] = 'd';
	dict['c'] = 'e';
	dict['w'] = 'f';
	dict['l'] = 'g';

	dict['b'] = 'h';
	dict['k'] = 'i';
	dict['u'] = 'j';
	dict['o'] = 'k';
	dict['m'] = 'l';
	dict['x'] = 'm';
	dict['s'] = 'n';

	dict['e'] = 'o';
	dict['v'] = 'p';
	dict['z'] = 'q';
	dict['p'] = 'r';
	dict['d'] = 's';
	dict['r'] = 't';

	dict['j'] = 'u';
	dict['g'] = 'v';
	dict['t'] = 'w';
	dict['h'] = 'x';
	dict['a'] = 'y';
	dict['q'] = 'z';
	
	dict[' '] = ' ';
}

char transform(char ch)
{
	return dict[ch];
}

int main()
{
	init_map();
	ifstream fin("input.txt");
	int n;
	fin>>n;

	string input;
	
	getline(fin, input, '\n');
	ofstream fout("output.txt");
	for (int i = 1;i <= n;++i)
	{
		getline(fin, input, '\n');
		string result;
		for (string::iterator it = input.begin(); it != input.end();++it)
		{
			result.push_back(transform((*it)));
		}
		fout<<"Case #"<<i<<": "<<result<<endl;
		//cout<<"Case #"<<i<<": "<<result<<endl;
	}
}