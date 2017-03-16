#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>

#define IN_RANGE(x, A, B)	((A <= x)&&(x <= B))

typedef struct _pair{
	unsigned int n;
	unsigned int m;
} Pair;

bool operator<(const Pair& a, const Pair& b) {
	if(a.n == b.n) return a.m < b.m;
	else return a.n < b.n;
}

unsigned int NUMBER_OF_DIGITS;

int recycle(const unsigned int n, const unsigned int start) {
	unsigned int div_base = pow(10, start), temp = n % div_base;
	//if(temp < div_base/10) return -1;
	return (n / div_base) + (temp * pow(10, NUMBER_OF_DIGITS - start));
}

int main(int argc, char** argv) {
	unsigned int T, A, B, i, n, k, m;
	
	//FILE *fp = fopen("input.txt", "r");
	FILE *fp = fopen("C-small-attempt0.in", "r");
	fscanf(fp, "%d", &T);
	//printf("T: %d\n", T);
	for(i=0; i<T; ++i) {
		fscanf(fp, "%d %d", &A, &B);
		NUMBER_OF_DIGITS = log10(A)+1;
		if(NUMBER_OF_DIGITS == 1) {
			printf("Case #%d: %d\n", i+1, 0);
			continue;
		}
		//printf("A: %d, B: %d (NoD: %d)\n", A, B, NUMBER_OF_DIGITS);
		
		std::set<Pair> pairs;
		
		for(n=A; n<=B; ++n) {
			//printf("%03d ::\t", n);
			for(k=1; k<NUMBER_OF_DIGITS; ++k) {
				m = recycle(n, k);
				if(n == m) {/*printf("[%03d]\t", m);*/ continue;}
				Pair new_pair = ((n < m) ? (Pair){n, m} : (Pair){m, n});
				if(IN_RANGE(m, A, B))
					pairs.insert(new_pair);
				
				//(IN_RANGE(m, A, B)) ? printf("%03d\t", m) : printf("[%03d]\t", m);
				//printf("%03d\t", m);
			}
			//putchar('\n');
		}
		
		/*
		std::set<Pair>::iterator pair_itr;
		for(pair_itr=pairs.begin(); pair_itr!=pairs.end(); ++pair_itr) {
			printf("(%d, %d)\n", pair_itr->n, pair_itr->m);
		}*/
		
		printf("Case #%d: %d\n", i+1, pairs.size());
	}
	fclose(fp);
	
	return EXIT_SUCCESS;
}

