#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdint.h>
#include <algorithm>

using namespace std;

void print(char a, char b, int k) {
    for (int i = 0; i < k; i++) {
        putchar(a);
        putchar(b);
    }
}

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        printf("Case #%d: ", cas);
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > 0) print('W', 'E', x);
        else print('E', 'W', -x);
        if (y > 0) print('S', 'N', y);
        else print('N', 'S', -y);
        puts("");
    }
    return 0;
}
