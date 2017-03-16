
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int checkNewDigits(long n, bool *seen) {
    // printf("Trying %ld\n", n);
    int changed = 0;
    while (n != 0) {
        int digit = n % 10;
        if (!seen[digit]) {
            // printf("Adding digit %d\n", digit);
            changed++;
            seen[digit] = true;
        }
        n /= 10;
    }

    return changed;
}

int main(int argc, char *argv[]) {
    int num;

    cin >> num;

    long inp;

    for (int i = 0; i < num; i++) {
        bool seen[10];
        fill(seen, seen + 10, false);
        cin >> inp;

        if (inp == 0) {
            printf("Case #%d: INSOMNIA\n", i + 1);
            continue;
        }

        long currentNum = inp;
        int j = 1;

        int numsLeft = 10;
        while (numsLeft != 0) {
            numsLeft -= checkNewDigits(currentNum, seen);
            currentNum = inp * (++j);
        }

        printf("Case #%d: %ld\n", i + 1, inp * (j - 1));
    }

    return 0;
}
