#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <map>

using namespace std;

long long rv(long long n) {
    long long a = 0;
    while(n > 0) {
        a = a * 10 + (n % 10);
        n/=10;
    }
    return a;
}

int len(long long n) {
    int c = 0;
    while(n > 0) {
        c++;
        n/=10;
    }
    return c;
}
void solve(int t) {
    long long n; cin>>n;
    if(n < 10) {
        printf("Case #%d: %lld\n",t,n);
        return;
    }
    long long ans = 1;
    while(n > 1) {

        long long r = rv(n);
        int l = len(n);
        long long h = pow(10,l/2);
        if(r == 1) {
            n--;
            ans++;
        }
        else if(r % h == 1) {
            ans+=(n - pow(10,l - 1) + 1);
            n = pow(10,l - 1)  - 1;
        }
        else if(n % h == 0) {
            ans+=h - 1;
            n-=h - 1;
            if(rv(n) < n) {
                ans++;
                n = rv(n);
            }
        }
        else {
            ans+=(n % h);
            n-=(n % h) - 1;
            n = rv(n);
        }
        if(n < 10) {
            ans+=n - 1;
            break;
        }
    }
    printf("Case #%d: %lld\n",t,ans);
}

int main() {
    freopen("/Users/administrator/Desktop/A-large.in","r",stdin);
    freopen("/Users/administrator/Desktop/gcjoutpu1.txt","w",stdout);
    int t; cin>>t;
    for(int i = 1;i <= t;i++) {
        solve(i);
    }
    
}