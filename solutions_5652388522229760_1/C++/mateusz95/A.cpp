#include <bits/stdc++.h>

using namespace std;

const int D = 10;

bool wasDigit[D];

void test() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("INSOMNIA\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        wasDigit[i] = false;
    }
    int w = 0;
    int visDigits = 0;
    while (visDigits < D) {
        w += n;
        int x = w;
        while (x) {
            if (wasDigit[x % D] == false) {
                visDigits++;
            }
            wasDigit[x % D] = true;
            x /= D;
        }
    }
    printf("%d\n", w);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tests = 1; tests <= t; tests++) {
        printf("Case #%d: ", tests);
        test();
    }

    return 0;
}