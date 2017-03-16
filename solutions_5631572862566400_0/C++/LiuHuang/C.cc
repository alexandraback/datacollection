/* ***********************************************
Author        :oilover
Created Time  :2016/4/16 9:21:01
File Name     :
************************************************ */

#include <bits/stdc++.h>
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
void read(int &re) { scanf("%d", &re); }
using namespace std;
int n; int a[1777], b[1223];
int main()
{
    int re,ca=1; cin>>re;
    while (re--) {
        cin>>n;
        for (int i=0;i<n;i++) cin>>a[i], a[i]--;
        int ans = 1;
        for (int s=0;s<(1<<n);s++) {
            int m = 0;
            for (int i=0;i<n;i++) if(s>>i&1) b[m++] = i;
            if (m <= ans) continue;
            do {
                bool ok = true;
              //  for (int i=0;i<m;i++) printf("%4d", b[i]); cout<<endl;
                for (int i=0;i<m;i++)
                {
                    int x = a[b[i]];
                    if (!(b[(i+m-1)%m]==x || b[(i+1)%m]==x))
                       {
                           ok = false;
                           break;
                       }
                }
                if (ok) { ans=max(ans,m); break; }

            } while (next_permutation(b,b+m));
           // cout<<endl;
        }
        printf("Case #%d: ", ca++);
        cout<<ans<<endl;
    }
}
