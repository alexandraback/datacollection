#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int E, R, N;
int values[10005];

int dp[15][10];

int main()
{
    int numTestcases;

    cin >> numTestcases;
    for (int testcase = 0; testcase < numTestcases; testcase++)
    {
        cin >> E >> R >> N;
        for (int i = 0; i < N; i++)
            cin >> values[i];

        memset(dp, -1, sizeof(dp));
        dp[0][E] = 0;

        for (int i = 0; i < N; i++)
            for (int energy = 0; energy <= E; energy++)
            {
                if (dp[i][energy] < 0)
                    continue;

                for (int spend = 0; spend <= energy; spend++)
                {
                    int gain = dp[i][energy] + spend * values[i];
                    if (gain > dp[i + 1][min(energy - spend + R, E)])
                        dp[i + 1][min(energy - spend + R, E)] = gain;
                }
            }

        int answer = 0;
        for (int energy = 0; energy <= E; energy++)
            answer = max(answer, dp[N][energy]);

        cout << "Case #" << testcase + 1 << ": " << answer << endl;
    }

    return 0;
}
