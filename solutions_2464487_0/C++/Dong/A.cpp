#include <iostream>

using namespace std;

unsigned long long R, T;

int main()
{
    int numTestcases; cin >> numTestcases;

    for (int testcase = 0; testcase < numTestcases; testcase++)
    {
        cin >> R >> T;

        unsigned long long answer = 1;
        unsigned long long left = 2, right = 1000000000;

        while (left <= right)
        {
            unsigned long long middle = (left + right) / 2;
            unsigned long long u = (2 * middle - 1) * middle;

            if (u > T)
            {
                right = middle - 1;
                continue;
            }
            u = (T - u) / middle / 2;
            if (u < R)
                right = middle - 1;
            else
            {
                answer = middle;
                left = middle + 1;
            }
        }

        cout << "Case #" << testcase + 1 << ": " << answer << endl;
    }

    return 0;
}
