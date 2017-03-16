#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

int t,c,d,v,a;
bool coin[1000000010];

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    for(int j = 1; j <= t; j++){
        memset(coin,0,sizeof coin);
        int ans = 0;
        scanf("%d%d%d",&c,&d,&v);
        for(int i = 0; i < d; i++){
            scanf("%d",&a);
            for(int k = v; k >= 1; k--){
                if(coin[k]) coin[k+a] = 1;
            }
            for(int k = a, counter=0; counter < c; k += a){
                counter++;
                coin[k] = 1;
            }
        }
        for(int i = 1; i <= v; i++){
            if(!coin[i]){
                ans++;
                for(int k = v; k >= 1; k--){
                    if(coin[k]) coin[k+i] = 1;
                }
                for(int k = i, counter=0; counter < c; k += i){
                    counter++;
                    coin[k] = 1;
                }
            }
        }
        printf("Case #%d: %d\n",j,ans);
    }
}