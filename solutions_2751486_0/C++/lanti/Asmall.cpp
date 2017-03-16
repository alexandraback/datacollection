// Asmall.cpp

#include <iostream>
using namespace std;

bool is_vowel(char ch)
{
    char vowels[] = "aeiou";
    for (int i = 0; i < 5; ++i) if (ch == vowels[i])
        return true;
    return false;
}

bool is_cons(char ch)
{
    return !is_vowel(ch);
}

void solve(int tcase)
{
    string s; cin >> s;
    int thresh; cin >> thresh;
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i)
    for (int j = i+1; j <= n; ++j)
    {
        int cnt = 0;
        for (int k = i; k < j; k++) {
            if (is_cons(s[k])) {
                cnt++;
                if (cnt >= thresh) break;
            } else {
                cnt = 0;
            }
        }
        if (cnt >= thresh) ans++;
    }
    cout << "Case #" << tcase << ": ";
    cout << ans << endl;
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
        solve(t);
}
