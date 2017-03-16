#include<algorithm>
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
    int T,count=1;
    double c,f,x,sum,s,t1,t2,t=0;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",count++);
        sum=0;s=2.0,t=0;
        scanf("%lf%lf%lf",&c,&f,&x);
        while(1){

            t1=x/s;
            t2=c/s+x/(s+f);
            //printf("t1=%lf , t2=%lf  \n",t1,t2);
            if(t1<=t2){
                printf("%.7lf\n",t+t1);
                break;
            }
            else {
                t+=c/s;
                s+=f;
            }
        }
    }

    return 0;
}
