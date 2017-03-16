#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream lire("input.in", ios::in);
ofstream ecrire("output.txt", ios::out);

long long int f[200] = {0};

long long int fact(int n)
{
    if (n == 0)
        return 1;
    if (f[n] == 0)
        f[n] = (n * fact(n - 1)) % 1000000007;
    return f[n];
}

int main()
{
    int T;
    lire >> T;
    for (int t = 1; t <= T; t++)
    {
        int N;
        long long int s = 1;
        int b[26][26] = {0};
        lire >> N;
        int a[26][4] = {0};
        string str;
        for (int n = 0; n < N; n++)
        {
            lire >> str;
            int i = 0;
            while (i < str.length() && str[i] == str[0])
                i++;
            if (i == str.length())
                a[str[0] - 'a'][0]++;
            else
                a[str[0] - 'a'][1]++;
            if (i < str.length() && str[0] == str[str.length() - 1])
                s = 0;
            while (i < str.length())
            {
                int r = i;
                while (i < str.length() && str[i] == str[r])
                    i++;
                if (i == str.length())
                    a[str[r] - 'a'][2]++;
                else
                    a[str[r] - 'a'][3]++;
                r = i;
            }
            b[str[0] - 'a'][str[str.length() - 1] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
            if (a[i][1] > 1 || a[i][2] > 1 || a[i][3] > 1 || (a[i][3] > 0 && (a[i][1] > 0 || a[i][2] > 0 || a[i][0] > 0)))
                s = 0;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                if (i != j && b[i][j] > 0 && b[j][i] > 0)
                    s = 0;
        if (s != 0)
        {
            for (int i = 0; i < 26; i++)
                s = (s * fact(a[i][0])) % 1000000007;
            for (int i = 0; i < 26; i++)
            {
                if (a[i][0] > 0)
                    N = N + 1 - a[i][0];
                if (a[i][1] == 1 && a[i][2] == 1)
                    N = N - 1 - (a[i][0] > 0);
                if (a[i][1] == 1 && a[i][2] == 0)
                    N = N - (a[i][0] > 0);
                if (a[i][2] == 1 && a[i][1] == 0)
                    N = N - (a[i][0] > 0);
            }
            s = (s * fact(N)) % 1000000007;
        }
        ecrire << "Case #" << t << ": " << s << endl;
    }
    return 0;
}
