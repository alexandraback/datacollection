#include<iostream>
#include<vector>
#include<sstream>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

int solve()
{
    map<int, int> count;
    int n;
    cin >> n;
    for (int i = 0; i < n * (2 * n - 1); ++i)
    {
        int x;
        cin >> x;
        count[x]++;
    }
    for (auto elem: count)
    {
        if (elem.second % 2 == 1)
            cout << " " << elem.first;
    }
    cout << endl;
}

int main()
{
    int T, t;
    cin >> T;
    for (t = 1; t <= T; ++t)
    {
        cout << "Case #" << t << ":";
        solve();
    }
    return 0;
}

