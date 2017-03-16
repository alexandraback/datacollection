#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool iscons(char ch)
{
    return (ch != 'u' && ch != 'e' && ch != 'o' && ch != 'a' && ch != 'i');
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int nTest;
    cin >> nTest;
    for (int test = 1; test <= nTest; ++test)
    {
        long long n = 0;
        string s;
        cin >> s >> n;
        long long left = -1, dem = 0, res = 0;
        for (long long i = 0; i < s.length(); ++i)
        {
            if (iscons(s[i]))
                dem++;
            else
                dem = 0;
            if (dem >= n)
                left = i - n + 1;
            res += left + 1;
        }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
