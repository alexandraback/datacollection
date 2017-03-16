#include <stdio.h>
#include <map>
using namespace std;

char from[] = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvzq";
char to[] =   "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upqz";
map<char, char> translate;

int main(){
	for(int i=0;from[i];i++){
		translate[from[i]] = to[i];
	}
	for(char c = 'a'; c<='z'; c++){
		//printf("%c %c\n", c, translate[c]);
	}
	char rad[1024];
	gets(rad);
	for(int j=0;j<30;j++){
		gets(rad);
		for(int i=0;rad[i];i++){
			rad[i] = translate[rad[i]];
		}
		printf("Case #%d: %s\n", j+1, rad);
	}
}