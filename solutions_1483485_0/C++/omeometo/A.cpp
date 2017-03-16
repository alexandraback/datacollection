#include <stdio.h>

char convert(char c){
	if(c==' ')return ' ';
	else{
		char conv[]="yhesocvxduiglbkrztnwjpfmaq";
		return conv[c-'a'];
	}
}

main(){
	int cases;
	scanf("%d ",&cases);
	for(int casenum=1;casenum<=cases;casenum++){
		char buf[1000];
		gets(buf);
		printf("Case #%d: ",casenum);
		for(int i=0;buf[i];i++){
			printf("%c",convert(buf[i]));
		}
		puts("");
	}
}