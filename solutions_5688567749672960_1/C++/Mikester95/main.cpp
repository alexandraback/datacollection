#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("test.in");
ofstream fout("test.out");

int v[30];

long long solve()
{
    long long n;
    fin >> n;

    long long ans = 0;

    if (n < 10)
    {
        return n;
    }
    else ans += 10;

    long long pw = 100;
    long long pw2 = 9;
    int i = 1;

    while (n >= pw)
    {
        if (i&1)
        {
            ans += pw2 + pw2 + 1;
        }
        else
        {
            ans += pw2 + pw2*10 + 9 + 1;
            pw2 = pw2 * 10 + 9;
        }

        ++i;
        pw = pw*10;
    }

    if (n == pw/10)
    {
        return ans;
    }

    if (n%10 == 0)
    {
        n--;
        ++ans;
    }

    long long x = n;
    int t = 0;

    while (x > 0)
    {
        v[++t] = x%10;
        x /= 10;
    }

    long long rez = 0;

    int mid = t/2;
    if(t&1)
        ++mid;

    for (int i = mid; i >= 1; --i)
    {
        rez = rez*10 + v[i];
    }
    ans += rez;
    rez = 0;

    for (i = mid+1; i <= t; ++i)
    {
        rez = rez*10 + v[i];
    }
    if (rez != 1)
        ans += rez;

    return ans;
}

int main()
{
    int test;
    fin >> test;

    for (int k = 1; k <= test; ++k)
    {
        long long ans = solve();

        fout << "Case #" << k << ": " << ans << "\n";
    }
}
