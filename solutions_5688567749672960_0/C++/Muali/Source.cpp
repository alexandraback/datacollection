#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cassert>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair                                                  

ll reverse(ll n)
{
    string s;
    s = to_string(n);
    for (int i = 0; i < s.size() / 2; ++i)
    {
        swap(s[i], s[s.size() - 1 - i]);
    }
    return stoll(s);
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    queue<pair<ll, ll>> calc;
    map<int, bool> used;
    calc.push(make_pair(1LL, 1LL));
    while (true)
    {
        auto top = calc.front();
        calc.pop();
        if (used.find(top.second + 1) == used.end())
        {
            used[top.second + 1] = true;
            calc.push(mp(top.first + 1, top.second + 1));
        }
        ll rev = reverse(top.second);
        if (used.find(rev) == used.end())
        {
            used[rev] = true;
            calc.push(mp(top.first + 1, rev));
        }
        if (rev == n || top.second + 1 == n)
        {
            cout << top.first + 1 << endl;
            return;
        }
    }
}              

int main() {
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}