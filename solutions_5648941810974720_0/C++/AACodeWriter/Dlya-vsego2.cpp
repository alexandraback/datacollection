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

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t;
    string a;
    map < char, ll > mt;
    vector < ll > num(10);

    cin >> t;

    forl(q, 1, t)
    {
        cin >> a;

        forn(i, a.length())
        {
            a[i] = tolower(a[i]);
            mt[a[i]]++;
        }

        while(mt['z'] > 0)
        {
            mt['z']--;
            mt['e']--;
            mt['r']--;
            mt['o']--;
            num[0]++;
        }

        while(mt['w'] > 0)
        {
            mt['t']--;
            mt['w']--;
            mt['o']--;
            num[2]++;
        }

        while(mt['u'] > 0)
        {
            mt['f']--;
            mt['o']--;
            mt['u']--;
            mt['r']--;
            num[4]++;
        }

        while(mt['x'] > 0)
        {
            mt['s']--;
            mt['i']--;
            mt['x']--;
            num[6]++;
        }

        while(mt['g'] > 0)
        {
            mt['e']--;
            mt['i']--;
            mt['g']--;
            mt['h']--;
            mt['t']--;
            num[8]++;
        }

        while(mt['o'] > 0)
        {
            mt['o']--;
            mt['n']--;
            mt['e']--;
            num[1]++;
        }

        while(mt['t'] > 0)
        {
            mt['t']--;
            mt['h']--;
            mt['r']--;
            mt['e']--;
            mt['e']--;
            num[3]++;
        }

        while(mt['f'] > 0)
        {
            mt['f']--;
            mt['i']--;
            mt['v']--;
            mt['e']--;
            num[5]++;
        }

        while(mt['v'] > 0)
        {
            mt['s']--;
            mt['e']--;
            mt['v']--;
            mt['e']--;
            mt['n']--;
            num[7]++;
        }

        while(mt['n'] > 0)
        {
            mt['n']--;
            mt['i']--;
            mt['n']--;
            mt['e']--;
            num[9]++;
        }

        cout << "Case #" << q << ": ";

        forn(i, 10)
        {
            forn(j, num[i])
            cout << i;
            num[i] = 0;
        }
        cout << endl;
    }


}
