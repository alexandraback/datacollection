/* ***********************************************
Author        :oilover
Created Time  :2016/4/9 8:29:42
File Name     :
************************************************ */

#include <bits/stdc++.h>
#define prt(k) cerr<<#k" = "<<k<<endl
typedef long long LL;
void read(int &re) { scanf("%d", &re); }
using namespace std;
int N, J, cnt;
vector<int> f(int n)
{

    vector<int> ret();
}
int prime(LL n)
{
    for (LL i=2;i<=sqrt(n+0.5);i++) if (n%i==0) return i;
    return -1;
}
int ans[22];int bit[55];
int main()
{
    int re = 1, ca = 1;
    freopen("small.out", "w", stdout);
    while (re--) {
        N = 16; J = 50;
      //  N = 5 ; J = 3;
        printf("Case #%d: ", ca++);
        cnt = 0;
        for (int i=0;i<(1<<N-2);i++) {
            LL n = i;
            n = 2*n+ 1 + (1<<N-1);
            for (int j=0;j<N;j++) bit[j] = n >> j & 1;
            bool ok = true;
            for (int B=2;B<=10;B++) {
                LL s = 0;
                for (int k=N-1;k>=0;k--)
                    s = (s * B + bit[k]);
                ans[B] = prime(s);
                if (ans[B] == -1)
                {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int j=N-1;j>=0;j--) printf("%d", bit[j]);
                for (int j=2;j<=10;j++) printf(" %d", ans[j]);
                cout<<endl;
                if (++cnt == J) break;
            }
        }
    }
}
