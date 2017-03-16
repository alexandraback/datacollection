#include <iostream>
using namespace std;

int a[101];

int main() {
    int t,n,s,p;
    cin>>t;

    for(int tc=1; tc<=t; ++tc) {
        cin>>n>>s>>p;
        for(int i=0; i<n; ++i) cin>>a[i];

        if(p == 0) {
            cout<<"Case #"<<tc<<": "<<n<<endl;
            continue;
        }else if(p == 1) {
            int ans = 0;
            for(int i=0; i<n; ++i)
                if(a[i] > 0) ans++;
            cout<<"Case #"<<tc<<": "<<ans<<endl;
            continue;
        }

        int ok = 0, maybe = 0;
        for(int i=0; i<n; ++i) {
            if(a[i] >= 3*p-2) ok++;
            else if(a[i] >= 3*p-4) maybe++;
        }

        ok += min(maybe, s);

        cout<<"Case #"<<tc<<": "<<ok<<endl;
    }
}
