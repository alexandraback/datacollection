#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

#define small
//#define large

int path[2000][15];
vector <int> ans;
int t, n, m;

void solve()
{
    for(int i = 1; i <= n; i ++)
    {
        ans.clear();
        for(int j = 1; j <= path[i][0]; j ++)
            ans.push_back(path[i][j]);
        for(int j = 0; j != ans.size(); j ++)
        {
            for(int k = 1; k <= path[ans[j]][0]; k ++)
            {
                for(int l = 0; l != ans.size(); l ++)
                    if(ans[l] == path[ans[j]][k])
                    {
                        printf("Yes\n");
                        return ;
                    }
                ans.push_back(path[ans[j]][k]);
            }
        }
    }
    printf("No\n");
}

int main()
{
#ifdef small
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
#endif

#ifdef large
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif
    
    scanf("%d", &t);
    for(int c = 1; c <= t; c ++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &m);
            path[i][0] = m;
            for(int j = 1; j <= m; j ++)
                scanf("%d", &path[i][j]);
        }
        printf("Case #%d: ", c);
        solve();
    }
//    system("pause");
    return 0;
}
