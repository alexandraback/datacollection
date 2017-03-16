#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int T;
	char buf[110];
	freopen("a.in","r",stdin);
	freopen("a.res","w+",stdout);
	gets(buf);
	T=atoi(buf);
	map<char,char> dic;
	dic['a']='y';dic['b']='h';dic['c']='e';dic['d']='s';dic['e']='o';dic['f']='c';dic['g']='v';dic['h']='x';
	dic['i']='d';dic['j']='u';dic['k']='i';dic['l']='g';dic['m']='l';dic['n']='b';dic['o']='k';dic['p']='r';
	dic['q']='z';dic['r']='t';dic['s']='n';dic['t']='w';dic['u']='j';dic['v']='p';dic['w']='f';dic['x']='m';dic['y']='a';dic['z']='q';
	dic[' ']=' ';
	for(int tt=1;tt<=T;tt++)
	{
		gets(buf);
		cout<<"Case #"<<tt<<": ";
		for(int i=0,len=strlen(buf);i<len;i++)
			cout<<dic[buf[i]];
		cout<<endl;
	}
	return 0;
}

