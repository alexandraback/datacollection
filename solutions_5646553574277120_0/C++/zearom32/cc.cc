#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;


int C,D,V;

int a[100];
int b[40];
int c[40];
int d[100];
int ans = 0;
int cur;
int valid()
{
    vector<int> tmp(b,b+40);
    for (int i = 1; i <= cur; i++){
        for (int j = V; j >= d[i]; j--){
            tmp[j] = tmp[j] | tmp[j-d[i]];
        }
    }
    int flag = 2;
    for (int i = 1; i <= V; i++)
    {
        if (!tmp[i]) {flag = 0; break;}
    }
    
    if (flag) ans = cur;
    return flag;
}

void dfs(int t,int u = 0)
{
    if (ans) return;
    if (t == 0){
        valid();
        return;
    }else
    {
        for (int i = u + 1; i <= V;i ++)
        {
            if (!c[i]){
                d[t] = i;
                dfs(t-1,i);
            }
        }
    }
}
void doit(int t)
{
    cur=t;
   dfs(t); 
}

void solve()
{
    ans = 0;
    memset(c,0,sizeof(c));
    memset(b,0,sizeof(b));
    cin >> C>>D>>V;
    for (int i =  0; i < D; i++)
        cin >> a[i];
    b[0] = 1;
   for (int i = 0; i < D; i++)
   {
       c[a[i]] = 1;
       for (int j = V; j >= a[i]; j--)
       {
           b[j] = b[j] | b[j-a[i]];
       }
   } 
   cur = 0;
   if (valid())
   {
       cout << 0 << endl;
       return;
   }
   for (int i = 1; i <= V; i++)
   {
       doit(i);
       if (ans)
       {
           cout << ans <<endl;
           return;
       }
   }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #"<<i<<": ";
        solve();
    }
    return 0;
}
