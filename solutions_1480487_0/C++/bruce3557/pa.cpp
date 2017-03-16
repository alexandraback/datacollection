/*
 *  pa.cpp
 *  
 *
 *  Created by Bruce Kuo on 12/5/5.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

int n, sum;
int V[210];
double dsum;
double S[210];
double ans[210];

int main() {

	int t, cases=0;
	scanf("%d",&t);
	while(t--) {
		sum = 0;
		dsum = 0;
		scanf("%d",&n);
		for(int i=0;i<n;++i) {
			scanf("%d",V+i);
			S[i] = V[i];
			sum += S[i];
		}
		dsum = sum;
		double avg = 2*dsum/(double)n;
		
		double stv = 0;
		int cnt = 0;
		for(int i=0;i<n;++i)
			if( S[i] >= avg ) {
				++cnt;
				stv += S[i];
			}
		
		double avvg = avg;
		avg = (2*dsum-stv)/(double)(n-cnt);
		
		for(int i=0;i<n;++i) {
			if(S[i] >= avvg) {
				ans[i] = 0;
				continue;
			}
			ans[i] = (avg-S[i])/dsum;
			if(ans[i] < 0)	ans[i] = 0;
			if(ans[i] > 1)	ans[i] = 1;
			/*ans[i] = (2*dsum-n*S[i])/(n*dsum);
			double sv;
			for(int j=0;j<n;++j) {
				if(i == j)	continue;
				sv = (dsum+S[j]-S[i])/(2*dsum);
				if(sv < ans[i])	ans[i] = sv;
				sv = (dsum-S[i])/dsum;
				if(sv < ans[i])	ans[i] = sv;
			}
			if(ans[i] < 0)	ans[i] = 0;*/
		}
		printf("Case #%d:",++cases);
		for(int i=0;i<n;++i)
			printf(" %lf",ans[i]*100);
		puts("");
	}
	
	return 0;
}
