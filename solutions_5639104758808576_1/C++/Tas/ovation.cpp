#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>
using namespace std;



int solve( vector<int>& levels)
{
    int total = 0;
    int extra = 0;
    for (int i=0; i <  levels.size(); i++ )
    {
        if ( i > total)
        {
            int delta = i-total;
            total += delta;
            extra += delta;
        }

        total += levels[i];
    }

    return extra;
}


int main()
{
    int t;
    cin >> t;
    for (int cs=0; cs < t; cs++)
    {
        int smax;
        string s;
        cin >> smax >> s;
        vector<int> levels;

        for (int i=0; i < s.size(); i++)
        {
            int val = s[i]-'0';
            levels.push_back(val);

        }
         cout << "Case #" << cs +1<< ": ";
         cout << solve(levels) << endl;
    }
}
