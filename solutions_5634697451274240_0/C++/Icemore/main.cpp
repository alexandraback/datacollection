#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define forv(i, a) forn(i, (int)(a).size())

typedef long long lng;

vector<int> read()
{
    string str;
    cin >> str;
    
    vector<int> a(str.size());

    forv(i, str)
    {
        a[i] = str[i] == '+' ? 1 : 0;
    }
    
    return a;
}

int d[500][2];

int solve()
{
    auto a = read();
    int n = a.size();

    forn(i, n)
    {
        forn(t, 2)
        {
            if(i == 0)
            {
                d[i][t] = a[i] == t ? 0 : 1;
            }
            else
            {
                d[i][t] = (a[i] == t) ? (d[i-1][t]) : (d[i-1][1-t] + 1);
            }
        }
    }

    return d[n-1][1];
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int T;
    cin >> T;
    forn(tc, T) {
        auto res = solve();

        std::cout << "Case #" << tc + 1 << ": " << res << endl;
    }
    
    return 0;
}
