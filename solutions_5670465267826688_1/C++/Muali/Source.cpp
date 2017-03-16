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

int mult(int a, int b)
{
    static int res[4][4] = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };
    bool sign = true;
    if (a < 0)
    {
        sign = false;
        a = -a;
    }
    if (b < 0)
    {
        sign = !sign;
        b = -b;
    }
    int r = res[a - 1][b - 1];
    if (!sign)
        r = -r;
    return r;
}

int fast_pow(int a, ll p)
{
    int res = 1;
    for (int i = 0; i < p % 16; ++i)
    {
        res = mult(res, a);
    }
    return res;
}

bool check(vector<int> v, ll l)
{
    int f = 1;
    for (int i = 0; i < v.size(); ++i)
    {
        f = mult(f, v[i]);
    }
    if (fast_pow(f, l) != -1)
        return false;
    f = 1;
    int pos1 = 0;
    for (int i = 0; i < 16; ++i)
    {
        bool ok = false;
        for (int j = 0; j < v.size(); ++j)
        {
            pos1++;
            f = mult(f, v[j]);
            if (f == 2)
            {
                ok = true;
                break;
            }
        }
        if (ok)
            break;
    }
    int pos2 = pos1;
    f = 1;
    for (int i = 0; i < 16; ++i)
    {
        bool ok = false;
        for (int j = 0; j < v.size(); ++j)
        {
            pos2++;
            f = mult(f, v[(j + pos1) % v.size()]);
            if (f == 3)
            {
                ok = true;
                break;
            }
        }
        if (ok && pos2 < (v.size() * l))
            return true;
    }
    return false;
}

void solve()               
{
    ll x, l;
    cin >> x >> l;
    string s;
    cin >> s;
    vector<int> v(x);
    for (int i = 0; i < x; ++i)
    {
        switch (s[i])
        {
        case 'i': v[i] = 2; break;
        case 'j': v[i] = 3; break;
        case 'k': v[i] = 4; break;
        }
    }
    if (check(v, l))
        cout << "YES";
    else
        cout << "NO";
}                                                 


int main() {
	ios_base::sync_with_stdio(false);
    freopen("C-large.in", "r", stdin);
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