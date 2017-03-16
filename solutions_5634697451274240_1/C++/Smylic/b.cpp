#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++)
    {
        char s[128];
        cin >> s;

        int n = strlen(s);
        s[n] = '+';

        int k = 0;

        for (int i = 0; i < n; i++)
            k += s[i] != s[i + 1];

        cout << "Case #" << tt << ": " << k << endl;
    }

    return 0;
}
