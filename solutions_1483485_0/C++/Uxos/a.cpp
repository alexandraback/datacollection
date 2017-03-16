#include<stdio.h>
#include<string.h>
int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	char map[]="yhesocvxduiglbkrztnwjpfmaq";
	char actual[110];
	int n;
	gets(actual);
	sscanf(actual,"%d",&n);
	for(int i=1;i<=n;i++){
		fflush(stdin);
		gets(actual);
		printf("Case #%d: ",i);
		for(int j=0;j<strlen(actual);j++){
			if( actual[j]>='a' && actual[j]<='z' )
				printf("%c",map[actual[j]-'a']);
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
	
}
