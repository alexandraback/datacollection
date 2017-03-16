#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;

int main()
{
    freopen("B.txt", "r", stdin);
    freopen("B-output.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T ++)
    {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        int cot = 0;
        for (int i = 0; i < a; i ++)
        {
            for (int j = 0; j < b; j ++)
            {
                if ((i & j) < k)
                {
                    cot ++;
                }
            }
        }
        printf("Case #%d: %d\n", T, cot);
    }
    return 0;
}
