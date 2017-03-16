#include <cstdio>
#include <algorithm>
#include <limits.h>

using namespace std;

#define MAX_N 100

int motes[MAX_N];

int solve() {
    int a, n;
    scanf("%d %d", &a, &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &motes[i]);
    }

    if (a == 1) {
        return n;
    }

    sort(motes, motes+n);

    int best = n;
    int addCount = 0;
    for (int i = 0; i < n; i++) {
        while (a <= motes[i]) {
            a += (a-1);
            addCount++;
        }
        a += motes[i];
        best = min(best, addCount + (n-i-1));
    }

    return best;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
         printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}
