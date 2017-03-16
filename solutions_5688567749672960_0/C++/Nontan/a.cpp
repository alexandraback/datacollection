#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int T;
int N;
int M[1000000];

const int inf = INT_MAX / 3;

int pow(int a, int b) {
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}

int rev(int x) {
    int n = x;
    int d = 0;
    for (; n != 0; d++) { n /= 10; }

    int r = 0;
    for (int i = 0; i < d; i++) {
        r += ((x / pow(10, d - i - 1)) % 10) * pow(10, i);
    }
    return r;
}

int solve() {
    int ans_a = 11;

    if (N <= 10) { return N; }

    int n = N;
    int d = 0;
    for (; n != 0; d++) { n /= 10; }

    // d digits
    for (int i = 2; i < d; i++) {
        ans_a += 10 + pow(10, i - 1);
    }

    int r = rev(N);

    int x = inf;
    if (N % 10 != 0) {
        x = (N % 10 - 1) + (r - ((N % 10) * pow(10, d - 1) + 1)) + 1;
    }

    int y = (r % 10 - 1) + (N - ((r % 10) * pow(10, d - 1) + 1));
    int z = N - pow(10, d - 1) - 1;

    return ans_a + min(min(x, y), z);
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d", &N);
        printf("Case #%d: %d\n", i, solve());
    }
}

