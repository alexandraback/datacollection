#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compute(char *line, int len){
	int result=0;
	
	int i=0;
	for(i=0;i<len-1;i++){
		if(line[i+1]!=line[i]){
			result += 1;
		}
	}
	if(line[len-1] == '-')result += 1;
	
	return result;
}

int main(){
	int T,M,N,i,result,n;
	char c,line[101];
	int len=0;

	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	fscanf(input,"%d", &T);
	fgetc(input);

	n=1;
	while(n<=T){
		len=0;
		while((c=fgetc(input))!=EOF && c!='\n'){
			line[len++]=c;
			line[len]='\0';
		}
		
		result = compute(line,len);
		
		fprintf(output, "Case #%d: %d\n", n, result);
		n++;
	}

	return 0;
}
