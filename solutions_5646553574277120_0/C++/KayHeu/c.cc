#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define LL long long
using namespace std;
int flag[40000];
int vis[40000];
void dfs(int n)
{
    flag[n] = 1;
    for(int i = 0; i < 35; i++)
    {
        if(vis[i])
        {
            vis[i] = 0;
            dfs(n + i);
            vis[i] = 1;
        }
    }
}
int main()
{
    freopen("in.in", "r", stdin);
    freopen("out1.out", "w", stdout);
    int T, cse = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(flag, 0, sizeof flag);
        int c, d, v;
        scanf("%d%d%d", &c, &d, &v);
        int num[40000] = {0};
        for(int i = 0; i < d; i++)
        {
            int x;
            scanf("%d", &x);
            num[x] = 1;
        }
        memcpy(vis, num, sizeof(num));
        dfs(0);
        //for(int i = 0; i < 10; i++)
            //cout << flag[i] << " ";
        //puts("");
        int ans = 0;
        for(int i = 1; i <= v; i++)
        {
            if(flag[i] == 0)
            {
                ans++;
                //cout << i << endl;
                int tmp[40000];
                memcpy(tmp, flag, sizeof flag);
                for(int j = 0; j < 35; j++)
                {
                    if(tmp[j])
                        flag[i + j] = 1;
                }
            }
        }
        printf("Case #%d: %d\n", cse++, ans);
    }
    return 0;
}
