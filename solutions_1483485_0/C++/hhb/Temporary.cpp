#include<stdio.h>

char map[]="yhesocvxduiglbkrztnwjpfmaq";
char str[128], res[128];
int main() {
	int T;
	scanf("%d", &T);
	gets(str);
	for(int c=1;c<=T;c++) {
		gets(str);
		int i;
		for(i=0;str[i];i++) {
			if(str[i]>='a'&&str[i]<='z') {
				res[i]=map[str[i]-'a'];
			} else {
				res[i]=str[i];
			}
		}
		res[i]=0;
		printf("Case #%d: %s\n", c, res);
	}
}