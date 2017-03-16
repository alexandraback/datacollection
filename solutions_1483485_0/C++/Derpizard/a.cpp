#include<iostream>
#include<map>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;

map<char, char> derp;


int main()
{
	derp['b']='h';
	derp['e']='o';
	derp['j']='u';
	derp['p']='r';
	derp['m']='l';
	derp['y']='a';
	derp['s']='n';
	derp['l']='g';
	derp['c']='e';
	derp['k']='i';
	derp['d']='s';
	derp['x']='m';
	derp['v']='p';
	derp['n']='b';
	derp['r']='t';
	derp['i']='d';
	derp['t']='w';
	derp['w']='f';
	derp['h']='x';
	derp['o']='k';
	derp['g']='v';
	derp['a']='y';
	derp['f']='c';
	derp['u']='j';
	derp['z']='q';
	derp['q']='z';

	int n;
	cin >> n >> ws;
	for(int i = 0; i < n; i++)
	{
		string s; getline(cin, s);
		cout << "Case #" << i+1 << ": ";
		for(int j = 0; j < s.size(); j++)
			cout << (!isalpha(s[j]) ? s[j] : derp[s[j]]);
		cout << endl;
	}
}
