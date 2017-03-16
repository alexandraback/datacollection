#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
const int maxn=1000;
char map[maxn];
string s;
int i,j,n,m,tests;

int main()
{
	map['a']='y';
	map['b']='h';
	map['c']='e';
	map['d']='s';
	map['e']='o';
	map['f']='c';
	map['g']='v';
	map['h']='x';
	map['i']='d';
	map['j']='u';
	map['k']='i';
	map['l']='g';
	map['m']='l';
	map['n']='b';
	map['o']='k';
	map['p']='r';
	map['q']='z';
	map['r']='t';
	map['s']='n';
	map['t']='w';
	map['u']='j';
	map['v']='p';
	map['w']='f';
	map['x']='m';
	map['y']='a';
	map['z']='q';
	scanf("%d\n",&tests);
	for (i=1;i<=tests;i++)
	{
		getline(cin,s);
		for (j=0;j<s.size();j++)
			if ((s[j]>='a')&&(s[j]<='z'))
				s[j]=map[s[j]];
		cout<<"Case #"<<i<<": "<<s<<endl;
	}
	return 0;
}
