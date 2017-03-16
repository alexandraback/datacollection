#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair            

bool ac(int c, vector<pii> d)
{
    for (int i = 0; i < d.size(); ++i)
        d[i].second = 0;
    for (int i = 0; i < c; ++i)
    {
        int rem = c - i;
        bool suc = true;
        for (int j = 0; j < d.size(); ++j)
        {
            if (d[j].first > rem)
                suc = false;
        }

        if (suc)
            return true;

        for (int j = 0; j < d.size(); ++j)
        {
            if (d[j].second != 0)
                d[j].first += d[j].second;
        }

        for (int j = 0; j < d.size(); ++j)
        {
            if (d[j].first > rem)
            {
                d[j].second++;
                d[j].first -= rem - 1;
                break;
            }
        }
    }
    return false;
}

int bs(int l, int r, vector<pii>& d)
{
    if (l == r)
        return l;
    int m = (l + r) / 2;
    if (ac(m, d))
        return bs(l, m, d);
    else
        return bs(m + 1, r, d);
}

void solve()               
{
    int d;
    cin >> d;
    vector<pii> din(d);
    for (int i = 0; i < d; ++i)
    {
        cin >> din[i].first;
    }
    cout << bs(1, 1005, din);
}                                                 


int main() {
	ios_base::sync_with_stdio(false);
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << endl;
    }
}