#include<bits/stdc++.h>
using namespace std;
long long v[1010100];
long long s1[1010100],N,M;

int ok = 0;
set<int> S;
void make(int x) {
    while(x) {
        int d = x % 10;
        x=x/10;
        S.insert(d);
    }
}
int main() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        long long aux = tt;
        cin >> aux;
        S.clear();
        if(aux == 0) {
            printf("Case #%d: INSOMNIA\n",tt,N);
            continue;
        }
        long long N = 0;
        while(S.size() < 10) {
            N += aux;
            make(N);
        }
        printf("Case #%d: %lld\n",tt,N);
    }
}
