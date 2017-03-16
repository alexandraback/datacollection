#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ulong;

int p[10] = {1, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};

int shift(int u, int k){
    int l = log(float(u))/log(float(10));
    ulong rem = u%p[k];
    u = u/p[k];
    u = u+rem*p[l-k+1];
    return u;
}

int A, B;

ulong solve(int n){
    ulong s=0;
    int k=1;
    while(true){
        int sh = shift(n, k);
        if(sh == n) return s;
        if(sh > n && B >= sh) s++;
        k++;
    }
}


int main(){
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        ulong sum=0;
        cout << "Case #" << t << ": ";
        cin >> A >> B;
        for(int i=A; i<B; i++){
            sum += solve(i);
        }
        cout << sum << '\n';
    }
    return 0;
}
