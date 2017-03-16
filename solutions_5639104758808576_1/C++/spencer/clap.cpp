#include <algorithm>
#include <cstdio>
using namespace std;

int solve()
{
    int Smax; scanf("%d ", &Smax);
    int max_gap = 0;
    int total = 0;
    for (int shyness = 0; shyness <= Smax; shyness++)
    {
        char c; scanf("%c", &c);
        int count = c - '0';
        if (total < shyness) max_gap = max(max_gap, shyness - total);
        total += count;
    }
    return max_gap;
}

int main()
{
    int T; scanf("%d\n", &T);
    for (int t = 1; t <= T; t++)
        printf("Case #%d: %d\n", t, solve());
    return 0;
}
