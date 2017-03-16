#include<iostream>
#include<string>
using namespace std;

char table[256]={0};

int main()
{

	
	table['a']='y';table['b']='h';table['c']='e';table['d']='s';
	table['e']='o';table['f']='c';table['g']='v';table['h']='x';
	table['i']='d';table['j']='u';table['k']='i';table['l']='g';
	table['m']='l';table['n']='b';table['o']='k';table['p']='r';
	table['q']='z';table['r']='t';table['s']='n';table['t']='w';
	table['u']='j';table['v']='p';table['w']='f';table['x']='m';
	table['y']='a';table['z']='q';
	table[' ']=' ';

	int tcs;
	cin>>tcs;
	
	for(int t=1;t<=tcs;++t)
	{
		string str;while(str.length()==0){ getline(cin,str); }
		cout<<"Case #"<<t<<": ";

		for(int i=0;i<str.length();++i)cout<<table[str[i]];
		cout<<endl;
	}

	return 0;
}