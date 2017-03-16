#include <vector>
#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int idxTestcase = 0; idxTestcase < T; ++idxTestcase)
    {
        int A, N;
        scanf("%d%d", &A, &N);
        vector<int> motes(N);
        for (int i = 0; i < N; ++i)
            scanf("%d", &motes[i]);
        int ans;
        if (A == 1)
            ans = N;
        else
        {
            sort(motes.begin(), motes.end());
            ans = INT_MAX;
            for (int rem = 0; rem <= N; ++rem)
            {
                int cur = A;
                int cost = N - rem;
                for (int i = 0; i < rem; ++i)
                {
                    while (motes[i] >= cur)
                    {
                        cur = 2 * cur - 1;
                        ++cost;
                    }
                    cur += motes[i];
                }
                if (cost < ans)
                    ans = cost;
            }
        }
        printf("Case #%d: %d\n", idxTestcase + 1, ans);
    }
    return 0;
}
