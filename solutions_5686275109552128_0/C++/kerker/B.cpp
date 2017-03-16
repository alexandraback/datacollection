#include <stdio.h>
#include <stdlib.h>

int a[1003];

int main(){
    
    int T;
    scanf(" %d",&T);
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        int maxi = 0;
        for(int i=0;i<N;i++){
            scanf(" %d",&a[i]);
            if(a[i]>maxi)   maxi = a[i];
        }
        int ans = maxi;
        for(int left=1;left<=maxi;left++){
            int now = 0;
            for(int i=0;i<N;i++){
                int tmp = a[i]%left==0 ? a[i]/left : a[i]/left+1;
                now += (tmp-1);
            }
            now += left;
            if(now<ans) ans = now;
        }
        printf("Case #%d: %d\n",t+1,ans);
    }

    return 0;
}
