#include<iostream>
#include<vector>
#include<sstream>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

int ans = 0;
vector <int> neigh;

void check(vector<int> & p)
{
    int m = p.size();
    for (int i = 0; i < m; ++i)
    {
        int fr = neigh[p[i]];
        if (p[(i + 1) % m] != fr && p[(i - 1 + m) % m] != fr)
            return;
    }
    ans = max(ans, m);
}

void gen(vector<int> & p, int n)
{
    check(p);
    for (int i = 1; i <= n; ++i)
    {
        if (find(p.begin(), p.end(), i) == p.end())
        {
            p.push_back(i);
            gen(p, n);
            p.pop_back();
        }
    }
}

int solve()
{
    int n;
    cin >> n;
    neigh.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> neigh[i];
    }
    ans = 0;
    vector <int> p;
    gen(p, n);
    return ans;
}

int main()
{
    int T, t;
    cin >> T;
    for (t = 1; t <= T; ++t)
    {
        cout << "Case #" << t << ": " << solve() << endl;
        cerr << t << " ";
    }
    return 0;
}

