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

map < string, ll > ac, bc;

bool pred1 (pair < str, str > a, pair < str, str > b)
{
    return ac[a.f] < ac[b.f];
}

bool pred2 (pair < str, str > a, pair < str, str > b)
{
    return bc[a.s] < bc[b.s];
}

int main(void)
{
    FAST_READ

    freopen("C-small-attempt4.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t, ans, ans2, s1, s2, n;
    string a, b;
    set < string > st1, st2;
    vector < pair < str, str > > ca;

    cin >> t;

    forl(q, 1, t)
    {
        cin >> n;
        ans = ans2 = 0;
        st1.clear();
        st2.clear();
        ac.clear();
        bc.clear();
        ca.clear();

        forn(i, n)
        {
            cin >> a >> b;

            ac[a]++;
            bc[b]++;

            ca.pb(mp(a, b));
        }

        sort(ca.begin(), ca.end(), pred1);

        forn(i, n)
        {
            s1 = st1.size();
            s2 = st2.size();

            st1.insert(ca[i].f);
            st2.insert(ca[i].s);

            if (st1.size() - s1 == 0 && st2.size() - s2 == 0)
                ans++;
        }

        sort(ca.begin(), ca.end(), pred2);
        st1.clear();
        st2.clear();

        forn(i, n)
        {
            s1 = st1.size();
            s2 = st2.size();

            st1.insert(ca[i].f);
            st2.insert(ca[i].s);

            if (st1.size() - s1 == 0 && st2.size() - s2 == 0)
                ans2++;
        }

        cout << "Case #" << q << ": " << max(ans, ans2) << endl;
    }
}
