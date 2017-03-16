#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int T = 1; T <= t; ++T)
    {
        string s;
        cin >> s;

        int alphabet[26] = {0};
        for(int i = 0; i < s.size(); ++i)
            alphabet[s[i] - 'A']++;

        int digit[10] = {0};

        digit[0] = alphabet['Z' - 'A'];
        digit[2] = alphabet['W' - 'A'];
        digit[4] = alphabet['U' - 'A'];
        digit[6] = alphabet['X' - 'A'];
        digit[8] = alphabet['G' - 'A'];

        digit[1] = alphabet['O' - 'A'] - digit[0] - digit[2] - digit[4];
        digit[3] = alphabet['R' - 'A'] - digit[0] - digit[4];
        digit[5] = alphabet['F' - 'A'] - digit[4];
        digit[7] = alphabet['S' - 'A'] - digit[6];

        digit[9] = alphabet['I' - 'A'] - digit[6] - digit[8] - digit[5];

        cout << "Case #" << T << ": ";
        for(int i = 0 ; i < 10; ++i)
            for(int j = 0; j < digit[i]; ++j)
                cout << i;
        cout << endl;
    }

    return 0;
}
