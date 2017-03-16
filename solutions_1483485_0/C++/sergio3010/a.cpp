#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


char resp[1000];
int n;
char str[1000];

int main(){
	resp['a'] = 'y';
	resp['b'] = 'h';
	resp['c'] = 'e';
	resp['d'] = 's';
	resp['e'] = 'o';
	resp['f'] = 'c';
	resp['g'] = 'v';
	resp['h'] = 'x';
	resp['i'] = 'd';
	resp['j'] = 'u';
	resp['k'] = 'i';
	resp['l'] = 'g';
	resp['m'] = 'l';
	resp['n'] = 'b';
	resp['o'] = 'k';
	resp['p'] = 'r';
	resp['q'] = 'z';
	resp['r'] = 't';
	resp['s'] = 'n';
	resp['t'] = 'w';
	resp['u'] = 'j';
	resp['v'] = 'p';
	resp['w'] = 'f';
	resp['x'] = 'm';
	resp['y'] = 'a';
	resp['z'] = 'q';
	gets(str);
	sscanf(str, "%d", &n);
	for(int cas = 1; cas <= n; cas++){
		printf("Case #%d: ",cas);
		gets(str);
		for(int i = 0; str[i]; i++){
			if(str[i] == ' ') printf(" ");
			else printf("%c",resp[str[i]]);
		}
		printf("\n");
	}
	return 0;
}
