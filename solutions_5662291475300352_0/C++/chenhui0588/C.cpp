#include<bits/stdc++.h>
using namespace std;

int N;
int D[10],M[10];
void init(){
    int n,d,h,m;
    scanf("%d",&n);
    N = 0;
    while(n--){
        scanf("%d%d%d",&d,&h,&m);
        for(int i=0; i<h; ++i){
            D[N] = d;
            M[N] = m+i;
            N++;
        }
    }
}

int solve(){
    if(N<2) return 0;
    if(N>2) return 0;
    double minS = 1000000000.0;
    for(int i=0; i<N; ++i){
        minS = min(minS, (360.0+(double)D[i])/(double)M[i]);
    }
    double maxS = 0.0;
    for(int i=0; i<N; ++i){
        maxS = max(maxS, (360.0-(double)D[i])/(double)M[i]);
    }
    if(minS>maxS) return 1;
    return 0;
}
int main(){
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C-small-1-attempt0.out","w",stdout);
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
        init();
        int ans = solve();
        printf("Case #%d: %d\n",ca++,ans);
    }
    return 0;
}
