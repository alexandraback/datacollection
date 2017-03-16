#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int n,c=0;
	scanf("%d",&n);
	while(n>c) {
		c++;
		int N;
		scanf("%d",&N);
		int S[N];
		int sum=0;
		for(int i=0; i<N; i++) {
			int s;
			scanf("%d",&s);
			S[i]=s;
			sum+=s;
		}
		printf("Case #%d: ",c);
		for(int i=0; i<N; i++) {
			int O[N];
			memcpy(O,S,sizeof(int)*N);
			int votes = sum;
			int m=(i==0?1:0);
			for(int j=0; j<N; j++) {
				if(j==i) continue;
				if(O[j]<O[m]) m=j;
			}
			while(votes+S[i] > O[m] && votes>0) {
				votes--;
				O[m]++;
				for(int j=0; j<N; j++) {
					if(j==i) continue;
					if(O[j]<O[m]) m=j;
				}
			}
			for(int j=0; j<N; j++) {
				if(j==i) continue;
				if(O[j]<O[m]) m=j;
			}
			if(O[m]>S[i]+votes) votes++;
			printf("%lf ",(100*(double)votes/sum));
		}
		printf("\n");

	}
}
