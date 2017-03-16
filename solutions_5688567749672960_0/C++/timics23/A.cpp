#include<stdio.h>
#include<iostream>
using namespace std;
int N,T;
//long long N;
int d[1000100],q[1000100];

int rev(int x) {
    int y = x;
    int z = 0;
    while(y) {
        z = z*10 + y%10;
        y = y/10;
    }
    return z;
}
int main() {
    freopen("input.in","r",stdin);
    freopen("outA.out","w",stdout);
    for(int i=1;i<=1000000;++i) {
        d[i] = -1;
    }
    int first = 1, last = 1;
    q[first] = 1;
    d[1] = 1;
    while(first<=last) {
        int x = q[first];
        ++first;
        if(d[x+1]==-1 && x+1 <= 1000000 ) {
            d[x+1] = d[x] + 1;
            q[++last] = x+1;
        }
        int y = rev(x);
        if(d[y]==-1 && y <= 1000000 ) {
            d[y] = d[x] + 1;
            q[++last] = y;
        }
    }
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d: ",t);
        scanf("%d",&N);
        printf("%d\n",d[N]);
    }
    return 0;
}
