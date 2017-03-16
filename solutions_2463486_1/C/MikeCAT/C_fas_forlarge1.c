#include <stdio.h>
#include <string.h>

int isPalindrome(long long n) {
	char buf[32];
	int i,len;
	sprintf(buf,"%lld",n);
	len=strlen(buf);
	for(i=0;i<len-i-1;i++) {
		if(buf[i]!=buf[len-i-1])return 0;
	}
	return 1;
}

int oknum;
long long oklist[10000000];

int main(void) {
	int T,caseCount;
	long long A,B;
	int i;
	oknum=0;
	for(i=0;i<=10000000;i++) {
		if(i%100000==0)fprintf(stderr,"%d/100\n",i/100000);
		if(isPalindrome(i)) {
			long long now=(long long)i*i;
			if(isPalindrome(now))oklist[oknum++]=now;
		}
	}
	fprintf(stderr,"Total %d fair and square numbers found.\n",oknum);
	scanf("%d",&T);
	for(caseCount=1;caseCount<=T;caseCount++) {
		int left,right,mid;
		int Apos,Bpos;
		scanf("%lld%lld",&A,&B);
		left=0;right=oknum-1;
		while(left<=right) {
			mid=(left+right)/2;
			if(oklist[mid]<A)left=mid+1; else right=mid-1;
		}
		Apos=left-1;
		left=0;right=oknum-1;
		while(left<=right) {
			mid=(left+right)/2;
			if(oklist[mid]<=B)left=mid+1; else right=mid-1;
		}
		Bpos=left-1;
		printf("Case #%d: %d\n",caseCount,Bpos-Apos);
	}
	return 0;
}
