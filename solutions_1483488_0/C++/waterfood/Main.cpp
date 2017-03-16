#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>
using namespace std;

struct Pair
{
public:
    int n;
    int m;
};
bool operator==(Pair& a, Pair& b)
{
    return a.n == b.n && a.m == b.m;
}
bool comp(Pair& a, Pair& b)
{
    if (a.n == b.n)
    {
        return a.m < b.m;
    }
    else
    {
        return a.n < b.n;
    }
}
int powOfTen[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
vector<Pair> pairs;

// l: digit length, k: the kth digit has been added to n and m
int TryOneDigit(int lo, int hi, int sh, int l, int k, int n, int m)
{
    if (n > hi || m > hi)
    {
        return 0;
    }
    else if (lo - n >= powOfTen[l-k])
    {
        return 0;
    }
    else if (k + sh > l && (lo - m) >= powOfTen[l-(k+sh-l)])
    {
        return 0;
    }
    else if (k == l)
    {
        if (lo <= m && n != m)
        {
            Pair p = {n, m};
            pairs.push_back(p);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int ans = 0;
        k++;
        int j = (sh + k - 1) % l + 1;
        for (int i = 0; i < 10; i++)
        {
            ans += TryOneDigit(lo, hi, sh, l, k, n, m);
            n += powOfTen[l-k];
            m += powOfTen[l-j];
        }
        return ans;
    }
}

int Algo1(int lower, int upper)
{
    int len = (int)floor(log10((double)lower)) + 1;
    int ans = 0;
    for (int sh = 1; sh < len; sh++)
    {
        int n = 0, m = 0;
        for (int i = 0; i < 10; i++)
        {
            ans += TryOneDigit(lower, upper, sh, len, 1, n, m);
            n += powOfTen[len-1];
            m += powOfTen[len-sh-1];
        }
    }
    return ans / 2;
}

int main()
{
    ifstream in("C-small-attempt0.in");
    ofstream out("C-small-attempt0.out");
    pairs.resize(500000);

    int T;
    in >> T;
    for (int x = 0; x < T; x++)
    {
        int lo, hi;
        in >> lo >> hi;
        pairs.clear();

        Algo1(lo, hi);
        sort(pairs.begin(), pairs.end(), comp);
        int ans = pairs.size();
        for (int i = 1; i < pairs.size(); i++)
        {
            if (pairs[i-1] == pairs[i])
            {
                ans--;
            }
        }
        ans = ans / 2;

        out << "Case #" << (x+1) << ": " << ans;
        out << endl;
    }
    in.close();
    out.close();
    return 0;
}
