#include <bits/stdc++.h>

using namespace std;

template<class T>
using v = vector<T>;
using ll = long long;

using pii = pair<ll, ll>;


void solve()
{
    set<int> used;
    int x;
    cin >> x;

    auto check = [&](int y)
    {
        while (y)
        {
            used.insert(y % 10);
            y /= 10;
        }
        return used.size() == 10;
    };

    if (x == 0)
    {
        cout << "INSOMNIA\n";
        return;
    }

    int z = x;
    while (!check(z)) z+= x;
    cout << z << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}