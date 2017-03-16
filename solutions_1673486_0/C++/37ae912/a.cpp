
#include <cstdio>
#include <iostream>
using namespace std;

int A,B;

double d[100010];
double dpall[100010];
double dpone[100010];


int main()
{
    int cs=0,t;
    scanf("%d",&t);
    while(cs++<t){
        printf("Case #%d: ",cs);
    
        scanf("%d%d",&A,&B);
        for(int i=1;i<=A;++i)
            scanf("%lf",d+i);
    
        dpone[0]=1.0;
        dpall[0]=1.0;

        for(int i=1;i<=A;++i){
            dpall[i]=d[i]*dpall[i-1];
            dpone[i]= 1.0-dpall[i];
        }
        double res=B+10;

        //type-1
        //double t1= B-A+1+ dpone[A]*(B+1);
        //if(res>t1)res=t1;

        
        for(int i=0;i<=A;++i){
            double t2 = i + (B-A+i+1) + dpone[A-i]*(B+1);
            if(res>t2)res=t2;
        }

        //type-3
        double t3= 1+B+1;
        if(res>t3)res=t3;

        printf("%.6lf\n",res);
        
    }

    return 0;
}
