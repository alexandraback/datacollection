#include <stdio.h>
#include <string.h>

void updateSeen(int tmp, bool seen[10], int &count) {
    while (tmp) {
        int d = tmp % 10;
        if (!seen[d]) {
            seen[d] = true;
            ++count;
        }
        tmp /= 10;
    }
}

void solve(int i) {
    bool seen[10];
    int count = 0;
    memset(seen, false, sizeof(seen));

    int tmp = i;
    while (tmp >= i) {
        updateSeen(tmp, seen, count);
        if (count == 10) {
            printf("%d\n", tmp);
            return;
        }
        tmp += i;
    }
}

int main(void) {
    for (int i = 1; i <= 1000000; ++i) {
        solve(i);
    }
    return 0;
}