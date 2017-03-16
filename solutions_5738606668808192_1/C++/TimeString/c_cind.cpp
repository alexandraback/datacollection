#include <stdio.h>
#include <vector>

using namespace std;

const int PRIME_BOUND = 100000;

bool is_not_prime[PRIME_BOUND + 1];
vector<int> primes;

bool even_divided(unsigned int bit_num, int base, int divisor) {
	bool big_enough = false;
	int sum = 0;
	int mul = 1;
	for (int i = 0; i < 32 && !big_enough; i++) {
		sum += (int)((bit_num & (1 << i)) > 0) * mul;
		if (sum > divisor)
			big_enough = true;
		mul *= base;
		if (mul > divisor)
			mul = divisor + 1;
	}
	if (!big_enough)
		return false;
	mul = 1;
	int remainder = 0;
	for (int i = 0; i < 32; i++) {
		remainder = (remainder + ((int)((bit_num & (1 << i)) > 0) * mul)) % divisor;
		mul = (mul * base) % divisor;
	}
	return remainder == 0;
}

int find_divisor(unsigned int bit_num, int base) {
	for (int i = 0; i < primes.size(); i++)
		if (even_divided(bit_num, base, primes[i]))
			return primes[i];
	return 0;
}

int main() {
	//even_divided(63, 2, 21);
	//return 0;

	for (int i = 2; i <= PRIME_BOUND; i++)
		if (is_not_prime[i] == false) {
			for (int j = i + i; j <= PRIME_BOUND; j += i)
				is_not_prime[j] = true;
			primes.push_back(i);
		}
	
	for (int i = 2; i <= 32; i++) {
		char out_name[1000];
		sprintf(out_name, "c_database_%d.txt", i);
		FILE *fout = fopen(out_name, "w");

		unsigned int n = 1;
		n |= (1 << (i-1));
		int ans_cnt = 0;
		int tmp[11];
		while (ans_cnt <= 500 && (n & (1 << (i-1)))) {
			int j;
			for (j = 2; j <= 10; j++) {
				int t = find_divisor(n, j);
				if (t == 0)
					break;
				tmp[j] = t;
			}
			if (j == 11) {
				for (int k = i-1; k >= 0; k--)
					fprintf(fout, "%d", (int)((n & (1 << k)) > 0));
				for (int k = 2; k <= 10; k++)
					fprintf(fout, " %d", tmp[k]);
				fprintf(fout, "\n");
				ans_cnt++;
				fprintf(stderr, "len=%d, idx=%d, ans=%x\n", i, ans_cnt, n);
			}
			//printf("%d, %u\n", i, n);
			n += 2;
		}

		fclose(fout);
	}

	return 0;
}
