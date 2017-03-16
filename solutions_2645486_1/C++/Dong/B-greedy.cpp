#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

unsigned long long E, R, N;
unsigned long long values[10005], maxValues[10005];

int main()
{
    int numTestcases; cin >> numTestcases;

    for (int testcase = 0; testcase < numTestcases; testcase++)
    {
        cin >> E >> R >> N;
        if (R > E)
            R = E;
        for (int i = 0; i < N; i++)
            cin >> values[i];

        maxValues[N] = 0;
        for (int i = N - 1; i >= 0; i--)
            maxValues[i] = max(maxValues[i + 1], values[i]);

        unsigned long long energy = E;
        unsigned long long answer = 0;

        for (int i = 0; i < N;)
        {
            int next = i + 1;

            while (next < N && values[i] >= values[next])
                next++;
            if (next == N)
            {
                answer += energy * values[i];
                energy = R;
                i++;
            }
            else
            {
                if (energy + (next - i) * R <= E)
                {
                    energy += (next - i) * R;
                    i = next;
                }
                else
                {
                    unsigned long long spend;

                    spend = max(energy + (next - i) * R - E, (unsigned long long) 0);
                    spend = min(spend, energy);
                    answer += spend * values[i];
                    energy = energy - spend + R;
                    i++;
                }
            }
        }

        cout << "Case #" << testcase + 1 << ": " << answer << endl;
    }

    return 0;
}

