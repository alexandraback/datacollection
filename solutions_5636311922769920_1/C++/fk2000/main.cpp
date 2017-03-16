#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[20000],n,k,m,ans,t,x;
string s;
void output(int t) {
    cout << "Case #" << t << ": ";
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int tt=1;tt<=t;tt++) {
        cin >> n >> m >> k;
        output(tt);
        if (k==n) {
            for (int i=1;i<=n;i++) cout << i << " ";
            cout << "\n";
        }
        else {
            if (m==1 && k<n) cout << "IMPOSSIBLE\n";
            else {
                long long l=0;
                long long ans=1;
                for (int i=1;i<=m-1;i++) ans=ans*n;
                if (k<n/2+n%2) cout << "IMPOSSIBLE\n";
                else {
                    for (int i=2;i<=n;i+=2) cout << ans*(i/2-1)+i << " ";
                    if (n%2==1) cout << n << "\n";
                    else cout  << "\n";
                }
            }
        }
    }
    return 0;
}
