#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool f[35];

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int z=1; z<=t; z++){
        cout<<"Case #"<<z<<": ";
        int c,d,v;
        cin>>c>>d>>v;
        memset(f,0,sizeof(f));
        f[0] = 1;
        while(d-->0) {
            int x;
            cin>>x;
            for(int i=v; i>=x; i--) {
                f[i] |= f[i - x];
            }
        }
        int res = 0;
        for(int j=1; j<=v; j++) {
            if(!f[j]) {
                res++;
                for(int i=v; i>=j; i--) {
                    f[i] |= f[i-j];
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}