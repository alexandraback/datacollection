#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
const int MaxN= 111;
const char str[30]= "yhesocvxduiglbkrztnwjpfmaq";
int T;
char ch;
int main(){
	scanf("%d", &T);
	for(int i= 1;i<= T;++ i){
		while((ch= getchar(), ch<'a' || ch>'z') && ch!=' ');
		printf("Case #%d: ", i);
		if(islower(ch)) putchar(str[ch-'a']); else putchar(ch);
		while((ch= getchar(), ch>='0' && ch<='z') || ch==' '){
			if(islower(ch))
				putchar(str[ch-'a']);
			else
				putchar(ch);
		}
		puts("");
	}
	return 0;
}
