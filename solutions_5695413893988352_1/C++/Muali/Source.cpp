#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cstring>

using namespace std;

using ll = long long;

ifstream in;
ofstream out;

struct ans
{
    string a, b;
    ll dif;
};

bool operator<(ans const& a, ans const& b)
{
    if (a.dif != b.dif)
        return a.dif < b.dif;
    if (a.a != b.a)
        return a.a < b.a;
    return a.b < b.b;
}

ans s1(string a, string b, int i, bool eq, bool gr)
{
    if (i == a.size())
    {
        ll av = stoll(a);
        ll bv = stoll(b);
        return ans{a, b, llabs(av - bv)};
    }


    ans cans = {"", "", 1e18 + 5};
    if (eq)
    {
        if (a[i] == '?' && b[i] == '?')
        {
            a[i] = '0';
            b[i] = '0';
            cans = min(cans, s1(a, b, i + 1, true, gr));
            a[i] = '1';
            cans = min(cans, s1(a, b, i + 1, false, true));
            a[i] = '0';
            b[i] = '1';
            cans = min(cans, s1(a, b, i + 1, false, false));
            return cans;
        }    

        if (a[i] == '?')
        {
            a[i] = b[i];
            cans = min(cans, s1(a, b, i + 1, true, gr));
            a[i] = b[i] + 1;
            if (a[i] <= '9')
                cans = min(cans, s1(a, b, i + 1, false, true));
            a[i] = b[i] - 1;
            if (a[i] >= '0')
                cans = min(cans, s1(a, b, i + 1, false, false));
            return cans;
        }

        if (b[i] == '?')
        {
            b[i] = a[i];
            cans = min(cans, s1(a, b, i + 1, true, gr));
            b[i] = a[i] + 1;
            if (b[i] <= '9')
                cans = min(cans, s1(a, b, i + 1, false, false));
            b[i] = a[i] - 1;
            if (b[i] >= '0')
                cans = min(cans, s1(a, b, i + 1, false, true));
            return cans;
        }

        if (a[i] == b[i])
            return s1(a, b, i + 1, eq, gr);
        if (a[i] < b[i])
            return s1(a, b, i + 1, false, false);
        return s1(a, b, i + 1, false, true);
    }

    if (gr)
    {
        if (a[i] == '?')
            a[i] = '0';
        if (b[i] == '?')
            b[i] = '9';
        return s1(a, b, i + 1, eq, gr);
    }

    if (a[i] == '?')
        a[i] = '9';
    if (b[i] == '?')
        b[i] = '0';
    return s1(a, b, i + 1, eq, gr);
}

void solve()
{
    string a, b;
    in >> a >> b;
    ans an = s1(a, b, 0, true, false);
    out << an.a << " " << an.b;
}

int main(int argc, char const *argv[])
{
    in = ifstream(argv[1]);
    out = ofstream(argv[2]);
    //in = ifstream("in.txt");
    //out = ofstream("out.txt");
    int n;
    in >> n;
    for (int i = 0; i < n; ++i)
    {
        out << "Case #" << i + 1 << ": ";
        solve();
        out << endl;
    }
}