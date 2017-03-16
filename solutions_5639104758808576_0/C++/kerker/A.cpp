#include <stdio.h>
#include <stdlib.h>

int a[1003];

int main(){
    
    int T;
    scanf(" %d",&T);
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        for(int i=0;i<=N;i++)
            scanf(" %1d",&a[i]);
        int ans = 0, now=a[0];
        for(int i=1;i<=N;i++){
            if(a[i]>0 && now<i)   ans += (i-now), now = i;
            now += a[i];
        }
        printf("Case #%d: %d\n",t+1,ans);
    }

    return 0;
}
