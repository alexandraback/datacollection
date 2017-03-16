#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int D;
int P[1000];

bool check(const int m)
{
    for(int k = 0; k < m; ++k)
    {
        int cnt = 0;
        for(int i = 0; i < D; ++i)
            cnt += (P[i] - 1) / (m - k);
        if(cnt <= k)
            return true;
    }
    return false;
}

void solve(const int t)
{
    cin >> D;
    for(int i = 0; i < D; ++i)
        cin >> P[i];
    
    int l = 0, r = 1010;
    while(l + 1 < r)
    {
        int m = (l + r) / 2;
        if(check(m))
            r = m;
        else
            l = m;
    }
    cout << "Case #" << t << ": " << l + 1 << "\n";
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        cerr << "Solving #" << t << "\n";
        solve(t);
    }
    return 0;
}
