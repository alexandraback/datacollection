#include<bits/stdc++.h>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
#define max(a,b) a>b?a:b
using namespace std;
const int N=1005;
vector < int > g[N];
int visited[N];
int de[N];
/*void dfs(int v, int pr) {
    visited[v]=1;
    if(pr!=-1)
        de[v]=de[pr]+1;
  int sz = g[v].size();
  for(int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr || visited[u]==1) {
      continue;
    }
    dfs(u, v);
  }
}*/
int solve()
{
   int n;
   cin >> n;
   int i;int a[1005];
   rep(i,0,n)
    g[i].clear();
   int foo;
   rep(i,0,n)
   {
       cin >> foo;
       foo--;
       a[i]=foo;
   }
    rep(i,0,n){
    visited[i]=0;de[i]=0;}
    int m=0;
    rep(i,0,n)
    {
        int c=1;
        while(true)
        {
            if(visited[a[i]]==0)
                c++;
            else
                break;
            visited[a[i]]=1;
        }
        rep(k,0,n)
        {
            visited[i]=0;
        }
        m=max(c,m);
    }
    return m;
   
}
int main()  
{
    int t;
    cin >> t;
    int j;
    for(j=0;j<t;j++)
    {
         cout << "Case #" << j+1 << ": " << solve() << "\n";
    }
    return 0;
    
}