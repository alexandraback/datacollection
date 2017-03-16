#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tb[6][6];
int b, m;
bool check()
{
    int dg[6] {}, dp[6] {};
    for(int i = 0; i < b; ++i)
        for(int j = 0; j < b; ++j)
            dg[j] += tb[i][j];
    vector<int> s;
    for(int i = 0; i < b; ++i)
        if(dg[i] == 0)
            s.push_back(i);
    reverse(s.begin(), s.end());
    vector<int> sol;
    while(!s.empty())
    {
        int c = s.back();
        sol.push_back(c);
        s.pop_back();
        for(int i = 0; i < b; ++i)
        {
            if(tb[c][i])
            {
                dg[i] -= tb[c][i];
                if(dg[i] == 0)
                    s.push_back(i);
            }
        }
    }
    if(sol.size() != b) return false;
    dp[0] = 1;
    for(int i = 0; i < b; ++i)
    {
        int c = sol[i];
        for(int j = 0; j < b; ++j)
            if(tb[c][j])
                dp[j] += dp[c];
    }
    return (dp[b-1] == m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int z;
    cin >> z;
    for(int t = 1; t <= z; ++t)
    {
        cin >> b >> m;
        bool f = false;
        for(int i = 0; i < (1 << (b-1)*(b-1)); ++i)
        {
            int j = i;
            for(int ii = 0; ii < b; ++ii)
                for(int jj = 1; jj < b; ++jj)
                    tb[ii][jj] = j&1, j >>= 1;
            if(check())
            {
                cout << "Case #" << t << ": POSSIBLE\n";
                for(int ii = 0; ii < b; ++ii)
                    for(int jj = 0; jj < b; ++jj)
                        cout << tb[ii][jj] << " \n"[jj==b-1];
                f = true;
                break;
            }
        }
        if(!f)
            cout << "Case #" << t << ": IMPOSSIBLE\n";
    }
    return 0;
}
