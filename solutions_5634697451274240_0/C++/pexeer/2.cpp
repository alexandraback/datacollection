#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <algorithm>


bool g_map[1024];

int min_zero(int i);
int min_one(int i);

int min_zero(int i) {
    if (i == 0) {
        if(g_map[0]) {
            return 1;
        } else {
            return 0;
        }
    }

    if (g_map[i]) {
        return min_one(i-1) + 1;
    } else {
        return min_zero(i-1);
    }
}

int min_one(int i) {
    if (i == 0) {
        if(g_map[0]) {
            return 0;
        } else {
            return 1;
        }
    }
    if (g_map[i]) {
        return min_one(i-1);
    } else {
        return min_zero(i-1) + 1;
    }
}

void solve(int T) {
    char input[1024];
    scanf("%s", input);
    int i;
    for (i = 0; input[i]; ++i) {
        if (input[i] == '+') {
            g_map[i] = 1;
        } else {
            g_map[i] = 0;
        }
    }
    printf("Case #%d: %d\n", T, min_one(--i));
}

int main(int argc, char* argv[]) {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
    return 0;
}
