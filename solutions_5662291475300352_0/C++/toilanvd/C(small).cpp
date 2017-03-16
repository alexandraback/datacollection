#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll n;
ll a[500005], b[500005], s[500005];

int main(){
    freopen("C(small).in","r",stdin);
    freopen("C(ok).out","w",stdout);

    ll test; cin >> test;
    for(ll timer=1;timer<=test;timer++){
        cin >> n;
        for(ll i=1;i<=n;i++) cin >> a[i] >> b[i] >> s[i];
        if(n==1) cout << "Case #" << timer << ": 0" << "\n";
        else if(s[1]==s[2]) cout << "Case #" << timer << ": 0" << "\n";
        else{
            if(s[1]>s[2]){
                swap(s[1],s[2]); swap(a[1],a[2]); swap(b[1],b[2]);
            }
            ll alpha= 360-a[1], beta= 360-a[2];
            if(a[1]<=a[2]) alpha+= 360;
            if(alpha*s[1]<=beta*s[2]) cout << "Case #" << timer << ": 1" << "\n";
            else cout << "Case #" << timer << ": 0" << "\n";
        }
    }

    return 0;
}
