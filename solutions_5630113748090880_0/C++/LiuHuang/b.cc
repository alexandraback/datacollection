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
int n; int a[7777];
int main()
{
    int re,ca=1; cin>>re;
    while (re--) {
        cin >> n;
        int c = 0;
        for (int i=0;i<2*n-1;i++)
            for (int j=0;j<n;j++)
        {
            int x; cin>>x;
            a[c++] = x;
        }
        sort(a, a+c);
        int b[333];
        int cnt = 0;
        for (int i=0;i<c;) {
            if (i<c-1 && a[i]==a[i+1])
                i+=2;
            else {
                b[cnt++] = a[i];
                i++;
            }
        }

        printf("Case #%d:", ca++);
        for (int i=0;i<n;i++) printf(" %d", b[i]);
        cout<<endl;
    }
    return 0;
}
