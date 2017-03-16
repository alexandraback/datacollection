#include <iostream>
#include <cstdio>
using namespace std;

char mapping[128];


char s[200];

int main()
{
	mapping['a']='y';
	mapping['b']='h';
	mapping['c']='e';
	mapping['d']='s';
	mapping['e']='o';
	mapping['f']='c';
	mapping['g']='v';
	mapping['h']='x';
	mapping['i']='d';
	mapping['j']='u';
	mapping['k']='i';
	mapping['l']='g';
	mapping['m']='l';
	mapping['n']='b';
	mapping['o']='k';
	mapping['p']='r';
	mapping['q']='z';
	mapping['r']='t';
	mapping['s']='n';
	mapping['t']='w';
	mapping['u']='j';
	mapping['v']='p';
	mapping['w']='f';
	mapping['x']='m';
	mapping['y']='a';
	mapping['z']='q';

	int numOfCases;
	scanf("%d", &numOfCases);
	gets(s);
	for(int i=1; i<=numOfCases; ++i)
	{
		printf("Case #%d: ", i);
		gets(s);
		for(int j=0; s[j]; ++j)
			if(s[j]>='a'&&s[j]<='z')
				printf("%c", mapping[s[j]]);
			else
				printf("%c", s[j]);
		printf("\n");
	}
	return 0;
}

