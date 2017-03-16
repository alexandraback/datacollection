#include <iostream>

using namespace std;

int T, N, J, n, m, digits[32];

void printDigits()
{
    for (int i = 0; i < N; i++)
    {
        cout << digits[i];
    }
}

void printDivisors()
{
    for (int i = 2; i <= 10; i++)
    {
        cout << " " << i + 1;
    }
}

int main()
{
    cin >> T >> N >> J;

    digits[0] = digits[N - 1] = 1;

    cout << "Case #" << T << ":" << endl;

    for (int i = 0; i < J; i++)
    {
        n = i;
        m = 0;
        while (n != 0)
        {
            m++;
            digits[m] = digits[N - m - 1] = n % 2;
            n /= 2;
        }

        printDigits();

        printDivisors();

        cout << endl;
    }

    return 0;
}
