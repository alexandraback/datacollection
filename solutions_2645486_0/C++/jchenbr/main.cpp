#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long LL;
const int N=10+5;
LL f[N][N];
LL e, r, n, a[N];

int main() {
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int total,tt=0;
    cin>>total;
    while (total--){
        cin>>e>>r>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        memset(f, 0, sizeof (f));
        LL tmp,ans=0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= e; j++) 
                for (int k = 0; k <= j; k++) {
                    tmp = j - k + r;
                    if (tmp > e) tmp = e;
                    f[i + 1][tmp] = max(f[i + 1][tmp], f[i][j] + k * a[i + 1]);
                }
        for (int i = 0; i <= e; i++) {
            ans = max(ans, f[n][i]);
        }
        cout<<"Case #"<<++tt<<": "<<ans<<endl;
    }
    return 0;
}
