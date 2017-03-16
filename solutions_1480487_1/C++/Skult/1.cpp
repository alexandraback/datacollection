#include <stdio.h>


int main(){


FILE *input;
FILE *output;
input = fopen("A-large.in","r");
output = fopen("output.txt", "w");
int cas,cases;
fscanf(input, "%d", &cases);
int num,n,jud[200],uj[200],j,i;
float ans[200];
float sum,x;
for(cas=0;cas<cases;cas++){
fscanf(input, "%d", &num);
x=0;
for (i=0;i<num;i++){
	fscanf(input, "%d", &jud[i]);
	x=x+jud[i];
}
for(i=0;i<num;i++){
	for(j=0;j<num;j++){
		uj[j]=0;
	}
	sum=0;
	for(j=0;j<num;j++){
		if(j!=i){
			sum=sum+(jud[i]-jud[j])/x;
		}
	}
	n=num;	
	ans[i]=(1-sum)/n;
	for(j=0;j<num;j++){
		if(jud[i]+x*ans[i]<jud[j] && uj[j]!=1){
			sum=sum-(jud[i]-jud[j])/x;
			n--;
			ans[i]=(1-sum)/n;
			uj[j]=1;
			j=0;
		}
	}
			

}


	fprintf(output, "Case #%d:", cas+1);
	for(i=0;i<num;i++){
		if (ans[i]<0){
			ans[i]=0;
		}
		fprintf(output," %f", 100*ans[i]);
	}
	fprintf(output, "\n");
}

fclose(input);
fclose(output);

	return 0;
}