#include <cstdio>
int Case;

int main() {
	char map[27] = "yhesocvxduiglbkrztnwjpfmaq";
	char s[105];
	
	scanf("%d", &Case);
	gets(s);
	for (int i=1;i<=Case;++i) {
		printf("Case #%d: ", i);
		
		gets(s);
		for (int j=0;s[j];++j)
			if ('a'<=s[j] && s[j]<='z') putchar(map[s[j] -'a']);
			else if ('A'<=s[j] && s[j]<='Z') putchar(map[s[j]-'a']-'a'+'A');
			else putchar(s[j]);
		puts("");
	}
	
	return 0;
}