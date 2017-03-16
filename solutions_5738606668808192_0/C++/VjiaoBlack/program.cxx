#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int N;

long myPow(long x, long p)
{
    if (p == 0) return 1;
    if (p == 1) return x;

    long tmp = myPow(x, p/2);
    if (p%2 == 0) return tmp * tmp;
    else return x * tmp * tmp;
}

long generate_max(int i) {
    long ans = 0;
    for (int j = 0; j < i; j++) {
        ans = ans << 1;
        ans |= 1;
    }

    return ans;
}


long get_number(long cur, int base) {
    long ans = 0;

    // printf("\nGet number: %ld, %d\n", cur, base);

    long mask = 0x1;

    for (int i = 0; i < N; i++) {
        int val = mask & cur;

        // printf(">>->> %d\n", val);

        if (val == 1) {
            ans += myPow(base, i);
        }
        cur = cur >> 1;
    }

    return ans;
}

bool is_divisible(long cur, int base, long divisor) {
    return (get_number(cur, base) % divisor) == 0;
//     long rem = 0;
//     int place = 0;

//     long mask = 0x1;

//     for (int i = 0; i < N; i++) {
//         int right_bit = mask & cur;

//         if (right_bit) {
//             if (i == 0) {
//                 rem += 1;
//             } else {
//                 for (int j = 0; j < i; j++) {

//                 }
//             }
//         }
//             rem += myPow(base, i);

//         rem = rem % divisor;

//         cur = cur >> 1;
//     }

//     // cout << "  " << rem << endl;

//     return rem == 0;

}


int main() {
    int T;
    cin >> T;

    long * divisors = new long[9];


    for (int i = 0; i < T; i++) {
        printf("Case #%d:\n", i+1);
        int J;

        cin >> N >> J;

        long max = generate_max(N);

        long cur = 1 | (1 << (N - 1));
        int generated = 0;
        while (cur <= max && generated < J) {
            int divisibles = 0;


            // cout << "  " << sqrt_cur << endl;


            for (int base = 2; base < 11; base++) {
                long divisor;



                long sqrt_cur = sqrt(get_number(cur, base));

                for (divisor = 2; divisor <= sqrt_cur; divisor++) {
                    if (is_divisible(cur, base, divisor)) {
                        divisors[base-2] = divisor;

                        // printf("  base: %d | %ld is divisible by %ld | stop: %ld\n", base, get_number(cur, base), divisor, sqrt_cur);
                        divisibles++;
                        break;
                    }
                }


            }
            if (divisibles == 9) {
                cout << bitset<16>(cur);

                for (int i = 0; i < 9; i++) {
                    printf(" %ld", divisors[i]/*, get_number(cur, i+2)*/);
                }
                printf("\n");
                generated++;
            } else {
                // cout << bitset<8>(cur) << endl;


            }


            cur+=2;
        }
    }
}
