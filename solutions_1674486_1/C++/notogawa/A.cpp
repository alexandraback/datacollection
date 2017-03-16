#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

string solve()
{
    int n = 0;
    cin >> n;
    vector< vector< int > > edges(n);
    vector< int > zs;
    for (int i = 0; i < n; ++i)
    {
        int m = 0;
        cin >> m;
        if (0 == m) zs.push_back(i);
        for (int j = 0; j < m; ++j)
        {
            int x = 0;
            cin >> x;
            edges[x-1].push_back(i);
        }
    }

    for (vector< int >::iterator i = zs.begin(); i != zs.end(); ++i)
    {
        stack< int > s;
        s.push(*i);
        vector< int > visits(n, false);
        while (!s.empty())
        {
            int x = s.top(); s.pop();
            if (visits[x]) return "Yes";
            for (size_t j = 0; j < edges[x].size(); ++j)
                s.push(edges[x][j]);
            visits[x] = true;
        }
    }
    return "No";
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << (i+1) << ": " << solve() << endl;
    }
}
