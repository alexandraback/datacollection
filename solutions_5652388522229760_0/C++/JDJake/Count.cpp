#include <iostream>
#include <cstdio>

using namespace std;

bool found[15];

void reset() {
    for (int i = 0; i < 15; i++) found[i] = false;
}

bool finished() {
    for (int i = 0; i <= 9; i++) if (!found[i]) return false;
    return true;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        reset();

        long long N;
        scanf("%lld", &N);

        if (N == 0) {
            printf("Case #%d: INSOMNIA\n", i);
            continue;
        }

        long long current = N;
        //int num_zeroes_chopped = 0;
        while (!finished()) {
            //printf("%lld\n", current);
            //for (int i = 0; i <= 9; i++) printf("%d ", found[i]);
            //printf("\n");
            // Chop off bottom zeroes
            //while (current % 10) {
            //    found[0] = true;
            //    num_zeroes_chopped++;
            //    current /= 10;
            //}

            // Get digits in number
            long long temp = current;
            while (temp != 0) {
                int digit = temp % 10;
                found[digit] = true;
                temp /= 10;
            }

            if (finished()) break;

            current += N;
        }

        printf("Case #%d: %lld\n", i, current);
    }
}