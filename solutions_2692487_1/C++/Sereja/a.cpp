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

int n,A,i,ans,tmp;
int a[200];

int main()
{
    freopen("a2.dat","r",stdin);
    freopen("a2.sol","w",stdout);
    cin >> tstt;
    for (tst=1;tst<=tstt;tst++){
        cin >> A >> n;
        for (i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        
        if (A == 1) ans = n; else
        {        
            ans = n;
            
            tmp = 0;
            for (i=0;i<n;i++){
                if (tmp+n-i<ans) ans = tmp+n-i;
                while (a[i]>=A) {
                      A = A+A-1;
                      tmp++;
                }
                A = A+a[i];
                if (tmp+n-(i+1)<ans) ans = tmp+n-(i+1);
            }
        }
        
        printf("Case #%d: ",tst);
        cout << ans << endl;
    }
    //system("pause");
    return 0;
}
