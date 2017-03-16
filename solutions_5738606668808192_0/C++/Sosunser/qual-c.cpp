#include <bits/stdc++.h>
using namespace std;

int res = 0;
string a = "1000000000000001";
long long x[11];

void solve(){
    if(res == 50) return;
    for(long long base = 2; base <= 10; base++){
        long long n = stoll(a,0,base);
        if(n == 2) return;
        x[base] = 0;
        for(long long i = 2; i <= sqrt(n); i++){
            if(n%i == 0){
                x[base] = i;
                break;
            }
        }
    }
    for(long long i = 2; i <= 10; i++) if(!x[i]) return;
    cout << a << " ";
    for(long long i = 2; i <= 9; i++){
        printf("%lld ",x[i]);
    }
    printf("%lld\n",x[10]);
    res++;
    return;
}

void gen(int i){
    if(i == 15){
        solve();
        return;
    }
    a[i] = '0';
    gen(i+1);
    a[i] = '1';
    gen(i+1);
    return;
}

int main(){
    freopen("C-small-attempt0.out","w",stdout);
    printf("Case #1:\n");
    gen(1);
}