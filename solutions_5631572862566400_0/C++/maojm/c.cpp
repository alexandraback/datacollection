#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<ctime>

using namespace std;

int a[2000];
int b[2000];
int c[2000];
int d[2000];

int o;
int p;

int dfs(int x, int y, int z)
{
    b[y] = 1;
    if (b[a[y]] == 1 && a[y] != x) {o = z; p = a[y]; return -1;}
    if (a[y] == x) return z + 1;
    return dfs(x,a[y], z+1);
}

int main()
{
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  int t;
  cin >> t;
   

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            a[j] = x - 1;
        }
        int ans =0;
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        for (int j = 0; j < n; j++) d[j] = 1;
        for (int j = 0; j < n; j++)
        {
            memset(b,0,sizeof(b));
            int u = dfs(j,j,0);
            if (u > ans) ans = u;
            if (u == -1)
                if (o > d[p]) d[p] = o;
            c[j] = u;
        }
        int aa = 0;
        //for (int j =0 ; j < n; j++) cout << d[j] << " ";
        for (int j = 0; j < n; j++)
            if (a[a[j]] == j) aa += d[j] ;
        if (aa > ans) ans = aa;
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
      
}
