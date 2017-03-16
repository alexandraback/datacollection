#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int compute(int K, int C, int S, int *A, int *len)
{
	int i;
	if(S<K)return -1;
	for(i=0;i<S;i++){
		A[i] = i+1;
	}
	*len = S;
	
	return 0;
}

int main()
{
	int T,K,C,S,i,len,n,A[101],result;

	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	fscanf(input,"%d", &T);

	n=1;
	while(n<=T){
		fscanf(input, "%d%d%d", &K, &C, &S);
		//assert(K==S);
		result = compute(K,C,S,A,&len);

		if(-1==result){
			fprintf(output, "Case #%d: IMPOSSIBLE\n", n);
		}else{
			fprintf(output, "Case #%d:", n);
			for(i=0;i<len;i++)fprintf(output, " %d", A[i]);
			fprintf(output, "\n");
		}
		n++;
	}

	return 0;
}
