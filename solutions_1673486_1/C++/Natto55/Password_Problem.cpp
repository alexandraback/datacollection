#include<stdio.h>
#include<stdlib.h>
int main(){
    int t,a,b;
    scanf("%d",&t);
    for(int k=0;k<t;k++){
        scanf("%d %d",&a,&b);
        double p[a];
        double pGood=1;
        for(int i=0;i<a;i++){
            scanf("%lf",&p[i]);
            pGood*=p[i];
        }
        double min;
        double pKeepType=(2*b-a+2)*(1-pGood)+(b-a+1)*pGood;
        if(b+2<pKeepType)min=b+2;
        else min=pKeepType;
        for(int i=1;i<a;i++){
            double pG=1;
            for(int j=a-i-1;j>=0;j--)pG*=p[j];
            double temp=(2*i+(b-a)+1)*pG+(2*i+(2*b-a)+2)*(1-pG);
            if(temp<min)min=temp;
        }
        printf("Case #%d: %lf\n",k+1,min);
    }
    return 0;
}
