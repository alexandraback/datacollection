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

int val[N];
char ss[N];
int n;

void flip(int L, int R) {
    int p = L, q = R;
    while (p <= q) {
        swap(val[p], val[q]);
        p++;
        q--;
    }
    for (int i = L; i <= R; i++) val[i] ^= 1;
}

int main() {
    int test;
    scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        scanf("%s", ss + 1);
        n = strlen(ss + 1);
        for (int i = 1; i <= n; ++i) {
            val[i] = ss[i] == '+';
        }

        int res = 0;

        for (int i = n; i >= 1; i--) {
            if (val[i] == 1) continue;
            int cur = i;
            while (cur >= 1 && val[cur] == 0) {
                cur--;
            }
            if (cur == 0) {
                res++;
                break;
            }
            else {
                int j = 2;
                int col = val[1];
                for (; j <= i; j++) {
                    if (val[j] != col) {
                        break;
                    }
                }
                j--;
                if (col == 0) {
                    res++;
                    flip(1, i);
                }
                else {
                    res += 2;
                    flip(1, j);
                    flip(1, i);
                }
            }
        }
        printf("Case #%d: %d\n", cas, res);
    }
    return 0;
}
