#include <iostream>
#include <cstdio>
using namespace std;
int mar[20000],gd,t,x;
void output(int t, long long x) {
    if (x>0)
    cout << "Case #" << t << ": " << x << "\n";
    else
    cout << "Case #" << t << ": INSOMNIA\n";
}
void chck(long long x) {
    if (x==0) {
        if (mar[x]==0) {
            gd++;
            mar[x]=1;
        }
        return;
    }
    while (x!=0) {
        if (mar[x%10]==0) {
            gd++;
            mar[x%10]=1;
        }
        x=x/10;
    }
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int tt=1;tt<=t;tt++) {
        cin >> x;
        gd=0;
        long long ans=0;
        for (int i=0;i<=9;i++) mar[i]=0;
        for (int i=1;i<=100000;i++) {
            chck(1ll*i*x);
            if (gd==10) {
                ans=1ll*i*x;
                break;
            }
        }
        if (gd!=10) output(tt,-1);
        else output(tt,ans);
    }
    return 0;
}
