#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <long long, int> > a;
vector <pair <long long, int> > b;

long long Solve()
{
    if (a.empty() || b.empty())
        return 0;
    vector <pair <long long, int> > na = a, nb = b;
    long long ans = 0;
    if (a.back().second == b.back().second)
    {
        long long mi = min(a.back().first, b.back().first);
        a.back().first -= mi;
        b.back().first -= mi;
        if (a.back().first == 0)
            a.pop_back();
        if (b.back().first == 0)
            b.pop_back();
        ans = max(ans, mi + Solve());
        a = na;
        b = nb;
        return ans;
    }
    a.pop_back();
    ans = max(ans, Solve());
    a = na;
    b.pop_back();
    ans = max(ans, Solve());
    b = nb;
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        int n, m;
        cin >> n >> m;
        a.resize(n);
        b.clear();
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        for (int i = 0; i < m; i++)
        {
            long long x, y;
            cin >> x >> y;
            bool has = false;
            for (int j = 0; j < n; j++)
                if (a[j].second == y)
                    has = true;
            if (has)
                b.push_back(make_pair(x, y));
        }
        printf("Case #%d: ", t + 1);
        cout << Solve() << endl;
    }
}