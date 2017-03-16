#include<stdio.h>      
#include<stdlib.h>      
#include<math.h>  
#include <algorithm>
#include <iostream>

int main() { 
	
	int T,i,j;
	scanf("%d",&T);
	
	for (i=1; i<=T; i++)
	{
		int N;
		scanf("%d", &N);
		
		double naomi[N], ken[N];
		for (j=0;j<N;j++) scanf("%lf",&naomi[j]);
		std::sort(naomi,naomi+N);
		for (j=0;j<N;j++) scanf("%lf",&ken[j]);
		std::sort(ken, ken+N);
		
		int war=0;
		int index_ken=N-1, index_naomi=N-1;
		while ((index_ken>=0)&&(index_naomi>=0)){
			if (ken[index_ken]>naomi[index_naomi]) {
				index_ken--;
				index_naomi--;
			}
			else {
				index_naomi--;
				war++;
			}
		}
		
		
		int d_war=0;
		index_ken=0; index_naomi=0;
		while ((index_ken<=N-1)&&(index_naomi<=N-1)){
			if (ken[index_ken]>naomi[index_naomi]) {
				index_naomi++;
			}
			else {
				index_ken++;
				index_naomi++;
				d_war++;
			}
		}

		
		
		

		
		printf("Case #%d: %d %d\n",i,d_war,war);
	}
	
	return 0;
}

