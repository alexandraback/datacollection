#include <cstdio>

char d[256];
int main() {
	d['a']='y';
	d['b']='h';
	d['c']='e';
	d['d']='s';
	d['e']='o';
	d['f']='c';
	d['g']='v';
	d['h']='x';
	d['i']='d';
	d['j']='u';
	d['k']='i';
	d['l']='g';
	d['m']='l';
	d['n']='b';
	d['o']='k';
	d['p']='r';
	d['q']='z';
	d['r']='t';
	d['s']='n';
	d['t']='w';
	d['u']='j';
	d['v']='p';
	d['w']='f';
	d['x']='m';
	d['y']='a';
	d['z']='q';
	d[' ']=' ';
	int n; scanf("%d ", &n);
	for(int i=0; i<n; i++) {
		printf("Case #%d: ", i+1);
		char x;
		while(scanf("%c", &x)==1 && x!='\n') {
			printf("%c", d[x]);
		}
		printf("\n");
	}
}
