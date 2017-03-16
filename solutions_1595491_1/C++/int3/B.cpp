#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_unsurprise(int n) {
    if (n % 3 == 0) return n / 3;
    else return n / 3 + 1;
}

int max_surprise(int n) {
    if (n < 2) return n;
    if (n % 3 == 0) return n / 3 + 1;
    if (n % 3 == 2) return n / 3 + 2;
    if (n % 3 == 1) return (n - 4) / 3 + 2;
}

int main(int argc, const char *argv[])
{
    int i, j, k;
    int T;
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        int N, S, p, pt;
        scanf("%d %d %d", &N, &S, &p);
        int passes = 0;
        for (j = 0; j < N; j++) {
            scanf("%d", &pt);
            if (max_unsurprise(pt) >= p)
                passes++;
            else if (max_surprise(pt) >= p && S-- > 0)
                passes++;
        }
        printf("Case #%d: %d\n", i + 1, passes);
    }
    return 0;
}
