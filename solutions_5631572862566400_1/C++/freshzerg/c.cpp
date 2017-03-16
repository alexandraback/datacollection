#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int vis[1001];
vector<int>BFF[1001];
int BFFR[1001];
int N;

int dfs(int src, int ban)
{
    int maxD = 0;
    for (int i = 0; i < BFF[src].size(); i++)
    {
        if (BFF[src][i] != ban)
        {
            maxD = max(maxD, dfs(BFF[src][i], ban));
        }
    }
    return 1 + maxD;
}
int getcircle(int src)
{
    memset(vis,0,sizeof(vis));
    int st = src;
    int res = 1;
    vis[st] = 1;
    while(!vis[BFFR[st]])
    {
        st = BFFR[st];
        vis[st] = 1;
        res++;
    }
    if(BFFR[st] != src) return 0;
    else return res;
}
int main()
{
    int T; cin >> T;
    for (int TT = 1; TT <= T; ++TT)
    {

        printf("Case #%d: ", TT);
        cin >> N;
        for (int i = 1; i <= N; ++i)
        {
            BFF[i].clear();
        }
        for (int i = 1; i <= N; ++i)
        {
            scanf("%d", &BFFR[i]);
            BFF[BFFR[i]].push_back(i);
        }
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            int bffs = BFFR[i];
            if (bffs > i && BFFR[bffs] == i)
            {
                int numberR = dfs(i, bffs);
                int numberL = dfs(bffs, i);
                ans += numberL + numberR;
            }
        }
        for(int i = 1; i <= N; ++i)
        {
            ans = max(ans,getcircle(i));
        }
        printf("%d\n", ans);
    }
    return 0;
}