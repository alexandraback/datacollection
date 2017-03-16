#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <deque>
using namespace std;

string calc_string(string const& s)
{
    deque<char> res;
    for (int i = 0; i < s.size(); ++i)
    {
        if (res.empty())
        {
            res.push_back(s[i]);
            continue;
        }
        else if (s[i] >= res[0])
        {
            res.push_front(s[i]);
        }
        else
        {
            res.push_back(s[i]);
        }
    }
    return string(res.begin(), res.end());
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;
        cout << "Case #" << + i + 1 << ": " << calc_string(s) << "\n";
    }
    return 0;
}