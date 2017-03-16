#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int C, D, V;
int coins[100];
bool used[100];
bool can[100];

bool check(bool can[100])
{
    for (int i = 0; i <= V; i++)
        if (!can[i]) return false;
    return true;
}
void _main(int cases)
{
    memset(used, 0, sizeof(used));
    scanf("%d%d%d", &C, &D, &V);
    for (int i = 0; i < D; i++)
    {
        scanf("%d", &coins[i]);
        used[coins[i]] = true;
    }

    memset(can, 0, sizeof(can));
    can[0] = true;
    for (int i = 0; i < D; i++)
    {
        for (int j = V; j >= 1; j--)
        {
            if (j - coins[i] >= 0 && can[j - coins[i]])
                can[j] = true;
        }
    }

    int res = 0;
    while (!check(can))
    {
        for (int i = 1; i <= V; i++) if (!used[i])
        {
            used[i] = true;
            res++;
            for (int j = V; j >= 1; j--)
            {
                if (j - i >= 0 && can[j - i])
                    can[j] = true;
            }
            break;
        }
    }

    printf("%d\n", res);
    
}


int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++)
    {
        printf("Case #%d: ", cases);
        _main(cases);
    }
}