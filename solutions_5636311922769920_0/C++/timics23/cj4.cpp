#include<stdio.h>
#include<iostream>
#include<vector>
#define pb push_back

using namespace std;
vector<long long> a;
int T,k,s,c;

void make_guess() {
    long long ret = 1;
    long long curr = 1;
    for(int i=c-1;i>=0;--i) {
        ret += curr*(a[i]-1);
        curr *= k;
    }
    printf("%lld ",ret);
}

int main() {
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d: ",t);
        scanf("%d%d%d",&k,&c,&s);
        if((k+c-1)/c > s) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        int x = k/c;
        for(int i=0;i<x;++i) {
            a.clear();
            for(int j=1;j<=c;++j) {
                a.pb(i*c + j);
            }
            make_guess();
        }
        if(k%c != 0) {
            a.clear();
            for(int i=1;i<=k%c;++i) {
                a.pb(x*c+i);
            }
            for(int i=k%c+1;i<=c;++i) {
                a.pb(1);
            }
            make_guess();
        }
        printf("\n");
    }
}
