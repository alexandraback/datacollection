#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j,k,t;
    long a,b;
    float c[100000],cal,prob,tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%ld%ld",&a,&b);
        for(j=0;j<a;j++)
            scanf("%f",&c[j]);
        prob=1;
        for(j=0;j<a;j++)
            prob*=c[j];
        cal=(b-a+1)*prob+(b+b-a+2)*(1-prob);
        tmp=2+b;
        if(cal>tmp)
            cal=tmp;
        prob=1;
        t=0;
        for(k=a-1;k>=1;k--){
            prob*=c[t];
            t++;
            tmp=(2*k+(b-a)+1)*prob+(2*k+(b-a)+2+b)*(1-prob);
            if(cal>tmp)
                cal=tmp;
        }
        printf("Case #%d: %f\n",i+1,cal);
    }
    return 0;
}
