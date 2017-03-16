#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int a[55][55];

int ans[60][60];
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t = 0;
    scanf("%d",&T);
    while(T--){
        ll n,m;
        scanf("%lld%lld",&n,&m);
        printf("Case #%d: ",++t);
        if(m > (1LL<<(n-2))){
            puts("IMPOSSIBLE");
            continue;
        }
        puts("POSSIBLE");
        if(n == 2){
            puts("01");
            puts("00");
            continue;
        }
        for(int i = 1; i < n; ++i)
            for(int j = i+1; j < n; ++j)
                ans[i][j] = 1;
        ll all = (1LL<<(n-2));
        int now = 1;
        ll tmp = all>>1;
        while(m){
            while(tmp > m)
                tmp >>= 1,++now;
            m -= tmp;
            ans[0][now] = 1;
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                printf("%d%s",ans[i][j],j==n-1?"\n":" ");
            }
        }
    }
    return 0;
}
