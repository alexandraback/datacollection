#include <stdio.h>

char s[2000];

int main() {
	int i,T,tt,N;
	scanf("%d\n",&T);
	for (tt=1;tt<=T;tt++) {
		scanf("%d %s\n",&N,s);
		int sum=0;
		int f=0;
		int d;
		for (i=1;i<=N;i++) {
			sum+=s[i-1]-'0';
			d=i-sum;
			if (d>0) f+=d,sum+=d;
		}
		printf("Case #%d: %d\n",tt,f);
	}
	return 0;
}
