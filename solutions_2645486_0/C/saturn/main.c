#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
static int values[10000];

int main(void) {
	FILE* inp = fopen("inp.txt","r");
	FILE* out = fopen("out.txt","w");
	int caseCount = 0;
	int test = 0,i;
	int n,e,r;
	long long int ans =0,sum;
	int max = 0,maxIndex=0;
	//float ans = 0.0f;
	int cur = 0;
	fscanf(inp,"%d",&test);
	for(caseCount =1;caseCount<=test;caseCount++){
		fscanf(inp,"%d",&e);
		fscanf(inp,"%d",&r);
		fscanf(inp,"%d",&n);
		if(r>e) r =e;
		max =0;
		sum =0;
		for(i=0;i<n;i++){
			fscanf(inp,"%d",&values[i]);
			if(values[i]>=max){
				max = values[i];
				maxIndex = i;
			} 
			sum+= values[i];
		}
		ans =0;
		cur = e;
		if(e ==r){
			ans = sum*e;
			goto print;
		}
		for(i=0;i<n;i++){
			if(i == maxIndex){
				ans += (cur)*values[i];
				cur = r;
				continue;
			}
			if(i+1>=n){
				ans += cur * values[i];
				continue;
			}
			if(values[i]>values[i+1]){
				ans += (r+1)*values[i];
				cur -= r+1;
				cur += r;
				if(cur>e) cur =e;
			}
			else{
				if(cur ==e){
					ans += r*values[i];
					cur = e;
					
				}
				else{
				if(cur+r-e>0){
				
				ans += (cur+r-e)*values[i];
			}
		
				cur += r;
				if(cur>e) cur =e;
				}
				
			}
		}
	//	ans = e *(max) + r*(sum-max);
		print:
		fprintf(out,"Case #%d: %lld\n",caseCount,ans);
	}
	return 0;
}
