#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int T,N,x,a[1010],nr;

int main() {
    freopen("input.in","r",stdin);
    freopen("outputB","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        scanf("%d",&N);
        nr = 0;
        int ma = 0;
        for(int i=1;i<=N;++i) {
            scanf("%d",&a[i]);
            ma = max(a[i],ma);
        }
        x = ma;
        for(int k=1;k<=ma;++k) {
            int S = 0;
            for(int i=1;i<=N;++i) {
                S += (a[i]-1)/k;
            }
            x = min(x,S+k);
        }
        printf("Case #%d: %d\n",t,x);
    }
    return 0;
}
