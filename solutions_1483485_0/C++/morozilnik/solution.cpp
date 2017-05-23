#include <iostream>
#include <string>
using namespace std;

string a;
string s,g;
int T;
char t1[]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
char l1[]="our language is impossible to understand";
char t2[]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char l2[]="there are twenty six factorial possibilities";
char t3[]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
char l3[]="so it is okay if you want to just give up";

int main()
{
	a.resize(260);
	a['a']='y';
a['b']='h';
a['c']='e';
a['d']='s';
a['e']='o';
a['f']='c';
a['g']='v';
a['h']='x';
a['i']='d';
a['j']='u';
a['k']='i';
a['l']='g';
a['m']='l';
a['n']='b';
a['o']='k';
a['p']='r';
a['q']='z';
a['r']='t';
a['s']='n';
a['t']='w';
a['u']='j';
a['v']='p';
a['w']='f';
a['x']='m';
a['y']='a';
a['z']='q';

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >>T; getline(cin, s);
	for (int q=1; q<=T; q++)
	{
		printf("Case #%d: ",q);
		getline (cin,s);
		g=s;
		for (int i=0; i<s.size(); i++)
			if (s[i]==' ') g[i]=' '; else		g[i]=(a[s[i]]);
		cout<<g<<endl;
	}
	
	return 0;
}