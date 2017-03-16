#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
char tran[128], text[1000];
int main(){
	tran[' '] = ' ';
	tran['a'] = 'y';
	tran['b'] = 'h';
	tran['c'] = 'e';
	tran['d'] = 's';
	tran['e'] = 'o';
	tran['f'] = 'c';
	tran['g'] = 'v';
	tran['h'] = 'x';
	tran['i'] = 'd';
	tran['j'] = 'u';
	tran['k'] = 'i';
	tran['l'] = 'g';
	tran['m'] = 'l';
	tran['n'] = 'b';
	tran['o'] = 'k';
	tran['p'] = 'r';
	tran['q'] = 'z';
	tran['r'] = 't';
	tran['s'] = 'n';
	tran['t'] = 'w';
	tran['u'] = 'j';
	tran['v'] = 'p';
	tran['w'] = 'f';
	tran['x'] = 'm';
	tran['y'] = 'a';
	tran['z'] = 'q';
	int t, i, time=0;
	scanf("%d ", &t);
	while(t--){
		gets(text);
		for(i=0; text[i]; i++)
			text[i] = tran[text[i]];
		printf("Case #%d: %s\n", ++time, text);
	}
	return 0;
}
