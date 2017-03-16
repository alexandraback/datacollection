#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <cstring>

using namespace std;

int possible_end[1000009];
char buf[1000009];

int main()
{
    //freopen("d:\\dev\\acm\\CodeJam2013_1C\\CodeJam2013_1C\\a-big.in", "r", stdin);
    freopen("d:\\dev\\acm\\CodeJam2013_1C\\CodeJam2013_1C\\A-large.in", "r", stdin);
    freopen("d:\\dev\\acm\\CodeJam2013_1C\\CodeJam2013_1C\\a_large.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; ++t)
    {
        string s;
        cin >> s;
        int L = s.length();

        int n;
        cin >> n;

        memset(possible_end, -1, sizeof(possible_end));

        int cur_consonants = 0;
        for (int i = L - 1; i >= 0; --i)
        {
            if (s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u')
                cur_consonants = 0;
            else
                cur_consonants++;

            if (cur_consonants >= n)
                possible_end[i] = i + n - 1;
            else
                possible_end[i] = possible_end[i + 1];
        }

        long long res = 0;

        for (int i = 0; i < L; ++i)
        {
            if (possible_end[i] != - 1)
                res += L - possible_end[i];
        }
        printf("Case #%d: %lld\n", t + 1, res);

    }
    return 0;
}