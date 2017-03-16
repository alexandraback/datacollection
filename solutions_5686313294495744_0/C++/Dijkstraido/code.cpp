#include <bits/stdc++.h>
using namespace std;

typedef pair<string,string> ss;
ss v[20];
int n;
int dp[1 << 16];

int solve(int mask)
{
    if(dp[mask] != -1) return dp[mask];

    int ans = 0;
    for(int i = 0; i < n; i++)
        if(!(mask & (1 << i)))
        {
            bool f1 = false, f2 = false;
            for(int j = 0; j < n; j++)
                if(i != j && (mask & (1 << j)))
                {
                    if(v[i].first == v[j].first)
                        f1 = true;
                    if(v[i].second == v[j].second)
                        f2 = true;
                }

            int cont;
            if(f1 && f2) 
                cont = 1;
            else
                cont = 0;

            ans = max(ans, cont + solve(mask | (1 << i)));
        }
    return dp[mask] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,ntest=1;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;

        memset(dp, -1, sizeof dp);
        cout << "Case #" << ntest++ << ": " << solve(0) << '\n';
    }
    return 0;
}