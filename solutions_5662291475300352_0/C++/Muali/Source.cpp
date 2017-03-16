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
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (hs[0].second > hs[1].second)
        swap(hs[0], hs[1]);
    double t1 = hs[1].second * (360. - hs[1].first) / 360.;
    double t2 = hs[0].second * (720. - hs[0].first) / 360.;
    if (t1 >= t2)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}              

int main() {
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}