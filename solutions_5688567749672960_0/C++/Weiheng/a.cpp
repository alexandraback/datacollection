#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

long long solve(long long n) 
{
    long long tmp;
    tmp = n;
    int l = 0;
    while (tmp>0) {
        tmp/=10;
        l++;
    }
    l--;
    int i, j;
    long long ans = 0, ss;
    for (i=1, ss=10, tmp = 10; i<=l; i++) {
        if (i>2 && i%2==1) ss*=10;
        ans += (tmp-1)/ss + ss-1 + 1;
        tmp *= 10;
    }
    for (i=0, tmp = 1; i<l/2+1; i++) tmp*=10;
    long long high = 0;
    long long low = n%tmp;
    for (;i<=l;i++) {
        high = high*10 + (n/tmp)%10;
        tmp*=10;
    }
    if (low%10 == 0 && high!=1) {
        return solve(n-1)+1;
    } else {
        ans += low;
        ans += high;
        if (high!=1) ans++;
        ans--;
    }
    return ans;
}

int main() {
    int nc, tc;
    tc = 1;
    cin>>nc;
    while (tc<=nc) {
        cout<<"Case #"<<tc<<": ";
        long long n;
        cin>>n;
        cout<<solve(n)<<endl;
        tc++;
    }
    return 0;
}
