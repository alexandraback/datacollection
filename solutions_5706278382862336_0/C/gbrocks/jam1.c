#include<stdio.h>
long long solve(long long i,long long p,long long q){
    if(i>40)return 0;
    if(p==q)return i;
    p<<=1;
    if(p==q)return i;
    if(p>q){//printf("p: %lld q:%lld\n",p,q);
         long long x=solve(i+1,p-q,q);
         /*while(x==0 && i<40){
             x=solve(i+1,p,q);
         }*/
         if(x!=0){
             return i;
         }
         else return 0;
    }
    return solve(i+1,p,q);
} 
     
int main(){
    long long h,t;
    long long p,q;
    scanf("%lld",&t);
    getc(stdin);
    char c;
    for(h=1;h<=t;h++){
        c=getc(stdin);
        p=c-'0';
        c=getc(stdin);
        while(c!='/'){
            p*=10;
            p+=c-'0';
            c=getc(stdin);
        }
        c=getc(stdin);
        q=c-'0';
        c=getc(stdin);
        while(c!='\n'){
            q*=10;
            q+=c-'0';
            c=getc(stdin);
        }
        long long x=solve(1,p,q);
        if(x==0)printf("Case #%lld: impossible\n",h);
        else printf("Case #%lld: %lld\n",h,x);
    }
    return 0;
}
