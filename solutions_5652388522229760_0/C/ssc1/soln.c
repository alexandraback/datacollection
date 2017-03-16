#include <stdio.h>
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,ans=0,d=0;scanf("%d",&a);long c=a;
        if(a==0){printf("Case #%d: INSOMNIA\n",i);continue;}
        int b[]={0,0,0,0,0,0,0,0,0,0};
        while(d<10){
            long tp=c;
            while(tp>0){
                int tp1=tp%10;
                if(b[tp1]==0){++d;b[tp1]=1;}
                tp/=10;
            }
            c+=a;
        }
        printf("Case #%d: %ld\n",i,c-a);
    }
}