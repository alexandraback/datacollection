#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

ll modulo(ll a,ll b,ll c){
    long long x=1,y=a; // long long is taken to avoid overflow of llermediate results
    while(b > 0){
        if(b%2 == 1){
            x=mulmod(x,y,c);
        }
        y = mulmod(y,y,c); // squaring the base
        b /= 2;
    }
    return x%c;
}

bool Miller(long long p,ll iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(ll i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("C.out", "w", stdout);
    int bound = 1<<16;
    int cnt = 0;
    vector<int> ds;
    for (int i = (1<<15)+1; i < bound; i += 2) {
        int now = i;
        bool ok = true;
        for (int base = 2; base <= 10; base++) {
            ll so = 0;
            for (int j = 15; j >= 0; j--) {
                so = so * base;
                if ((now >> j) & 1) so++;
            }
            if (Miller(so,30)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ds.push_back(i);
            if (ds.size() == 50) {
                break;
            }
        }
    }

    cout << "Case #1:\n";
    for (int i = 0; i < ds.size(); i++) {
        bitset<16> tmp = bitset<16>(ds[i]);
        cout << tmp << ' ';
        for (int base = 2; base <= 10; base++) {
            ll so = 0;
            for (int j = 15; j >= 0; j--)
                so = so * base + tmp[j];
            for (ll j = 2; j <= sqrt(so); j++)
            if (so % j == 0) {
                cout << j << ' ';
                break;
            }
        }
        cout << '\n';
    }

    return 0;
}
