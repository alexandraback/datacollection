#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
struct node{
    string a;
    string b;
}s[1010];
int suma[1010], sumb[1010], c[1010];
bool a[1010][1010];
int n1 = 0, m1 = 0;
bool vis[1111];
bool find(int x)
{
    for (int i = 1; i <= m1; i++)
        if (a[x][i] && !vis[i])
        {
            vis[i] = true;
            if (c[i] == 0 || find(c[i]))
            {
                c[i] = x;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int sum = 0;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n1; i++)
    {
        memset(vis, false, sizeof(vis));
        if (find(i)) sum++;
    }
    return sum;
}
int main()
{
    freopen("C-small-attempt1.in.txt", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int t, Case = 0;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        map<string, int> ma;
        ma.clear();
        map<string, int> mb;
        mb.clear();
        memset(suma, 0, sizeof(suma));
        memset(sumb, 0, sizeof(sumb));
        int ida = 1, idb = 1;
        for (int i = 0; i < n; i++)
        {
            cin>>s[i].a>>s[i].b;
            if (ma.find(s[i].a) == ma.end())
            {
                ma[s[i].a] = ida;
                suma[ida] = 1;
                ida++;
            }
            else{
                suma[ma[s[i].a]]++;
            }
            if (mb.find(s[i].b) == mb.end())
            {
                mb[s[i].b] = idb;
                sumb[idb] = 1;
                idb++;
            }
            else{
                sumb[mb[s[i].b]]++;
            }
            
        }
        
        
        n1 = ida;
        m1 = idb;
        memset(a, false, sizeof(a));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
           if (suma[ma[s[i].a]] == 1 || sumb[mb[s[i].b]] == 1)
           {
               ans++;
               continue;
           }
            a[ma[s[i].a]][mb[s[i].b]] = true;
        }
        ans += hungary();
        ans = n - ans;
        
        int ans1 = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (suma[ma[s[i].a]] > 1)
            {
                if (sumb[mb[s[i].b]] > 1)
                {
                    ans1++;
                    suma[ma[s[i].a]]--;
                    sumb[mb[s[i].b]]--;
                }
            }
        }
        
        printf("Case #%d: %d\n", ++Case, max(ans1, ans));
    }
    
    
}