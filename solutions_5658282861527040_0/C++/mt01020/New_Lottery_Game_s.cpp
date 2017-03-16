#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(int argc, char* argv[]){
    FILE *fin;
    fin = fopen(argv[1], "r");

    int T, A, B, K, result;
    fscanf(fin, " %d ", &T);
    for(int tc=0; tc<T; ++tc){
	result = 0;
	fscanf(fin, " %d %d %d ", &A, &B, &K);
	for(int fir=0; fir<A; ++fir){
	    for(int sec=0; sec<B; ++sec){
		//bit
		if((fir&sec) < K) ++result;
	    }
	}
	printf("Case #%d: %d\n", tc+1, result);
    }
    fclose(fin);

    return 0;
}
