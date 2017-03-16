#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector <pair <long long, int> > a;
vector <pair <long long, int> > b;
pair <long long, long long> now;
map <pair <long long, long long>, long long> cache;

long long Solve()
{
    if (a.empty() || b.empty())
        return 0;
    if (cache.count(now))
    {
        return cache[now];
    }
    vector <pair <long long, int> > na = a, nb = b;
    pair <long long, long long> nnow = now;
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
        now.first -= mi;
        now.second -= mi;
        ans = max(ans, mi + Solve());
        a = na;
        b = nb;
        now = nnow;
        return cache[now] = ans;
    }
    now.first -= a.back().first;
    a.pop_back();
    ans = max(ans, Solve());
    now = nnow;
    a = na;
    now.second -= b.back().first;
    b.pop_back();
    ans = max(ans, Solve());
    now = nnow;
    b = nb;
    return cache[now] = ans;
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
        now = make_pair(0, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
            now.first += a[i].first;
        }
        for (int i = 0; i < m; i++)
        {
            long long x, y;
            cin >> x >> y;
            bool has = false;
            for (int j = 0; j < n; j++)
                if (a[j].second == y)
                    has = true;
            if (has)
            {
                now.second += x;
                b.push_back(make_pair(x, y));
            }
        }
        printf("Case #%d: ", t + 1);
        cache.clear();
        cout << Solve() << endl;
    }
}