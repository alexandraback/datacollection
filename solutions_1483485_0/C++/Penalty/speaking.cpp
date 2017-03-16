#include<iostream>
#include<map>

using namespace std;

int main()
{
	int n;
	cin>>n;
	map<char,char> m;
	m['a']='y';
	m['b']='h';
	m['c']='e';
	m['d']='s';
	m['e']='o';
	m['f']='c';
	m['g']='v';
	m['h']='x';
	m['i']='d';
	m['j']='u';
	m['k']='i';
	m['l']='g';
	m['m']='l';
	m['n']='b';
	m['o']='k';
	m['p']='r';
	m['q']='z';
	m['r']='t';
	m['s']='n';
	m['t']='w';
	m['u']='j';
	m['v']='p';
	m['w']='f';
	m['x']='m';
	m['y']='a';
	m['z']='q';
	m[' ']=' ';
	
	
	for(int i=0;i<=n;i++) {
	        string s;
	        getline(cin,s);
	        if(i>0) {
	                cout<<"Case #"<<i<<": ";
	                for(int j=0;j<s.size();j++) cout<<m[s[j]];
	                cout<<endl;
	        }
	}
	return 0;
}
