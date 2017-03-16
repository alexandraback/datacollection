#include<stdio.h>
int re[3000000];
main(){
    freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
    int t;
    int set[501];
    scanf("%d",&t);
    for(int p=1;p<=t;p++){
        
        int n;
        scanf("%d",&n);
        for(int i=0;i<(n+1)*100001;i++){
            re[i]=-1;
            }
        
        for(int i=0;i<n;i++){
            scanf("%d",&set[i]);
            }
        int ok=0;
        int x,y;
        //printf("ok");
        for(int i=0;i<(1<<(n));i++){
            int tmpsum=0;
            for(int j=0;j<=n;j++){
                if((1<<j)&i){
                    tmpsum+=set[j];
                    }
                }
            if(re[tmpsum]==-1){
                re[tmpsum]=i;
                }
            else{
                ok=1;
                x=re[tmpsum];
                y=i;
                }
            }
        printf("Case #%d:\n",p);
        if(ok==0){
            printf("Impossible\n");
            }
        else{
            for(int i=0;i<n;i++){
                if(1<<i&x){
                    printf("%d ",set[i]);
                    }
                }
            printf("\n");
            for(int i=0;i<n;i++){
                if(1<<i&y){
                    printf("%d ",set[i]);
                    }
                }
            printf("\n");
            }
        }
    }
