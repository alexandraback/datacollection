#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	FILE* inp = fopen("inp.txt","r");
	FILE* out = fopen("out.txt","w");
	int caseCount = 0;
	int test = 0,i;
	long long int t,r,ans;
	//float ans = 0.0f;
	
	fscanf(inp,"%d",&test);
	for(caseCount =1;caseCount<=test;caseCount++){
		fscanf(inp,"%llu",&r);
		fscanf(inp,"%llu",&t);
		
		ans = 0;
		while(t>0){
			t -= (2*r+1);
			if(t<0) break;
			r+=2;
			
			ans++;
		}
		fprintf(out,"Case #%d: %llu\n",caseCount,ans);
	}
}
