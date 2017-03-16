#include <iostream>

using namespace std;

unsigned long long pos;

int T, K, C, S;

int main()
{
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cin >> K >> C >> S;

        if (C * S < K)
        {
            cout << "Case #" << i << ": IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "Case #" << i << ":";

            for (int j = 1; j <= K; j += C)
            {
                pos = j;

                for (int k = 1; k <= C; k++)
                {
                    pos = (pos - 1) * K + k;
                }

                cout << " " << pos;
            }

            cout << endl;
        }
    }

    return 0;
}
