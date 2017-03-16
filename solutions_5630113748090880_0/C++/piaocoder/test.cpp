#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int cnt[3000];

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t = 1;
    scanf("%d",&T);
    while(T--){
        memset(cnt,0,sizeof(cnt));
        int x,n;
        scanf("%d",&n);
        int len = 2*n-1;
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < n; ++j){
                scanf("%d",&x);
                ++cnt[x];
            }
        }
        printf("Case #%d:",t++);
        for(int i = 1; i <= 2500; ++i){
            if(cnt[i]&1)
                printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}
