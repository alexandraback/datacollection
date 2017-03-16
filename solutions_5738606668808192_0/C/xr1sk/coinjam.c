#include <stdio.h>
#include <math.h>
#include <assert.h>

#define LEN 16
#define REQ 50

long long parse(int *arr, int radix) {

    long long res = 0;
    for (int i = 0; i < LEN; i++) {
        res += arr[LEN - i - 1] * (long long) pow(radix, i);
    }

    assert(res >= 0);
    return res;
}

void show(int *arr) {
    for (int i = 0; i < LEN; i++) 
        printf("%d", arr[i]);
}

int main() {

    int count = 0;

    printf("Case #1:\n");

    for (int i = 0; i < pow(2, LEN - 2) && count != REQ; i++) {

        int str[LEN] = {}, cur = LEN - 2;
        str[0] = 1;
        str[LEN - 1] = 1;

        int t = i;

        while (t != 0) {
            str[cur--] = t % 2;
            t /= 2;
        }

        int divisors[11] = {};
        int outflag = 1; // this number is a coinjam

        for (int j = 2; j <= 10; j++) {

            long long rep = parse(str, j);
            int flag = 1; // a divisor does not exist in this base

            long long lim = sqrt(rep);
            for (int k = 2; k <= lim; k++) {

                if (rep % k == 0) {
                    divisors[j] = k;
                    flag = 0; // but it does...
                    break;
                }
            }

            if(flag == 1) {
                // at least one form is prime
                outflag = 0;
                break;
            }
        }

        if (outflag == 1) {
            show(str);
            printf(" ");
            for (int i = 2; i <= 10; i++)
                printf("%d ", divisors[i]);
            printf("\n");
            count++;
        }

   }

}

        


