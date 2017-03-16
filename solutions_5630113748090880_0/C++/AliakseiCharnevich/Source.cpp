#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <deque>
using namespace std;

void calc_row()
{
    vector<int> vp(2501, 0);
    int n;
    cin >> n;
    for (int i = 0; i < 2*n-1; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int val;
            cin >> val;
            ++vp[val];
        }
    }

    vector<int> result;
    for (int i = 0; i < vp.size(); ++i)
    {
        if (vp[i] % 2 == 1)
        {
            result.push_back(i);
        }
    }
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ' ';
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << + i + 1 << ": ";
        calc_row();
        cout << "\n";
    }
    return 0;
}