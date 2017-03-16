#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>

using namespace std;

map<char,char> dic;
int n;
char s[105];
int main(int argc, char** argv) {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	dic['a'] = 'y';dic['b'] = 'h';dic['c'] = 'e';
	dic['d'] = 's';dic['e'] = 'o';dic['f'] = 'c';
	dic['g'] = 'v';dic['h'] = 'x';dic['i'] = 'd';
	dic['j'] = 'u';dic['k'] = 'i';dic['l'] = 'g';
	dic['m'] = 'l';dic['n'] = 'b';dic['o'] = 'k';
	dic['p'] = 'r';dic['q'] = 'z';dic['r'] = 't';
	dic['s'] = 'n';dic['t'] = 'w';dic['u'] = 'j';
	dic['v'] = 'p';dic['w'] = 'f';dic['x'] = 'm';
	dic['y'] = 'a';dic['z'] = 'q';dic[' '] = ' ';
	scanf("%d",&n);gets(s);
	for(int v = 1;v <= n; ++v){
		gets(s);
		int len = strlen(s);
		for(int i = 0;i < len; ++i) s[i] = dic[s[i]];
		printf("Case #%d: %s\n",v,s);
	}
	return 0;
}

