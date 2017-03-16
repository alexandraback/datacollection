#include<stdio.h>
#include<iostream>
using namespace std;
int T;
long long N, ten[20], rez, curr;

long long rev(long long x) {
    long long y = x;
    long long z = 0;
    while(y) {
        z = z*10 + y%10;
        y = y/10;
    }
    return z;
}

int digits(long long x) {
    int rez = 0;
    long long y = x;
    while(y) {
        y = y/10;
        ++rez;
    }
    return rez;   
}

int main() {
    freopen("input.in","r",stdin);
    freopen("bigA.out","w",stdout);
    ten[0] = 1;
    for(int i=1;i<=14;++i) {
        ten[i] = ten[i-1]*10;
    }
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d: ",t);
        scanf("%lld",&N);
        rez = 0, curr = N;
        while(curr>1) {
            int d = digits(curr);
            long long x = ten[d/2]; 
            long long y = (curr + x - 1 )% x;// + x - 1;
            curr -= y;
            rez += y;
            y = rev(curr);
            if(curr == y && curr>1) {
                curr -= x;
                rez += x;
            }
            y = rev(curr);
            if(curr > y) {
                curr = y;
                ++rez;
            } 
//            cout<<curr<<" ";
        }
        printf("%lld\n",rez+1);
    }
    return 0;
}
