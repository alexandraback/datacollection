#include <bits/stdc++.h>
#define ll long long
#define MAX_VAL 10000000
using namespace std;

int t;
ll n;
int f[MAX_VAL];

int reverse(int k) {
    string s="";
    while (k>0) {
        s+=(char)((k % 10)+'0');
        k/=10;
    }
    int ret=0, p=1;
    for (int i=s.length()-1; i>=0; i--) {
        ret+=p*(s[i]-'0');
        p*=10;
    }
    return ret;
}

int main(void) {
    if (fopen("a.in","r")) {
        freopen("a.in","r",stdin);
        freopen("a.out","w",stdout);
    }
    for (int i=0; i<MAX_VAL; i++) f[i]=1 << 26;
    f[0]=0;
    for (int i=0; i<MAX_VAL-1; i++) {
        int k=reverse(i);
        if (k!=i) {
            f[k]=min(f[k],f[i]+1);
        }
        f[i+1]=min(f[i]+1,f[i+1]);
    }
    cin >> t;
    for (int ii=1; ii<=t; ii++) {
        cin >> n;
        cout << "Case #" << ii << ": " << f[n] << "\n";
    }
    return 0;
}
