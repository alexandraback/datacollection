#include<stdio.h>
int a,b;
int C(int x){
    return x*(x-1)/2;
    }
int di(int x){
    int sum=0;
    int p=x;
    while(p>0){
        sum++;
        p/=10;
        }
    return sum;
    }
int j(int x){
    int e=1;
    for(int i=1;i<x;i++){
        e*=10;
        }
    return e;
    }
int en(int x){
    return j(di(x));
    }
bool check(int x){
    if(x<=b&&x>=a){
        return true;
        }
    else{
        return false;
        }
    }
int re[2000005];
main(){
    freopen("pC.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++){
        printf("Case #%d: ",k+1);
    int ans=0;
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;i++){
        re[i]=0;
        }
    for(int i=a;i<=b;i++){
        if(re[i]==1||i<10){
            continue;
            }
        int e=i;
        re[e]=1;
        int d=0;
        while(1){
          //  printf("%d \n",e);
            int q=e%10;
            e=e/10;
            e=e+q*j(di(i));
            if(di(e)!=di(i)){
                continue;
                }
            if(check(e)){
                re[e]=1;
                d++;
                }
            if(e==i){break;}
            }
        ans+=C(d);
        }
    printf("%d\n",ans);
    }
}
    
    
    
    
    
