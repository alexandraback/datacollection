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

int tst,tstt;

int n,x,y,l,d,a,i,j,L,R;
int A;
double ans;
double dp[100][100];

int main()
{
    freopen("b1.dat","r",stdin);
    freopen("b1.sol","w",stdout);
    cin >> tstt;
    cout << fixed << setprecision(15);
    for (tst=1;tst<=tstt;tst++){
        printf("Case #%d: ",tst);
        
        cin >> n >> x >> y;
        if (x<0) x = -x;
        a = 0;
        d = 1;
        l = -2;
        A = -1;
        while (a+d<=n){
              l+=2;
              a += d;
              d += 4;
              if (x+y<=l) A = 1;
        }
        if (A>0) cout << 1.0 << endl; else
        if (x+y>l+2) cout << 0.0 << endl; else
        {
                   memset(dp,0,sizeof(dp));
                   dp[0][d+1] = 1;
                   n -= a;
                   for (i=1;i<=n;i++)
                       for (j=0;j<=i-1;j++)
                           if (j<=d/2){
                           L = j;
                           R = d+1-(i-1-j);
                           if (L==d/2){
                              dp[L][R-1] += dp[L][R];
                              continue;
                           }
                           if (R == d/2+2){
                              dp[L+1][R] += dp[L][R];
                              continue;
                           }
                           
                           dp[L+1][R] += dp[L][R]*0.5;
                           dp[L][R-1] += dp[L][R]*0.5;                           
                       }
                   ans = 0;
                   for (j=y+1;j<=n;j++)
                       ans = ans+dp[j][d+1-(n-j)];
                   cout << ans << endl;
        }
    }
    //system("pause");
    return 0;
}
