#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long ll;

void solve(void)
{
    string s;
    cin >> s;
    int p = s.find("/");
    ll a = atoll(s.substr(0, p).c_str());
    ll b = atoll(s.substr(p + 1, s.size() - p).c_str());

    ll t = b;
    int cnt = 0;
    while (t % 2 == 0)
    {
        t /= 2;
        ++cnt;
    }

    if (a % t != 0)
    {
        cout << "impossible" << endl;
        return;
    }
    a /= t;
    b /= t;

    t = a;
    while (t > 1)
    {
        t /= 2;
        --cnt;
    }

    cout << cnt << endl;
}

int main(void)
{
    int numTest;
    cin >> numTest;
    for (int testCase = 1; testCase <= numTest; ++testCase)
    {
        cout << "Case #" << testCase << ": ";
        solve();
    }
    return 0;
}
