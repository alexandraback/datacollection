#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
using namespace std;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	map<char, char> mm;
	 mm['a']='y';
	 mm['b']='h';
	 mm['c']='e';
	 mm['d']='s';
	 mm['e']='o';
	 mm['f']='c';
	 mm['g']='v';
	 mm['h']='x';
	 mm['i']='d';
	 mm['j']='u';
	 mm['k']='i';
	 mm['l']='g';
	 mm['m']='l';
	 mm['n']='b';
	 mm['o']='k';
	 mm['p']='r';
	 mm['q']='z';   
	 mm['r']='t';
	 mm['s']='n';
	 mm['t']='w';
	 mm['u']='j';
	 mm['v']='p';
	 mm['w']='f';
	 mm['x']='m';
	 mm['y']='a';
	 mm['z']='q';
	 mm[' ']=' ';


	string s, ss;
	int t;
	cin>>t; cin.ignore();
	for (int cs=0; cs<t; ++cs)
	{
		cout<<"Case #"<<cs+1<<": ";
		
		getline(cin, s);
		for (int j=0; j<s.size(); ++j)
			cout<<mm[s[j]];
		cout<<endl;
	}
}