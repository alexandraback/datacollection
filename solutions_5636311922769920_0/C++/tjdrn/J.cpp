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

int main() {
    int test, k, c, s;
    scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        scanf("%d%d%d", &k, &c, &s);
        LL len = 1;
        for (int i = 0; i < c; i++) {
            len *= k;
        }
        LL num = len / s;
        printf("Case #%d:", cas);
        for (int i = 0; i < s; i++) {
            printf(" %lld", num * i + 1);
        }
        puts("");
    }
    return 0;
}
