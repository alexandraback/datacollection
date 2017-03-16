#include<stdio.h>
char s[1001],t[1001];
int map[1001];
main(){
	int i,j,k,T;
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
	map[' ']=' ';
	scanf("%d",&T);
	while(getchar()!='\n');
	k=0;
	while(T--){
		k++;
		gets(s);
		printf("Case #%d: ",k);
		for(i=0;s[i];i++){
			putchar(map[s[i]]);
		}
		puts("");
	}
	scanf(" ");
}
