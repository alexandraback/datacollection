#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[20000],n,kk,ans,t,x;
string s;
void output(int t) {
    cout << "Case #" << t << ":\n";
}
int main() {
  //  freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int tt=1;tt<=t;tt++) {
        cin >> n >> kk;
        int m=n-2;
        int v=0;
        output(tt);
        for (int i=0;i<(1 << m);i++) {
            int kl=0;
            for (int t=2;t<=10;t++) {
                int gd=0;
                int del=0;
                for (int d=2;d<=1000;d++) {
                    int ans=1;
                    for (int j=2;j<=n-1;j++) {
                        int k=j-2;
                        int bt=(i & (1 << k));
                        if (bt!=0) ans=(ans*t+1)%d;
                        else ans=(ans*t)%d;
                    }
                    ans=(ans*t+1)%d;
                    if (ans==0) {
                        gd=1;
                        del=d;
                        break;
                    }
                }
                if (gd==1) {
                    kl++;
                    a[kl]=del;
                }
            }
            if (kl==9) {
                cout << "1";
                for (int j=2;j<=n-1;j++) {
                    int k=j-2;
                    int bt=(i & (1 << k));
                    if (bt!=0) cout << "1";
                    else cout << "0";
                }
                cout << "1 ";
                for (int i=1;i<=9;i++) cout << a[i] << " ";
                cout << "\n";
                v++;
            }
            if (v==kk) break;
        }
    }
    return 0;
}
