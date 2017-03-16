#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 3;
const int S = N * N * N;
const int SZ = 1 << S;

int a, b, c, k;
int id[N][N][N];
vector<int> back_id[S];
bool dp[SZ];
int bad[S];
int sz;

bool is_bad(int mask)
{
    for (int i = 0; i < sz; i++)
        if (__builtin_popcount(mask & bad[i]) > k)
            return true;
    return false;
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    sz = 0;

    scanf("%d%d%d%d", &a, &b, &c, &k);

    int ptr = 0;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            for (int t = 0; t < c; t++)
            {
                back_id[ptr] = {i, j, t};
                id[i][j][t] = ptr++;
            }

    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        {
            int mask = 0;
            for (int t = 0; t < c; t++)
                mask |= 1 << id[i][j][t];
            bad[sz++] = mask;
        }
    for (int i = 0; i < a; i++)
        for (int t = 0; t < c; t++)
        {
            int mask = 0;
            for (int j = 0; j < b; j++)
                mask |= 1 << id[i][j][t];
            bad[sz++] = mask;
        }
    for (int j = 0; j < b; j++)
        for (int t = 0; t < c; t++)
        {
            int mask = 0;
            for (int i = 0; i < a; i++)
                mask |= 1 << id[i][j][t];
            bad[sz++] = mask;
        }
    assert(sz <= S);

    dp[0] = true;
    int best_mask = 0;

    for (int mask = 0; mask < SZ; mask++)
    {
        if (!dp[mask] || is_bad(mask))
            continue;
        if (__builtin_popcount(best_mask) < __builtin_popcount(mask))
            best_mask = mask;

        for (int i = 0; i < ptr; i++)
            dp[mask | (1 << i)] = true;
    }

    printf("%d\n", __builtin_popcount(best_mask));
    for (int i = 0; i < ptr; i++)
        if (best_mask & (1 << i))
            printf("%d %d %d\n", back_id[i][0] + 1, back_id[i][1] + 1, back_id[i][2] + 1);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        cerr << "test " << i + 1 << endl;
        printf("Case #%d: ", i + 1);
        solve();
    }

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}
