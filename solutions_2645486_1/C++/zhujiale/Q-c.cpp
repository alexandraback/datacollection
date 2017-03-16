#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

int T,t;
unsigned long long E,r,n,a[10100],f[10100];

unsigned long long max(unsigned long long a, unsigned long long b)
{
    if (a>b) return a;
    return b;
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("C.out","w",stdout);
    cin>>T;
    while (t<T){
        unsigned long long ans = 0;
        t++;
        cin>>E>>r>>n;
        if (r>E) r = E;
        unsigned long long e = E;
        for (int i = 1; i<=n; i++) cin>>a[i];
        memset(f,0,sizeof(f));
        /*
        if (t==96) {
            cout<<E<<" "<<r<<" "<<n<<endl;
            for (int i = 1; i<=n; i++) cout<<a[i]<<" ";
        }
        */
        for (int i = n; i>=1; i--){
            f[i] = max(f[i+1],a[i]);
        }
        for (int i = 1; i<=n; i++){
            if (f[i]==a[i]){
                ans += a[i]*e;
                e = 0;
            }
            else if (e==E){
                ans += a[i]*r;
                e-=r;
            }
            else {
                ans += max(e+r-E,0)*a[i];
                e-=max(e+r-E,0);
            }
            e+=r;
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
