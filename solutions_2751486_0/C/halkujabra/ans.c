// This program assumes that the maximum length of the input strings is less than ~ 1Lac
#include "stdafx.h"
//This program would not harm the new lines given in input
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int isVowel(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		return 1;
	return 0;
}
long long int ans(char *s,int l,int n){
	int i,lcn=0,lc=-1,prev=-1;
	long long int sum = 0;
	for(i=0;i<l;++i)
	{
		if(isVowel(s[i]))
		{
			lcn=0;lc=-1;
		}
		else
		{
			lc=i;
			lcn++;
		}
		if(lcn>=n)
			prev=i-n+1;
		if(prev!=-1)
			sum+=prev+1;
	}
	return sum;
}

int main(void) {
		int i=0,t,n;
		scanf("%d\n",&t);
		char *str = (char *) malloc(1000005*sizeof(char));
		for(i=1;i<=t;++i)
		{
			scanf("%s %d\n",str,&n);
			int l = strlen(str);
			str[l]='\0';
			long long int a = ans(str,l,n);
			printf("Case #%d: %lld\n",i,a);
		}
			return 0;
}





