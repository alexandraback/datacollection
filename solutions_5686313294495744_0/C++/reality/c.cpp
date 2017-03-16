# include <bits/stdc++.h>
using namespace std;
# define x first
# define y second
# define ll long long
# define db long double
ifstream fi("c.in");
ofstream fo("c.out");
map < string , int > cnt;
pair < int , int > s[1 << 20];
int dp[1 << 16];
int main(void)
{
    int t;
    fi>>t;
    for (int cs = 1;cs <= t;++cs)
    {
        cerr << cs << '\n';
        fo << "Case #" << cs << ": ";
        int n;
        cnt.clear();
        fi>>n;
        int sz = 0;
        for (int i = 0;i < n;++i)
        {
            string a,b;
            fi>>a>>b;
            if (!cnt.count(a)) cnt[a] = ++sz;
            if (!cnt.count(b)) cnt[b] = ++sz;
            s[i] = {cnt[a],cnt[b]};
        }
        int mx = 1 << n;
        for (int i = 0;i < mx;++i) dp[i] = 0;
        for (int mask = 1;mask < mx;++mask)
            for (int i = 0;i < n;++i)
                if ((mask >> i)&1)
                {
                    int cnt = dp[mask ^ (1 << i)];
                    int ok1 = 0,ok2 = 0;
                    for (int j = 0;j < n;++j)
                        if (i != j && ((mask >> j)&1))
                            ok1 += s[j].x == s[i].x,ok2 += s[j].y == s[i].y;
                    cnt += ok1 && ok2;
                    dp[mask] = max(dp[mask],cnt);
                }
        fo << dp[mx - 1] << '\n';
    }
    return 0;
}

