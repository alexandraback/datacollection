#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int N;
int perm[100];
string words[100];
char buffer[100 * 100 + 1];
unsigned char used[26];

bool valid_comb()
{
    char* dest = buffer;
    for (int i = 0; i < N; ++i)
    {
        const string& word = words[perm[i]];
        memcpy(dest, word.c_str(), word.length());
        dest += word.length();
    }
    *dest = 0;

    memset(used, 0, 26);
    char* pos = buffer;
    while (*pos)
    {
        char c = *pos;
        if (used[c - 'a'])
            return false;
        used[c - 'a'] = 1;
        while (*pos == c)
        {
            ++pos;
        }
    }
    return true;
}

void solve()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> words[i];
        perm[i] = i;
    }

    int combs = 0;
    do
    {
        if (valid_comb())
            ++combs;
    } while (next_permutation(perm, perm + N));
    cout << combs << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}