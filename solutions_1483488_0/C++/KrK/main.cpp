#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 2000005;

int T, A, B;
bool taken[Maxn];
int helper;
ll res;

void Add(int num)
{
    set <int> S;
    while (!S.count(num)) {
        S.insert(num);
        num = num % 10 * helper + num / 10;
    }
    int siz = 0;
    for (set <int>::iterator it = S.begin(); it != S.end(); it++)
        if (helper <= *it && A <= *it && *it <= B) { taken[*it] = true; siz++; }
    res += ll(siz) * ll(siz - 1LL) / 2LL;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &A, &B);
        fill(taken, taken + Maxn, false);
        helper = 1;
        res = 0LL;
        for (int i = A; i <= B; i++) if (!taken[i]) {
            while (10 * helper <= i) helper *= 10;
            Add(i);
        }
        printf("Case #%d: %lld\n", tc, res);
    }
    return 0;
}
