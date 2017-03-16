#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define INPUT "A-small-attempt1.in"
#define OUTPUT "output.out"

long long int gcd(long long int divisor, long long int remainder){
#ifdef DEBUG
	printf("%lld %lld\n", divisor, remainder);
#endif
	if (remainder != 0)	return gcd(remainder, divisor % remainder);
	return divisor;
}
int main(int argc, char* argv[]){
	FILE *inf, *outf;

	int TestCase, N;
	int loop1, loop2, loop3;



	inf = fopen(INPUT, "r");
	outf = fopen(OUTPUT, "w+");
	
	fscanf(inf, "%d ", &TestCase);
	for (loop1 = 0; loop1 < TestCase; loop1++){

		unsigned long long int P, Q;
		unsigned long long int Percent, gc, checkBinary;

		int count = 0;
		int large = 0;
		fscanf(inf, "%lld/%lld ", &P, &Q);
		gc = gcd(P, Q);

		Q /= gc;
		P /= gc;
		//printf("%lld %lld\n", Q, P);
		checkBinary = Q;
		while(checkBinary!=1){
			if (!(checkBinary % 2)){
				checkBinary >>= 1;
			}
			else{
				break;
			//	printf("%lld\n", checkBinary);
			}
		}
		//printf("%lld\n", checkBinary);
		if (checkBinary!=1){
			fprintf(outf, "CASE #%d: impossible\n", loop1 + 1);
			continue;
		}while (Q!=1){
			
			
				Q >>= 1;
				count++;
				if (P >= Q){
					//printf("%lld ,%lld\n", P, Q);
					fprintf(outf, "CASE #%d: %d\n", loop1 + 1, count);
					break;
				}
				
			
		}
		
		
	}
	fclose(inf);
	fclose(outf);

	return 0;
}