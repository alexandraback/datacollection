#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;

int solve(__int64 p, __int64 q)
{
    if(p == 0)return 0;

    if(p == q)return 1;

    if(p > q)
    {
        if(solve(p - q, q) == -1)return -1;

        return 1;
    }

    if(q % 2 == 0)
    {
        int ans = solve(p, q / 2);

        if(ans == -1)return -1;

        return ans + 1;
    }

    return -1;
}

int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
	freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int nca;
    scanf("%d", &nca);

    for(int ii = 1; ii <= nca; ii++)
    {
        __int64 p, q;
        scanf("%I64d/%I64d", &p, &q);
        int ans = solve(p, q);

        if(ans != -1)
        {
            printf("Case #%d: %d\n", ii, ans - 1);
        }
        else
        {
            printf("Case #%d: impossible\n", ii);
        }
    }

    return 0;
}
