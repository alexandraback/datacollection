#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int ttt, t;

int n,m,i,j,h,ok;
int a[111][111], b[111][111];

int main()
{
    freopen("b2.in","r",stdin);
    freopen("b2.out","w",stdout);    
    cin >> t;
    for (ttt = 1; ttt <= t; ttt++){
        printf("Case #%d: ",ttt);
        
        cin >> n >> m;
        memset(b,0,sizeof(b));
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                cin >> a[i][j];
                
        for (h=100;h>=1;h--){
            for (i=1;i<=n;i++){
                ok = 1;                
                for (j=1;j<=m;j++)
                    if (a[i][j]>h) ok = 0;
                    
                if (ok)
                   for (j=1;j<=m;j++)
                       if (a[i][j] == h) b[i][j] = 1;
           }

            for (j=1;j<=m;j++){
                ok = 1;                
                for (i=1;i<=n;i++)
                    if (a[i][j]>h) ok = 0;
                    
                if (ok)
                   for (i=1;i<=n;i++)
                       if (a[i][j] == h) b[i][j] = 1;
           }           
        }
        ok = 1;
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                if (b[i][j] == 0)  ok = 0;
        if (ok) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
