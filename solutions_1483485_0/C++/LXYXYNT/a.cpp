#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

map<char,char> ma;
char s[200];

void init(){
	ma.clear();
	ma['a']='y';
	ma['b']='h';
	ma['c']='e';
	ma['d']='s';
	ma['e']='o';
	ma['f']='c';
	ma['g']='v';
	ma['h']='x';
	ma['i']='d';
	ma['j']='u';
	ma['k']='i';
	ma['l']='g';
	ma['m']='l';
	ma['n']='b';
	ma['o']='k';
	ma['p']='r';
	ma['q']='z';
	ma['r']='t';
	ma['s']='n';
	ma['t']='w';
	ma['u']='j';
	ma['v']='p';
	ma['w']='f';
	ma['x']='m';
	ma['y']='a';
	ma['z']='q';
}

int main(){
	init();
	int _,cas=0;
	scanf("%d",&_);
	while (_--){
		gets(s);
		while (s[0]=='\0') gets(s);
		for (int i=0;i<strlen(s);++i)
			if (s[i]!=' ') s[i]=ma[s[i]];
		printf("Case #%d: %s\n",++cas,s);
	}
	return 0;
}
		
