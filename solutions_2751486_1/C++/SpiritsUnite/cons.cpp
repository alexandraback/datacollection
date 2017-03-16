#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        long long ans = 0;
        string s;
        int n;
        cin >> s >> n;
        int vowels = 0;
        for (int i = 0; i < n - 1; i++)
            if (isVowel(s[i])) vowels++;
        int st = 0, ed = n - 1;
        int last = -1;
        for (; ed < s.length(); st++, ed++)
        {
            if (isVowel(s[ed])) vowels++;

            if (vowels == 0)
            {
                ans += (long long)(st - last) * (long long)(s.length() - ed);
                last = st;
            }

            if (isVowel(s[st])) vowels--;
        }
        cout << "Case #" << C << ": " << ans << '\n';
    }
    return 0;
}

