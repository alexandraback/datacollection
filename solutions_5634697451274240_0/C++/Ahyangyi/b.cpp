#include <iostream>
#include <string>

using namespace std;

int solve(string s)
{
    int ans = 0;

    for (int i = 0; i < s.size(); i ++)
    {
        char next;
        if (i + 1 < s.size())
        {
            next = s[i + 1];
        }
        else
        {
            next = '+';
        }

        if (s[i] != next)
        {
            ans ++;
        }
    }

    return ans;
}

int main()
{
    int ct, t;

    cin >> t;
    for (ct = 1; ct <= t; ct ++)
    {
        string s;

        cin >> s;
        cout << "Case #" << ct << ": " << solve(s) << endl;
    }

    return 0;
}
