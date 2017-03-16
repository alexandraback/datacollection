#include <cstdio>

char map[27] = "yhesocvxduiglbkrztnwjpfmaq";

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int N;
	scanf("%d%*c", &N);
	for(int t = 1; t <= N; t++){
		char buf[1000];
		gets(buf);
		printf("Case #%d: ", t);
		for(int i = 0; buf[i]; i++)
			if(buf[i] == ' ')putchar(' ');
			else putchar(map[buf[i] - 'a']);
		putchar('\n');
	}
}