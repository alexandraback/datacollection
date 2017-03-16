#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <thread>

using namespace std;

int main()
{
    freopen("gcj\\D-small-attempt0.in", "r", stdin);
    freopen("gcj\\D-small-attempt0.out", "w", stdout);
    
    int T, cases = 1;
    int K, C, S;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &K, &C, &S);
        
        if (K > C * S)
        {
            printf("Case #%d: IMPOSSIBLE\n", cases++);
            continue;
        }

        vector<long long> ans;
        int p = 0;
        while (p < K)
        {
            long long rnk = 1;
            for (int dep = 1; dep <= C; ++dep)
            {
                if (p < K)
                    p++;
                rnk = (rnk - 1) * K + p;
            }
            ans.push_back(rnk);
        }

        printf("Case #%d:", cases++);
        for (auto& id : ans)
            printf(" %I64d", id);
        puts("");
    }

    return 0;
}