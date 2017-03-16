#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// observation:
// for base N, 1...1, N^k = (N+1 -1)^k = r(N+1) +1 / -1
// first 1 => k(N+1)-1
// last 1 => k(N+1) +1
// just need to permutate the balance out 1s
int pow[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
int main(){
	int T;
	scanf("%d", &T);
	for(int tt =1; tt<=T; tt++){
		int n,j;
		scanf("%d %d", &n, &j);
		printf("Case #%d: \n",tt);
		int len = n/2 -1;
		for(int i=0; i<j; i++){
			int k = i;
			printf("1");
			for(int p =0; p<len ; p++, k>>=1){
				if(k%2) printf("11"); else printf("00");
			}
			printf("1");
			printf(" 3 4 5 6 7 8 9 10 11\n");
		}
	}
	return 0;
}
