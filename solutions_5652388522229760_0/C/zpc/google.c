#include <stdio.h>
#include <stdlib.h>

int chars[10];
void clear_chars(){
	int i;
	for(i=0;i<10;i++)chars[i]=0;
}

int not_complete(){
	int i;
	for(i=0;i<10;i++){
		if(0==chars[i])return 1;
	}
	return 0;
}

void add_chars(int n){
	char s[20]="";
	sprintf(s,"%d",n);
	for(char *p=s;*p;p++){
		chars[*p-'0']+=1;
	}
}

int compute(int n){
	clear_chars();
	int result = n;
	add_chars(result);
	while(not_complete()){
		result+=n;
		add_chars(result);
	}
	
	return result;
}

int main(){
	int T,M,N,i,result,n;

	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	fscanf(input,"%d", &T);

	n=1;
	while(n<=T){
		fscanf(input, "%d", &N);
		if(0==N){
			fprintf(output, "Case #%d: INSOMNIA\n", n);
		}else{
			result = compute(N);
		
			fprintf(output, "Case #%d: %d\n", n, result);
		}
		n++;
	}

	return 0;
}
