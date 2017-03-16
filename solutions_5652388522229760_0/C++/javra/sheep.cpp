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

#define DEBUG(s) cout << "*** " << (s) << " ***\n"

void solve()
{
    int N;
    cin >> N;

    if(N == 0)
    {
        cout << "INSOMNIA";
        return;
    }

    bool seen[10] = {0};

    for(int i = 1; i < 100; i++)
    {
        int n = N*i;
        for(char c : to_string(n))
        {
            seen[c - '0'] = true;
        }
        bool done = true;
        for(bool b : seen)
        {
            if(!b)
                done = false;
        }
        if(done)
        {
            cout << n;
            return;
        }
    }
    cout << "panic!";
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

