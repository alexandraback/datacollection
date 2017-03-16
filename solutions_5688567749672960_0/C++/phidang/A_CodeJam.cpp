#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define openfile {freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);}
#define debug 01

long long n, t;

void solve() {
    long long res = 0;
    int l=0;
    if (n==1) {
        cout<<n<<endl;
        return;
    }
    long long m=n;
    while (m>0) {
        l++;
        m/=10;
    }
    while (n>1) {
        if (n%10 == 0) {
            res++;
            n--;
            m=n;
            l=0;
            while (m>0) {
                l++;
                m/=10;
            }
        }
        m=n;
        long long e=1;
        for (int i=0; i<(l+1)/2; i++) {
            e*=10;
        }
        res+=m%e-1;
        m/=e;
        long long c=0;
        while (m>0) {
            c=c*10+m%10;
            m/=10;
        }
        if (c==1) {
            res++;
        }
        else res+=c+1;
        e=1;
        for (int i=0;i<l-1; i++) {
            e*=10;
        }
        if (n<e) n=e/10;
        else n=e;
        l--;
    }
    cout<<res<<endl;
}

int main()
{
    if (debug) openfile;
    cin>>t;
    for (int x=0; x<t; x++) {
        cin>>n;
        printf("Case #%d: ", x+1);
        solve();
    }
    return 0;
}
