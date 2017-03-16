#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("1.in");
    ofstream fout("1.out");
    int t;
    fin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        fin >> s;
        deque<char> ss;
        for (int j = 0; j < s.length(); j++)
            if (ss.empty() || ss.front() > s[j])
                ss.push_back(s[j]);
        else
                ss.push_front(s[j]);
        fout << "Case #" << i + 1 << ": ";
        for (int j = 0; j < s.length(); j++)
        {
            fout << ss.front();
            ss.pop_front();
        }
        fout << "\n";
    }
    return 0;
}

