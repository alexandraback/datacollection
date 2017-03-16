#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long s,gen,res,a[200];
int n,cas;
int main() {
freopen("input","r",stdin);
freopen("output","w",stdout);
    cin>>cas;
    for (int c=1;c<=cas;++c) {
        cout<<"Case #"<<c<<": ";
        cin>>s>>n;
        for (int i=0;i<n;++i) cin>>a[i];
        if (s==1) {
            cout<<n<<endl;
            continue;
        }
        sort(a,a+n);
        res = n;
        gen = 0;
        for (int i=0;i<n;++i) {
            while (s<=a[i]) {
                s+=(s-1);
                gen++;
            }
            s+=a[i];
            res = min(res, gen+n-i-1);
        }
        cout<<res<<endl;
    }
    return 0;
}



