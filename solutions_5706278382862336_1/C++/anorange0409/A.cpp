#include <iostream>
#include <cstdio>

using namespace std;

long long gcd(long long a, long long b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}


int get(long long p, long long q){
    if (p == q) return 1;
    int ans = -1; bool OK = false;
    for (int i = 0; i < 40; i++){
        p *= 2;
        long long d = gcd(p, q);
        p /= d; q /= d;
        if (p >= q && ans == -1) {ans = i + 1;}
        while (p >= q) p -= q;
        if (p == 0) { OK = true; break;}
    }
    if (!OK) return -1;
    else return ans;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++){
        long long p, q;
        scanf("%I64d/%I64d", &p, &q);
        int ans = get(p, q);
        printf("Case #%d: ", o);
        if (ans == -1) printf("impossible\n");
        else cout << ans << endl;
    }
}
