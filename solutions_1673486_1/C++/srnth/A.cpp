#include<cstdio>
int T;
#define MAXA 100000
#define min(a,b) ((a)>(b)?(b):(a))

int main(){
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int A,B;
        double p[MAXA];
        double pc=1.0;
        scanf("%d %d",&A,&B);
        int cl=B-A;
        for(int i=0;i<A;i++){
            scanf("%lf",p+i);
            pc*=p[i];
        }
        double a=cl+(1-pc)*(B+1);
        double b=100000000.0;
        for(int i=1;i<=A;i++){
            double pcn=1.0;
            
            for(int z=0;z<A-i;z++)
                pcn*=p[z];
            double k=cl+2*i+(1-pcn)*(B+1);
            if(k<b)b=k;
        }
        double c=1+B;
        printf("Case #%d: %lf\n",t+1,1+min(min(a,b),c));
    }
    
    return 0;
}

