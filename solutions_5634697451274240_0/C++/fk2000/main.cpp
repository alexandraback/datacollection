#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[20000],ans,t,x;
string s;
void output(int t, long long x) {
    cout << "Case #" << t << ": " << x << "\n";
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int tt=1;tt<=t;tt++) {
        cin >> s;
        int n=s.size();
        for (int i=1;i<=n;i++)
            if (s[i-1]=='+') a[i]=1;
            else a[i]=0;
        int ans=0,inv=1;
        for (int i=n;i>=1;i--) {
            if (a[i]==inv) continue;
            else {
                if (a[1]==inv) {
                    ans++;
                    inv=1-inv;
                }
                else {
                    ans++;
                    reverse(a+1,a+i+1);
                    for (int j=1;j<=i;j++) a[j]=1-a[j];
                }
            }
        }
        output(tt,ans);
    }
    return 0;
}
