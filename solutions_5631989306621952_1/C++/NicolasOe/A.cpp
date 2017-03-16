#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";

        deque<char> d;
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            if (d.empty()) d.push_front(s[j]);
            else
            {
                if (d.front() <= s[j]) d.push_front(s[j]);
                else d.push_back(s[j]);
            }
        }

        for (int j = 0; j < d.size(); j++)
            cout << d[j];
        cout << endl;
    }
}
