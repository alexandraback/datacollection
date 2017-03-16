#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

bool flag[10];

int check(int x) {
    memset(flag, false, sizeof(flag));
    int count = 0;

    int y = x;
    while (1) {
        for (int temp = y; temp; temp /= 10) {
            int k = temp % 10;
            if (!flag[k]) {
                flag[k] = true;
                ++ count;
            }
        }
        if (count == 10) break;
        y += x;
    }
    return y;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++ test) {
        printf("Case #%d: ", test);
        int n;
        scanf("%d", &n);
        if (n == 0)
            printf("INSOMNIA\n");
        else
            printf("%d\n", check(n));
    }
    /*
    for (int i = 1; i <= 1000000; ++ i)
        printf("%d %d\n", i, check(i));
    */
    return 0;
}
