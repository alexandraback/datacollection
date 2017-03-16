/*

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int Case;
int n, g[1001][1001];
bool h[1001];
bool dfs(int x)
{
    if (h[x]) return true;
    h[x]=true;
    for (int i=1;i<=g[x][0];i++)
        if (dfs(g[x][i])) return true;
    return false;
}
void display()
{
    scanf("%d",&Case);
    for (int ca=1;ca<=Case;ca++) {
        printf("Case #%d: ",ca);
        scanf("%d",&n);
        memset(g,0,sizeof(g));
        for (int i=1;i<=n;i++) {
            scanf("%d",&g[i][0]);
            for (int j=1;j<=g[i][0];j++)
                scanf("%d",&g[i][j]);
        }
        bool flag = false;
        for (int i=1;i<=n;i++) {
            memset(h,0,sizeof(h));
            if (dfs(i)) {
                flag = true;
                printf("Yes\n");
                break;
            }
        }
        if (!flag) printf("No\n");
    } 
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    display();
    return 0;
}

