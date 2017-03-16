#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long p, q;

long long gcd(long long p, long long q) {
    return q == 0 ? p : gcd(q, p % q);
}

int main() {
    freopen("A0.in", "r", stdin);
    freopen("A0.out", "w", stdout);
    int T;
    char s;
    cin>>T;
    for (int ca = 1; ca <= T; ca ++ ) {
        cin>>p>>s>>q;
        long long d = gcd(p, q);
        p /= d;
        q /= d;
        long long qq = q;
        while (!(qq & 1)) qq /= 2;
        if (qq != 1) {
            cout<<"Case #"<<ca<<": impossible"<<endl;
            continue;
        }
        int cnt = 0;
        while (p < q) {
            p *= 2;
            cnt ++ ;
        }
        if (cnt > 40) {
            cout<<"Case #"<<ca<<": impossible"<<endl;
            continue;
        }
        else
            cout<<"Case #"<<ca<<": "<<cnt<<endl;
    }
    return 0;
}
