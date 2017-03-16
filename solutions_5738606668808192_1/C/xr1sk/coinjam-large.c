#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <gmp.h>

#define LEN 32
#define REQ 500

int main() {

    int count = 0;

    printf("Case #1:\n");

    for (long long i = 0; i < pow(2, LEN - 2) && count != REQ; i++) {

        mpz_t rep, lim, looper, ONE;

        mpz_init(rep);
        mpz_init(looper);
        mpz_init(lim);
        mpz_init(ONE);

        mpz_set_str(ONE, "1", 10);

        int  cur = LEN - 2;
        char str[LEN + 1];
        memset(str, '0', sizeof(char) * (LEN + 1));

        str[0] = '1';
        str[LEN - 1] = '1';
        str[LEN] = '\0';

        long long t = i;

        while (t != 0) {
            str[cur--] = '0' + t % 2;
            t /= 2;
        }
        
        char* divisors[11] = {};
        int outflag = 1; // this number is a coinjam

        for (int j = 2; j <= 10; j++) {

            mpz_set_str(rep, str, j);
            int flag = 1; // a divisor does not exist in this base

            mpz_set_str(lim, "10000", 10);
            mpz_set_str(looper, "2", 10);
            while (mpz_cmp(looper, lim) <= 0) {

                if (mpz_divisible_p(rep, looper)) {
                    divisors[j] = mpz_get_str(NULL, 10, looper);
                    flag = 0; // but it does...
                    break;
                }

                mpz_add(looper, looper, ONE);

            }

            if(flag == 1) {
                // at least one form is prime
                outflag = 0;
                break;
            }
        }

        mpz_set_str(rep, str, 2);
        if (outflag == 1) {
            mpz_out_str(stdout, 2, rep);
            printf(" ");
            for (int i = 2; i <= 10; i++) {
                printf("%s ", divisors[i]);
            }
                
            printf("\n");
            count++;
        }

   }

}
