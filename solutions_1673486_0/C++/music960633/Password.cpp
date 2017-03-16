#include<stdio.h>
main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T,a,b,i,c;
    double p[100001],ans1,ans2,ans3,mul,tmp,ans;
    scanf("%d",&T);
    for(c=1;c<=T;c++){
        scanf("%d %d",&a,&b);
        for(i=0;i<a;i++) scanf("%lf",&p[i]);
        mul=1.0;
        for(i=0;i<a;i++) mul*=p[i];
        ans1=mul*(b-a+1)+(1-mul)*(2*b-a+2);
        ans=10000000.0;
        mul=1.0;
        for(i=1;i<=a;i++){
            mul*=p[i-1];
            tmp=mul*(a+b-2*i+1)+(1-mul)*(a+2*b-2*i+2);
            if(tmp<ans) ans=tmp;
        }
        ans3=(double)(b+2);
        if(ans1<ans) ans=ans1;
        if(ans3<ans) ans=ans3;
        printf("Case #%d: %lf\n",c,ans);
    }
}
        
