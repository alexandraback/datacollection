#include <cstdio>
#include <random>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 32;
const int J = 500;

unsigned int fastmul[11][168][32];

const int prime[168] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};

unsigned int excute(int base, unsigned val, int mod){
	unsigned result = 0;
	for (int i = 0; i < N; i++)
		if ((val >> i)&1) {
			result += fastmul[base][mod][i] % prime[mod];
            result %= prime[mod];
        }
	return result % prime[mod];
}

std::random_device rd;
std::uniform_int_distribution<unsigned int> dist(0, 1UL<<31);

unsigned int random(){
	return dist(rd);
}

void putbin(unsigned int x){
	for (int i = N - 1; i >= 0; i--)
		printf("%d", (x >> i)&1);
}

int prime_set[11] = {};

int main() {
	freopen("C.out", "w", stdout);
	printf("Case #1:\n");
	for (int i = 2; i <= 10; i++) {
        for (int k = 0; k < 168; k++) {
    		fastmul[i][k][0] = 1;
    		for (int j = 1; j < 32; j++)
    			 fastmul[i][k][j] = (fastmul[i][k][j - 1] * i) % prime[k];
        }
	}

	std::uniform_int_distribution<unsigned int> dist_s(0, 1UL<<(N - 1));

	int cnt = 0;
	while (cnt != J) {
		unsigned int num = dist_s(rd);
		num |= 1UL << (N - 1); num |= 1;
		bool ok = true;
        memset(prime_set, 0, sizeof(prime_set));
		for (int i = 2; i <= 10; i++) {
            bool found = false;
			for (int j = 0; j < 168; j++){
                unsigned x = excute(i, num, j);
                if (x == 0){
                    prime_set[i] = j;
                    found = true;
                    break;
                }
            }
            if (!found){
               // fprintf(stderr, "not found %d\n", i);
                ok = false;
                break;
            }
			
		}
        if (ok) {
            cnt++;
            putbin(num);
            for (int i = 2; i <= 10; i++) {
                printf(" %d", prime[prime_set[i]]);
            }
            puts("");
        }
	}
}