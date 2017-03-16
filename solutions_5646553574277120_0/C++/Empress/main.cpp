//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<climits>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
#include<map>
#include<queue>
#define lson l, mid
#define rson (mid+1), r
#define pb push_back

int a[10];
bool vis[135];
int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        int c, d, v;
        scanf("%d%d%d", &c, &d, &v);
        memset(vis, 0, sizeof(vis));
        vis[0]=1;
        for(int i=0; i<d; i++)
        {
            int x;
            scanf("%d", &x);
            for(int j=v; j>=x; j--)
                vis[j]=vis[j] || vis[j-x];
        }
        printf("Case #%d: ", ca++);
        int ans=0;
        for(int i=1; i<=v; i++)
            if(!vis[i])
            {
                for(int j=v; j>=i; j--)
                    vis[j]=vis[j] || vis[j-i];
                ans++;
            }
        printf("%d\n", ans);
    }
    return 0;
}
