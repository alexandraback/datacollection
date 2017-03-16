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


vector<lng> solve()
{
    vector<lng> res;
    lng k, c, s;

    cin >> k >> c >> s;

    if(c * s < k)
    {
        return res;
    }

    lng cur = 0;
    int j = 1;
    for(int i = 0; i < k; ++i, ++j)
    {
        cur *= k;
        cur += i;

        if(j == c)
        {
            res.push_back(cur);
            cur = 0;
            j = 0;
        }
    }

    if(j != 1)
    {
        res.push_back(cur);
    }


    return res;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int T;
    cin >> T;
    forn(tc, T) {
        auto res = solve();

        std::cout << "Case #" << tc + 1 << ": ";
        if(res.empty())
        {
            cout << "IMPOSSIBLE";
        }
        else{
            forv(i, res)
            {
                cout << res[i] + 1 << " ";
            }
        }

        std::cout << endl;
    }
    
    return 0;
}
