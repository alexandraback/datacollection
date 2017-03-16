#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXN = 100;

int A, N, s[MAXN];

void solve()
{
    if (A == 1) { printf("%d", N); return; }

    sort(s, s+N);
    int mn = N;

    for (int d = 0; d <= N; ++d) {
        int tA = A, cur = 0;

        for (int j = 0; j < N-d; ++j) {
            while (tA <= s[j]) {
                tA += tA - 1;
                ++cur;
            }

            tA += s[j];
        }

        if (cur+d < mn) mn = cur+d;
    }

    printf("%d", mn);
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d%d", &A, &N);
        for (int i = 0; i < N; ++i) scanf("%d", &s[i]);

        printf("Case #%d: ", t+1);
        solve();
        printf("\n");
    }

    return 0;
}
