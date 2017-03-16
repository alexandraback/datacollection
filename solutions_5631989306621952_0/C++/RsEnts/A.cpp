#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 1010

using namespace std;

int T, N;
char str[MaxN], output[MaxN], output1[MaxN];
bool used[MaxN];

int main() {
    freopen("A-small-attempt0 (1).in", "r", stdin);
    freopen("A-small-attempt0 (1).out", "w", stdout);
    int T0 = 0;
    scanf("%d", &T);
    for ( ; T; --T) {
        scanf("%s", &str);
        N = strlen(str);
        int l = 0, c, nc = 0;
        char ca = ' ';
        printf("Case #%d: ", ++T0);
        memset(used, 0, sizeof(used));
        for (int i = 0; i < N; ++i) {
            if (str[i] >= ca) {
                ca = str[i];
                used[i] = 1;
                output1[l++] = str[i];
            }
        }
        for (int i = l - 1; i >= 0; --i)
            printf("%c", output1[i]);
        for (int i = 0; i < N; ++i) {
            if (!used[i]) {
                printf("%c" , str[i]);
            }
        }
        puts("");
    }
    return 0;
}
