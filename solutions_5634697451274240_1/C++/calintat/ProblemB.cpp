#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int T, P[101], N[101];

int getLength(string str)
{
    int n = str.length();
    int m = 0;

    for (int j = 0; j < n; j++)
    {
        m += j == 0 || str[j] != str[j - 1];
    }

    return m;
}

int main()
{
    cin >> T;

    P[1] = 0;
    N[1] = 1;

    for (int i = 2; i <= 100; i++)
    {
        P[i] = N[i - 1] + 1;
        N[i] = P[i - 1] + 1;
    }

    for (int i = 1; i <= T; i++)
    {
        string str;

        cin >> str;

        int n = getLength(str);

        printf("Case #%d: %d\n", i, str[0] == '+' ? P[n] : N[n]);
    }

    return 0;
}
