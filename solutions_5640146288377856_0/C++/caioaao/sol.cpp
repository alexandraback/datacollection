#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXB (1<<15)
#define INF 1e8

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

int w, c;

inline bool onlyFitsInOnePlace(int bm)
{
    int last = -1;
    int ret = 0;
    for(int i = 0; i < c; ++i)
    {
        if(!(bm & (1<< i)))
        {
            if(i - last >= w)
                ++ret;
        }
        else
            last = i;
    }
    return (ret == 1);
}

int memo[MAXB];

int dp(int bm)
{
    if(memo[bm] < 0)
    {
        if(onlyFitsInOnePlace(bm))
        {
            memo[bm] = w;
        }
        else
        {
            memo[bm] = INF;
            for(int i = 0; i < c; ++i)
                if(!(bm & (1 << i)))
                    memo[bm] = min(memo[bm], 1 + dp(bm | (1 << i)));

        }
    }
    
    return memo[bm];
}

void solve()
{
    int r;
    cin >> r >> c >> w;
    memset(memo, -1, sizeof memo);
    cout << dp(0) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}
