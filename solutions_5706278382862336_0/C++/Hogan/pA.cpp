#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 1000;

char in[100000];

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for (int times = 0; times < T; times++) {
        scanf("%s", in);
        int len = strlen(in);

        int flag = 0;
        for (int i = 0; i < len; i++) {
            if (in[i] == '/') {
                flag = i + 1;
                in[i] = 0;
                break;
            }
        }

        long long a = atoll(in);
        long long b = atoll(in + flag);

        long long g = gcd(a, b);
        a /= g;
        b /= g;

        int check = 0;
        for (int i = 0; i < 40; i++) {
            long long c = 1LL << i;
            if (b & c) check++;
        }

        int t = 0;
        for (; t < 40; t++) {
            long long c = 1LL << t;
            if (a * c >= b) break;
        }

        if (t == 40 || check > 1) {
            printf("Case #%d: impossible\n", times + 1);
        }
        else {
            printf("Case #%d: %d\n", times + 1, t);
        }
    }
}
