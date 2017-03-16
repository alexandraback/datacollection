#include <cassert>
#include <iostream>

using namespace std;

int R, N, M, K;
int products[20];

int main()
{
    int numTestcases;
    cin >> numTestcases;

    for (int testcase = 0; testcase < numTestcases; testcase++)
    {
        cout << "Case #" << testcase + 1 << ":" << endl;

        cin >> R >> N >> M >> K;
        assert(N == 3 && M == 5);
        while (R--)
        {
            for (int i = 0; i < K; i++)
                cin >> products[i];

            bool done = false;
            for (int a = 2; a <= 5 && !done; a++)
            {
                for (int b = 2; b <= 5 && !done; b++)
                {
                    for (int c = 2; c <= 5 && !done; c++)
                    {
                        bool satisfied = true;

                        for (int i = 0; i < K; i++)
                        {
                            if (products[i] != 1 &&
                                products[i] != a &&
                                products[i] != b &&
                                products[i] != c &&
                                products[i] != a * b &&
                                products[i] != a * c &&
                                products[i] != b * c &&
                                products[i] != a * b * c)
                            {
                                satisfied = false;
                                break;
                            }
                        }
                        if (satisfied)
                        {
                            cout << a << b << c << endl;
                            done = true;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

