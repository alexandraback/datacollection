#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAX = 10101010;

int T, palcount[MAX];
long long A, B;

bool is_palindrome(long long x) {
    long long rev = 0;
    long long temp = x;
    while (temp > 0) {
        rev = 10 * rev + temp % 10;
        temp /= 10;
    }
    return x == rev;
}

void precompute() {
    palcount[0] = 1;
    for (int i = 1; i < MAX; i++) {
        palcount[i] = palcount[i - 1] + (is_palindrome(i) && is_palindrome((long long)i * i) ? 1 : 0);
    }
}

int main() {
    scanf("%d", &T);

    precompute();

    for (int t = 1; t <= T; t++) {
        scanf("%lld %lld", &A, &B);
        int low = (int) sqrt(A);
        int high = (int) sqrt(B);
        while ((long long) low * low < A) {
            low++;
        }

        while ((long long) high * high > B) {
            high--;
        }

        printf("Case #%d: %d\n", t, palcount[high] - palcount[low - 1]);
    }

    return 0;
}
