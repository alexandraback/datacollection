#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t;
    cin >> t;
    for(int caso = 1; caso <= t; caso++)
    {
        string s;
        cin >> s;
        long long int inv_count = 0;
        while(find(s.begin(), s.end(), '-') != s.end())
        {
            auto first_minus = find(s.begin(), s.end(), '-');
            if(first_minus == s.begin())
            {
                auto first_plus = find(s.begin(), s.end(), '+');
                for(auto it = s.begin(); it != first_plus; ++it)
                    *it = '+';
                inv_count++;
            }
            else
            {
                auto second_plus = find(first_minus, s.end(), '+');
                for(auto it = first_minus; it != second_plus; ++it)
                    *it = '+';
                inv_count += 2;
            }
        }
        cout << "Case #" << caso << ": " << inv_count << endl;
    }
    return 0;
}
