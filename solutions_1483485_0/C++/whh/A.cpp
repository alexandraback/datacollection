#include <cstdio>

char r[] = "abcdefghijklmnopqrstuvwxyz";
char m[] = "yhesocvxduiglbkrztnwjpfmaq";
char line[200];

int main(){
	int T ;
	scanf("%d", &T);
	gets(line);
	for (int tc=1;tc<=T;++tc){
		gets(line);
		printf("Case #%d: ", tc);
		
		for (int i=0;line[i];++i){
			if (line[i] >= 'a' && line[i] <= 'z') printf("%c", m[line[i]-'a']);
			else printf("%c", line[i]);
		}
		
		puts("");
	}
	return 0;
}