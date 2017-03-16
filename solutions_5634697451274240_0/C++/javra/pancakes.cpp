#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
typedef long long int llint;

#define debug(s) cout << "*** " << (s) << " ***\n"

void solve()
{
    string s;
    getline(cin, s);
    s += '+';

    int flips = 0;
    for(int i = 0; i < s.size()-1; i++)
    {
        if(s[i] != s[i+1])
            flips += 1;
    }
    cout << flips;
}

int main()
{
    int T;
    cin >> T;
    cin.get();
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

