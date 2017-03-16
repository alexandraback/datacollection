/* ***********************************************
Author        :oilover
Created Time  :2016/4/9 8:29:42
File Name     :
************************************************ */

#include <bits/stdc++.h>
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
void read(int &re) { scanf("%d", &re); }
using namespace std;
int n;
bool has(int n, int k)
{
    while (n > 0) {
        if (n%10 == k) return true;
        n /= 10;
    }
    return false;
}
int main()
{
    int re, ca=1; cin>>re;
    while (re--) {
        read(n);
        printf("Case #%d: ", ca++);
        if (n == 0) { puts("INSOMNIA");continue; }
        int ans = n;
        for (int k=0;k<10;k++)
        {
            int i;
            for (i=n;!has(i,k) && i/n<=123;i+=n) ;
            assert (has(i,k));
            ans = max(ans, i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
