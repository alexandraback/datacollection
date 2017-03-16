/*
 * Ba.c
 *
 *  Created on: May 5, 2012
 *      Author: shix6
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmp ( const void *a , const void *b )
{
return *(int *)a - *(int *)b;
}

int main(void) {
	int t=0, cnt=1;
	double avr=0;
	int i,j,k;
	int s[210]={0}, os[210]={0};
	int n=0,overn=0;
	int sum=0;
	double needs;
	scanf("%d",&t);
	while(t-->0) {
		sum=0;
		scanf("%d", &n);
		for (i=0;i<n;++i) {
			scanf("%d",s+i);
			os[i]=s[i];
			sum+=s[i];
		}
		printf("Case #%d:",cnt);++cnt;
		avr=0;k=0;
		qsort(s,n,sizeof(s[0]),cmp);
		for(i=0;i<n;++i) {
			needs=0;
			avr=s[i];k=0;
			for(j=0;j<n;++j)
				if(s[j]<s[i]) {
					k++; needs+=s[i]-s[j];
				}
			if (needs>=sum)
				break;
		}
		overn=k;
		if (i==n) overn=n;
		avr=sum;
		for(i=0;i<overn;++i)
				avr+=s[i];
		avr/=overn;
		//printf("avr=%lf,overn=%d..",avr,overn);
		for (i=0;i<n;++i)
			printf(" %lf", (os[i]-avr>=0?0:(avr-os[i])*100.0/sum) );
		printf("\n");
	}
	return EXIT_SUCCESS;
}

