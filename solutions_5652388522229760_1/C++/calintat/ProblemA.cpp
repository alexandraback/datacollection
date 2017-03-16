#include <iostream>

using namespace std;

int T, N, M;

bool digit[10];

bool done()
{
    for (int i = 0; i <= 9; i++)
    {
        if (!digit[i]) return 0;
    }
    return 1;
}

void checkDigits(int x)
{
    while (x != 0)
    {
        digit[x % 10] = 1;
        x /= 10;
    }
}

int main()
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> N;
        if (N == 0)
        {
            cout << "Case #" << i << ": INSOMNIA" << endl;
            continue;
        }
        for (int j = 0; j <= 9; j++)
        {
            digit[j] = 0;
        }
        M = N;
        while (1)
        {
            checkDigits(M);
            if (done())
            {
                cout << "Case #" << i << ": " << M << endl;
                break;
            }
            M += N;
        }
    }
    return 0;
}
