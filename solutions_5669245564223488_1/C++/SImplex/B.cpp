#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <set>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <map>
using namespace std;

#define forn(i,n) for(int i = 0; i < (int)n; ++i)
#define _mp(a,b) make_pair(a,b)
#define _pb(x) push_back(x)
#define mins(a,b) a = min(a,b)
#define maxs(a,b) a = max(a,b)

bool all_ok(string const& s, char c)
{
    int l = s.length();
    forn(i,l)
        if (s[i] != c)
            return false;
    return true;
}

int main() {
   ios_base::sync_with_stdio(false);
//    cout << fixed;
//    cout << setprecision(9);
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T = 0;
    cin >> T;
    long long fact[105] = {};
    long long const MOD = 1e9+7;
    fact[0] = 1;
    forn(i,102)
        fact[i+1] = (fact[i]*(i+1))%MOD;
    forn(test, T)
    {
        cout << "Case #" << test + 1 << ": ";
        int n = 0;
        cin >> n;
        vector<string> a(n);
        vector<int> len(n);
        forn(i,n)
        {
            cin >> a[i];
            len[i] = a[i].length();
        }

        long long ans = 1LL;
        forn(i,n)
        {
            vector<bool> mask(500, false);
            forn(j, len[i])
            {
                if (mask[a[i][j]] && a[i][j-1] != a[i][j])
                    ans = 0;
                mask[a[i][j]] = true;
                if (a[i][j] != a[i][0] && a[i][j] != a[i][len[i] - 1])
                    forn(i2, n)
                        forn(j2, len[i2])
                            if (i != i2 && a[i][j] == a[i2][j2])
                                ans = 0;
            }
        }


        int cnt = 0;
     //   while ( !exit )
      //  {
       //     exit = true;
            for(char c = 'a'; c <= 'z'; ++c)
            {
                int st = 0;
                int fin = 0;
                int all = 0;
                forn(i,a.size())
                {
                    int len = a[i].length();
                    if (all_ok(a[i], c))
                        ++all;
                    else
                    {
                        if (a[i][0] == c)
                        {
                            ++st;
                            if (a[i][len - 1] == c)
                                ans = 0;
                        }
                        if (a[i][len-1] == c)
                            ++fin;
                    }
                }
                if (max(st,fin) > 1)
                    ans = 0;
                if (ans == 0)
                    break;
                ans = (ans*fact[all])%MOD;
                forn(i,a.size())
                {
                    while (i < a.size() && all_ok(a[i], c))
                        a.erase(a.begin() + i);
                }
                if (st == fin && st == 1)
                {
                    int start = -1;
                    int finish = -1;
                    forn(i,a.size())
                    {
                        int len = a[i].length();
                        if (a[i][0] == c)
                            start = i;
                        if (a[i][len-1] == c)
                            finish = i;
                    }
                    string tmp = a[finish] + a[start];
                   // cout << "to " << c << " " <<  a[finish] << " " << a[start] << endl;
                    a.erase(a.begin() + max(finish,start));
                    a.erase(a.begin() + min(finish, start));
                    a._pb(tmp);
                }
                if (st == 0 && fin == 0 && all > 0)
                    ++cnt;
            }
     /*   forn(i, a.size())
            cout << a[i] << "\n";
        cout << ans << " " << cnt << endl;*/
        ans = (ans * fact[a.size() + cnt]) % MOD;
        cout << ans << "\n";
    }

    return 0;
}
