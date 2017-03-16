#include <iostream>
#include <cstdio>

using namespace std;

__int64 num[1000000];
int digit[20];
__int64 a, b;
int t;

bool isPalindromes(__int64 square) {
    int l =0;
    while (square) {
        digit[l++] = square % 10;
        square /= 10;
    }

    for (int i = 0; i < l / 2; ++i) {
        if (digit[i] != digit[l - i - 1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int l = 0;
    for(__int64 i = 1; i <= 10000001; ++i) {
        __int64 square = i * i;
        if (isPalindromes(i) && isPalindromes(square)) {
            num[l++] = square;
        }
    }

    scanf("%d", &t);
    for (int ti = 1; ti <= t; ++ti) {
        scanf ("%I64d %I64d", &a, &b);
        int ans = 0;
        for (int i = 0; i < l; ++i) {
            if (num[i] >= a && num[i] <= b) {
                ++ans;
            }
        }
         printf("Case #%d: %d\n", ti, ans);
    }

    return 0;
}

