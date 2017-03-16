#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int products[12];

int main(void) {
	FILE* inp = fopen("inp.txt","r");
	FILE* out = fopen("out.txt","w");
	int t,r,n,m,k,i,ans,j;
	int n1,n2,n3,maxProduct;
	fscanf(inp,"%d",&t);
	fprintf(out,"Case #1:\n");
	fscanf(inp,"%d",&r);
	fscanf(inp,"%d",&n);
	fscanf(inp,"%d",&m);
	fscanf(inp,"%d",&k);
	
	for(i=0;i<r;i++){
		maxProduct = 0;
		for(j=0;j<k;j++){
			fscanf(inp,"%d",&products[j]);	
			if(products[j]>maxProduct) maxProduct = products[j];
		}
		if(maxProduct == 125){
			fprintf(out,"555\n");
			continue;
		}
		if(maxProduct == 64){
			fprintf(out,"444\n");
			continue;
		}
		if(maxProduct == 27){
			fprintf(out,"333\n");
			continue;
		}
		if(maxProduct == 25){
			fprintf(out,"555\n");
			continue;
		}
		if(maxProduct == 16){
			fprintf(out,"444\n");
			continue;
		}
		if(maxProduct == 6){
			fprintf(out,"223\n");
			continue;
		}
		if(maxProduct == 27){
			fprintf(out,"333\n");
			continue;
		}
		if(maxProduct == 20){
			fprintf(out,"544\n");
			continue;
		}
		if(maxProduct == 27){
			fprintf(out,"333\n");
			continue;
		}
		if(maxProduct == 48){
			fprintf(out,"443\n");
			continue;
		}
		if(maxProduct == 32){
			fprintf(out,"442\n");
			continue;
		}
		if(maxProduct == 27){
			fprintf(out,"333\n");
			continue;
		}
		if(maxProduct == 80){
			fprintf(out,"445\n");
			continue;
		}
		if(maxProduct == 27){
			fprintf(out,"333\n");
			continue;
		}
		if(maxProduct == 100){
			fprintf(out,"554\n");continue;
		}
		if(maxProduct == 75){
			fprintf(out,"553\n");
			continue;
		}
		if(maxProduct == 36){
			fprintf(out,"334\n");
			continue;
		}
		if(maxProduct == 45){
			fprintf(out,"335\n");
			continue;
		}
		if(maxProduct == 18){
			fprintf(out,"332\n");
			continue;
		}
		if(maxProduct == 8){
			fprintf(out,"423\n");
			continue;
		}
		if(maxProduct == 60){
			fprintf(out,"345\n");
			continue;
		}
		if(maxProduct == 24){
			fprintf(out,"234\n");
			continue;
		}
		if(maxProduct == 30){
			fprintf(out,"235\n");
			continue;
		}
		if(maxProduct == 40){
			fprintf(out,"245\n");
			continue;
		}
		if(maxProduct == 27){
			fprintf(out,"333\n");
			continue;
		}
		fprintf(out,"234\n");
		
	}
	
	return 0;
}
