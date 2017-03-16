#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int flagg[10000001];
typedef long long llong;
int bfs(int n)
{
    memset(flagg, -1, sizeof(flagg));
    queue<int> que;
    que.push(1);
    flagg[1] = 1;
    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        if(now == n)
            return flagg[n];
        if(flagg[now + 1] < 0)
        {
            flagg[now + 1] = flagg[now] + 1;
            que.push(now + 1);
        }
        int noww = 0;
        for(int tmp = now; tmp != 0; tmp /= 10)
            noww = noww * 10 + tmp % 10;
        if(noww <= 10000000 && flagg[noww] < 0)
        {
            flagg[noww] = flagg[now] + 1;
            que.push(noww);
        }
    }
    return -1;
}

int main()
{
    int T = 0,Cases=0;
    while(scanf("%d", &T)!=EOF)
    {
        Cases=0;
        while(T--)
        {
            int n = 0;
            scanf("%d", &n);
            int ans = bfs(n);
            printf("Case #%d: %d\n", ++Cases, ans);
        }
    }
    return 0;
}
