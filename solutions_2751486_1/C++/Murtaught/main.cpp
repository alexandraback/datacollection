#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long int llint;

inline bool is_vowel(char c)
{
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        string s;
        int n;
        cin >> s >> n;

        llint sum = 0;
        int last_pos = 0;

        int got = 0;
        for (int i = 0; i < int(s.size()); ++i)
        {
            ++got;
            if ( is_vowel(s[i]) )
                got = 0;

            if ( got >= n )
            {
                llint r = s.size() - i ; // -1
                llint l = i - n - last_pos + 2;

                last_pos = i - n + 2;

                sum += r * l;
            }
        }

        printf("Case #%d: %lld\n", t, sum);


    }



    return 0;
}
