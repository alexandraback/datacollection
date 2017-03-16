#include <bits/stdc++.h>

#define forn(i,n) for(long long i = 0; i < n; i++)
#define ford(i,n) for(long long i = n - 1; i > -1; i--)
#define forl(i,l,r) for(long long i = l; i <= r; i++)
#define forst(it, a, ll) for(set < ll > :: iterator it = a.begin(); it != a.end(); it++)
#define forld(i,l,r) for(long long i = l; i >= r; i--)
#define FAST_READ ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define INF 100000000000
#define MOD 1000000007
#define pi 3.14159265358973238462643383
#define EPS 0.00000001
#define f first
#define s second
#define pb push_back
#define mp(i, j) make_pair(i, j)
#define COUT(n, a) fixed << setprecision(a) << n

using namespace std;

typedef unsigned long long ull;
typedef int long long ll;
typedef long double ld;
typedef string str;

int main(void)
{
    FAST_READ

    freopen("B-small-attempt2.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t, mx;
    string a, b;

    cin >> t;

    forl(q, 1, t)
    {
        cin >> a >> b;
        mx = 3;

        forn(i, a.length())
        {
            if (a[i] == '?' && b[i] == '?' && mx == 3)
                a[i] = b[i] = '0';
            else
                if (a[i] == '?' || b[i] == '?')
            {
                if (mx == 3 && (a[i] != '?' || b[i] != '?'))
                    a[i] = b[i] = (a[i] == '?' ? b[i] : a[i]);
                else
                {
                    if (mx == 1)
                    {
                        if (a[i] == '?')
                        a[i] = '0';
                        if (b[i] == '?')
                        b[i] = '9';
                    }
                    else
                    if (mx == 2)
                    {
                        if (a[i] == '?')
                        a[i] = '9';
                        if (b[i] == '?')
                        b[i] = '0';
                    }
                    else
                    {
                        a[i] = b[i] = (a[i] == '?' ? b[i] : a[i]);
                    }
                }
            }
            else
                if (mx == 3)
            {
                if (a[i] - '0' > b[i] - '0')
                {
                    mx = 1;
                }
                else
                    if (a[i] - '0' < b[i] - '0')
                {
                    mx = 2;
                }
            }
        }

        cout << "Case #" << q << ": " << a << ' ' << b << endl;
    }
}
