//Problem B.Rank and File
//By: phoenixinter@gmail.com
//Apr 15, 2016

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, kase = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> m;
        for (int i = 0; i < 2 * n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int val;
                cin >> val;
                m[val]++;
            }
        }
        vector<int> v;
        for (auto it : m)
        {
            if (it.second % 2 == 1)
                v.push_back(it.first);
        }
        sort(v.begin(), v.end());
        cout << "Case #" << ++kase << ": ";
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}