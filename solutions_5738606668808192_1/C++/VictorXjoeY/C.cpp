#include <bits/stdc++.h>

#define MAX 65537
#define BIG 1000000000000000000LL
// sqrt(4294967296) - needed

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;

int not_prime[MAX];
ull pot[11][33]; // Potencia y de x.
vector <ull> prime;
vector <ull> divs;

void genPots(){
	int i, j;

	for (i = 2; i <= 10; i++){
		pot[i][0] = 1;

		for (j = 1; pot[i][j - 1] < BIG; j++){
			pot[i][j] = pot[i][j - 1] * i;
		}

		// printf("%d: %d\n", i, j - 1);

		for (; j < 33; j++){
			pot[i][j] = 0;
		}
	}
}

void genPrimes(){
	ull i, j;

	for (i = 2 * 2; i < MAX; i += 2){
		not_prime[i] = 2;
	}

	for (i = 3; i < MAX; i += 2){
		if (!not_prime[i]){
			prime.push_back(i);

			for (j = i * i; j < MAX; j += i){
				not_prime[j] = i;
			}
		}
	}
}

void printBits(int x){
	bool flag = false;
	int i;

	for (i = 31; i >= 0; i--){
		if (x & (1 << i)){
			printf("1");

			flag = true;
		}
		else if (flag){
			printf("0");
		}
	}
}

ull convertFrom(ull x, int b){
	ull res = 0;
	int i;

	for (i = 0; i < 32; i++){
		if (x & (1 << i)){
			res += pot[b][i];
		}
	}

	return res;
}

ull notPrime(ull x){
	int i;

	// and prime[i] <= sqrt(x)
	for (i = 0; i < prime.size() and prime[i] < x; i++){
		if (x % prime[i] == 0){
			return prime[i];
		}
	}

	return 0;
}

int main(void){
	int T, N, J, i, k, counter;
	ull j, res, divisor;
	bool flag;

	genPrimes();
	genPots();

	scanf("%d", &T);

	for (i = 0; i < T; i++){
		scanf("%d%d", &N, &J);

		counter = 0;

		printf("Case #%d:\n", i + 1);

		// Iterando sobre as possibilidades.
		for (j = (1ULL << (N - 1)) + 1; j < (1ULL << N) and counter < J; j += 2){
			flag = true;

			for (k = 2; k <= 10; k++){
				res = convertFrom(j, k);

				if (!(divisor = notPrime(res))){
					flag = false;
					break;
				}
				
				divs.push_back(divisor);
			}

			if (flag){
				counter++;

				printBits(j);

				for (k = 0; k < divs.size(); k++){
					printf(" %llu", divs[k]);
				}
				printf("\n");
			}

			divs.clear();
		}
	}

	return 0;
}