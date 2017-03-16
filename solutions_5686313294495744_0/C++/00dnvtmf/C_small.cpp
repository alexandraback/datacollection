//writed by dnvtmf
#include <bits/stdc++.h>
#define INF 1000000007
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
const int NUM = 20;
int n;
char topics[NUM][2][22];
map<string, int> mp[2];
map<string, int>::iterator it;
int words_num[2];
int id[NUM][2];
int solve()
{
    mp[0].clear(); mp[1].clear();
    words_num[0] = words_num[1] = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            it = mp[j].find(topics[i][j]);
            if(it == mp[j].end())
            {
                id[i][j] = words_num[j];
                mp[j][string(topics[i][j])] = words_num[j]++;
            }
            else
            {
                id[i][j] = it->SE;
            }
        }
    }
    int ans = 0;
    for(int mask = (1 << n) - 1; mask >= 0; --mask)
    {
        bool vis[NUM][2] = {};
        for(int i = 0; i < n; ++i)
        {
            if(!(mask & (1 << i)))
            {
                vis[id[i][0]][0] = true;
                vis[id[i][1]][1] = true;
            }
        }
        bool flag = true;
        for(int i = 0; flag && i < n; ++i)
        {
            if(mask & (1 << i))
            {
                if(vis[id[i][0]][0] && vis[id[i][1]][1])
                    flag = true;
                else
                    flag = false;
            }
        }
        if(flag)
        {
            int res = 0;
            for(int i = 0; i < n; ++i)
            {
                if(mask & (1 << i))
                {
                    ++res;
                }
            }
            ans = max(ans, res);
        }
    }
    return ans;
}
int main()
{
#ifdef ACM_TEST
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
        {
            scanf("%s %s", topics[i][0], topics[i][1]);
        }
        printf("Case #%d: %d\n", cas, solve());
    }
    return 0;
}
