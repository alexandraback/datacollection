#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <assert.h>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int n;

void print(long long z , int len)
{
    if(!len)      return;
    print(z >> 1 , len - 1);
    printf("%d" , z & 1);
}

int bfs(string x)
{
    string finish;
    map < string , int > M;
    for(int i = 0;i < (int)x.size();++i)
        finish += '+';

    queue < string > q;
    q.push(x);
    M[x] = 1;
    while(!q.empty())
    {
        string temp = q.front();        q.pop();

        int vis = M[temp];
        for(int i = 0;i < n;++i)
        {
            string p = temp;
            for(int j = 0 , c = i;j <= i;++j , --c)
            {
                if(temp[j] == '+')
                    p[c] = '-';

                else
                    p[c] = '+';
            }
            if(M.find(p) == M.end())
            {
                M[p] = vis + 1;
                q.push(p);
            }
            if(p == finish)
                return M[p] - 1;
        }
    }
    assert(0 and "how could that happen");
    return 0;
}

///0 -> -
///1 -> +

int dp[105][2];

int doit(string s)
{
    if(s[0] == '-')
    {
        dp[0][0] = 0;
        dp[0][1] = 1;
    }
    else
    {
        dp[0][0] = 1;
        dp[0][1] = 0;
    }

    for(int i = 1;i < (int)s.size();++i)
    {
        if(s[i] == '-')
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][0] + 1;
        }
        else
        {
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = dp[i - 1][1] + 1;
        }
    }
    return dp[s.size() - 1][1];
}

int main()
{
    freopen("B-large.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T , c = 0;
    cin >> T;
    while(T--)
    {
        ++c;
        string s;
        cin >> s;
        n = s.size();

        cout << "Case #" << c << ": ";

        int ans = doit(s);
        cout << ans << "\n";

        cerr << c << "  ->   done  " << ans << "\n";

    }
    return 0;
}
