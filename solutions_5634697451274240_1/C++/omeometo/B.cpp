#include <stdio.h>
#include <string.h>
main(){
	int testcases;
	scanf("%d ",&testcases);
	for(int casenum=1;casenum<=testcases;casenum++){
		printf("Case #%d: ",casenum);
		char buf[10101];
		scanf("%s",buf);
		int chg=0;
		int l=strlen(buf);
		for(int i=0;i+1<l;i++)if(buf[i]!=buf[i+1])chg++;
		if(buf[l-1]=='+')printf("%d\n",chg);
		else printf("%d\n",chg+1);
	}
}