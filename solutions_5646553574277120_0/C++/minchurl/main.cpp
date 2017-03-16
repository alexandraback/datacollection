#include<stdio.h>
int test,n,c,d,v,t[350],dap;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tn,i,j,x;
    scanf("%d",&test);
    for(tn=1;tn<=test;tn++){
        printf("Case #%d: ",tn);
        scanf("%d %d %d",&c,&d,&v);
        t[0]=tn;
        dap=0;
        for(i=0;i<d;i++){
            scanf("%d",&x);
            for(j=v;j>=1;j--){
                if(j>=x && t[j-x]==tn)    t[j]=tn;
            }
        }
        for(i=1;i<=v;i++){
            if(t[i]==tn)    continue;
            for(j=v;j>=1;j--){
                if(j>=i && t[j-i]==tn)    t[j]=tn;
            }
            dap++;
        }
        printf("%d\n",dap);
    }
    return 0;
}
