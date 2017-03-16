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

double getmx(pii h)
{
    double t1 = h.second * (360. - h.first) / 360.;
    return t1;
}

ll cnt(double s, pii h)
{
    if (s > h.second)
    {
        double t1 = h.second * (360. - h.first) / 360.;
        t1 = s - t1;
        return t1 / h.second;
    }
    else
    {
        double t1 = s;
        double t2 = h.second * (360. - h.first) / 360.;
        if (t1 < t2)
            return 1;
        else
            return 0;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<pii> hs;
    for (int i = 0; i < n; ++i)
    {
        int d, h, s;
        cin >> d >> h >> s;
        for (int i = 0; i < h; ++i)
        {
            hs.push_back(mp(d, s));
            ++s;
        }
    }
    int best = hs.size();
    for (int i = 0; i < hs.size(); ++i)
    {
        ll cur = 0;
        for (int j = 0; j < hs.size(); ++j)
        {
            cur += cnt(getmx(hs[i]), hs[j]);
        }
        if (cur < best)
            best = cur;
    }
    cout << best << endl;
}

int main() {
    freopen("C-small-2-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}