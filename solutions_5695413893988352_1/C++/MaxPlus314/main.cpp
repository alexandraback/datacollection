#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

uint64_t bd, bn1, bn2;

void solve(const string &s1, const string &s2, uint64_t n1 = 0, uint64_t n2 = 0, int p = 0)
{
    if (p == s1.size())
    {
        uint64_t dif;
        if (n1 < n2)
            dif = n2 - n1;
        else
            dif = n1 - n2;
        if (dif < bd)
            bd = dif, bn1 = n1, bn2 = n2;
        return;
    }
    if (s1[p] != '?' && s2[p] != '?')
        solve(s1, s2, n1 * 10 + s1[p] - '0', n2 * 10 + s2[p] - '0', p + 1);
    else if (n1 == n2)
        if (s1[p] == '?' && s2[p] == '?')
        {
            solve(s1, s2, n1 * 10, n2 * 10, p + 1);
            solve(s1, s2, n1 * 10, n2 * 10 + 1, p + 1);
            solve(s1, s2, n1 * 10 + 1, n2 * 10, p + 1);
        }
        else if (s1[p] == '?')
        {
            if (s2[p] != '0')
                solve(s1, s2, n1 * 10 + s2[p] - '0' - 1, n2 * 10 + s2[p] - '0', p + 1);
            solve(s1, s2, n1 * 10 + s2[p] - '0', n2 * 10 + s2[p] - '0', p + 1);
            if (s2[p] != '9')
                solve(s1, s2, n1 * 10 + s2[p] - '0' + 1, n2 * 10 + s2[p] - '0', p + 1);
        }
        else if (s2[p] == '?')
        {
            if (s1[p] != '0')
                solve(s1, s2, n1 * 10 + s1[p] - '0', n2 * 10 + s1[p] - '0' - 1, p + 1);
            solve(s1, s2, n1 * 10 + s1[p] - '0', n2 * 10 + s1[p] - '0', p + 1);
            if (s1[p] != '9')
                solve(s1, s2, n1 * 10 + s1[p] - '0', n2 * 10 + s1[p] - '0' + 1, p + 1);
        }
        else;
    else if (n1 < n2)
        if (s1[p] == '?' && s2[p] == '?')
            solve(s1, s2, n1 * 10 + 9, n2 * 10, p + 1);
        else if (s1[p] == '?')
            solve(s1, s2, n1 * 10 + 9, n2 * 10 + s2[p] - '0', p + 1);
        else if (s2[p] == '?')
            solve(s1, s2, n1 * 10 + s1[p] - '0', n2 * 10, p + 1);
        else;
    else if (n1 > n2)
        if (s1[p] == '?' && s2[p] == '?')
            solve(s1, s2, n1 * 10, n2 * 10 + 9, p + 1);
        else if (s1[p] == '?')
            solve(s1, s2, n1 * 10, n2 * 10 + s2[p] - '0', p + 1);
        else if (s2[p] == '?')
            solve(s1, s2, n1 * 10 + s1[p] - '0', n2 * 10 + 9, p + 1);
        else;
    else;
}

int main()
{
    ifstream cin("B-large.in");
    ofstream cout("ansLarge");
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        string s1, s2;
        bd = 1e19;
        cin >> s1 >> s2;
        solve(s1, s2);
        cout << "Case #" << i + 1 << ": ";
        string sn1, sn2;
        stringstream tmp;
        tmp << bn1;
        tmp >> sn1;
        tmp.clear();
        tmp << bn2;
        tmp >> sn2;
        tmp.clear();
        for (int i = sn1.size(); i < s1.size(); ++i)
            cout << '0';
        cout << bn1 << ' ';
        for (int i = sn2.size(); i < s2.size(); ++i)
            cout << '0';
        cout << bn2 << '\n';
    }
    return 0;
}
