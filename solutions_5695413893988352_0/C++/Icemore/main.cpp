#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define forv(i, a) forn(i, (int)(a).size())

typedef long long lng;

bool is_match(string& pattern, int num)
{
    for(int i = pattern.size() - 1; i >= 0; --i, num/=10)
    {
        if(pattern[i] == '?')
            continue;

        if(pattern[i]-'0' != num%10)
        {
            return false;
        }
    }
    return true;
}

string solve()
{
    string one, two;
    cin >> one >> two;

    int n = one.size();
    int maxn = 1;
    forn(i, n) maxn *= 10;

    pair<int, int> ans;
    int mind = 1000*1000*1000;
    forn(first, maxn) forn(second, maxn)
    {
        if(!is_match(one, first) || !is_match(two, second))
            continue;

        if(abs(first - second) < mind)
        {
            mind = abs(first - second);
            ans = make_pair(first, second);
        }
    }

    stringstream ss;
    ss << setw(n) << setfill('0') << ans.first;
    ss << " ";
    ss << setw(n) << setfill('0') << ans.second;


    return ss.str();
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
