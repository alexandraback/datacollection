#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int main()
{
	int T;
	scanf("%d", &T);
	int N, J;
	scanf("%d%d", &N, &J);

	printf("Case #1:\n");

	unsigned long long int jamcoin;
	for(jamcoin = (1ULL << (N - 1)) | 1; jamcoin < (1ULL << N); jamcoin += 2)
	{
		int base;
		int good = 1;
		for(base = 2; base < 10; base++)
		{
			mpz_t number;
			mpz_init(number);
			int b;
			for(b = N - 1; b >= 0; b--)
			{
				mpz_mul_ui(number, number, base);
				if((jamcoin >> b) & 1)
					mpz_add_ui(number, number, 1);
			}
			int k;
			for(k = 0; k < 10; k++)
				if(mpz_divisible_ui_p(number, primes[k]))
					break;
			mpz_clear(number);
			if(k == 10)
			{
				good = 0;
				break;
			}
		}
		if(good)
		{
			int b;
			for(b = N - 1; b >= 0; b--)
				printf("%d", (jamcoin >> b) & 1 ? 1 : 0);
			printf(" ");
			for(base = 2; base <= 10; base++)
			{
				mpz_t number;
				mpz_init(number);
				for(b = N - 1; b >= 0; b--)
				{
					mpz_mul_ui(number, number, base);
					if((jamcoin >> b) & 1)
						mpz_add_ui(number, number, 1);
				}
				int k;
				for(k = 0; k < 10; k++)
					if(mpz_divisible_ui_p(number, primes[k]))
					{
						printf("%d ", primes[k]);
						break;
					}
				mpz_clear(number);
			}
			printf("\n");
			J--;
			if(!J)
				return 0;
		}
	}
}
