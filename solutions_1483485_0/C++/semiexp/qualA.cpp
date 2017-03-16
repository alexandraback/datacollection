#include <cstdio>

//            abcdefghijklmnopqrstuvwxyz
char tbl[] = "yhesocvxduiglbkrztnwjpfmaq";

int N;
char in[1000];

int main()
{
	scanf("%d ", &N);
	for(int i=0;i<N;i++){
		gets(in);
		for(int j=0;in[j];j++) if(in[j]>='a'&&in[j]<='z') in[j] = tbl[in[j]-'a'];
		printf("Case #%d: ", i+1);
		puts(in);
	}
	return 0;
}
