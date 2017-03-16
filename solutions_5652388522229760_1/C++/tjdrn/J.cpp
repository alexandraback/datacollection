#include <string>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


#define N 105
#define mod 1000000007
#define LL long long

inline int read() {//used to read 32bit positive integer
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    int x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }

    return x;
}

bool ok[10];

void insert(int val) {
    while (val) {
        int d = val % 10;
        ok[d] = 1;
        val /= 10;
    }
}

bool check() {
    for (int i = 0; i < 10; i++) {
        if (!ok[i])
            return 0;
    }
    return 1;
}

int main() {
    int test;
    scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: ", cas);
        if (n == 0) {
            puts("INSOMNIA");
            continue;
        }
        int tmp = n;

        memset(ok, 0, sizeof(ok));
        while (1) {
            insert(tmp);
            if (check()) break;
            tmp += n;
        }
        printf("%d\n", tmp);
    }
    return 0;
}
