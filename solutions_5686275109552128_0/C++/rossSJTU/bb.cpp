#include<stdio.h>
int P[1005];
int main ()
{
    int T,D;
    scanf("%d",&T);
    for(int _=1;_<=T;_++){
        scanf("%d",&D);
        for(int i =0;i<D;i++){
            scanf("%d",&P[i]);
        }
        int mx = 0;
        for(int i =0;i<D;i++){
            if(P[i]>mx) mx = P[i];
        }
        int ans = mx;
        for(int i =1;i<=mx;i++){
            int tmp = i;
            for(int j = 0;j<D;j++){
                tmp+=(P[j]-1)/i;
            }
            if(tmp<ans) {
                ans = tmp;
            }
        }
        printf("Case #%d: %d\n",_,ans);

    }
    return 0;
}