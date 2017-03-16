#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<utility>
using namespace std;
const int maxn = 1010;
pair <int, int> a[maxn], b[maxn];
int n;
void init()
{
     scanf("%d", &n);
     for (int i=0; i<n; i++)
     {
         scanf("%d%d", &a[i].first, &b[i].first);
         a[i].second = b[i].second = i;
     }
}
void work()
{
     sort(a, a+n); sort(b, b+n);
     static bool vis[maxn];
     int i, j;
     int ans = 0, now = 0;
     memset(vis, 0, sizeof(vis));
     for (i=0; i<n; i++)
     {
         for (j=0; j<n && now<b[i].first && a[j].first<=now; j++)
             if (!vis[a[j].second]) { vis[a[j].second] = true; now++; ans++; }
         if (now<b[i].first) break;
         ans++;
         now += vis[b[i].second] ? 1 : 2;
         vis[b[i].second] = true;
     }
     if (i<n) printf("Too Bad\n"); else printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        init();
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}
