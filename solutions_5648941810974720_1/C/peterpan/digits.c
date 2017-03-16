#include <stdio.h>

#define MAX_S 2000

int main()
{
	int tcase,T,freq[300],digits[10]={0,2,4,6,8,1,3,5,7,9},digitsFreq[10],i,d;
	char *cp,S[MAX_S+2], *words[10]={"ZERO","TWO","FOUR","SIX","EIGHT","ONE","THREE","FIVE","SEVEN","NINE"}, letters[11]="ZWUXGOHFSI";

	scanf("%d",&T);
	getchar();
	for(tcase=1;tcase<=T;tcase++)
	{
		for(i='A';i<='Z';i++)
			freq[i]=0;
		for(d=0;d<10;d++)
			digitsFreq[d]=0;
		scanf("%s",S);
		for(cp=S;*cp;cp++)
			freq[*cp]++;
		for(i=0;i<10;i++)
		{
			digitsFreq[digits[i]] = freq[letters[i]];
			for(cp=words[i];*cp;cp++)
				freq[*cp]-=digitsFreq[digits[i]];
		}
		printf("Case #%d: ", tcase);
		for(d=0;d<10;d++)
			for(i=0;i<digitsFreq[d];i++)
				printf("%d",d);
		printf("\n");
	}
	return 0;
}
