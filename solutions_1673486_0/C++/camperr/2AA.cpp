#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b;
double pr[100007];
double cal[100007];
double min(double c,double d){
    return c<d?c:d;
}
double op1(){
    return cal[a-1]*(b-a+1)+(1-cal[a-1])*(b-a+b+2);
}
double op2(){
    double ans=1e9,tm;
    int i;
    for(i=0;i<a;i++){
        if(i==0){
            tm=a+b+1;
        }else{
            tm=cal[i-1]*(a-i+b-i+1)+(1-cal[i-1])*(a-i+b-i+1+b+1);
        }
        ans=min(ans,tm);
    }
    return ans;
}
double op3(){
    return 2+b;
}
int main(){
    int t,i,j,k;
    //freopen("in.txt","r",stdin);
    //freopen("A-small-attempt0.in","r",stdin);
   // freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(j=1;j<=t;j++){
        scanf("%d %d",&a,&b);
        for(i=0;i<a;i++){
            scanf("%lf",pr+i);
             if(i==0) cal[i]=pr[i];
             else cal[i]=cal[i-1]*pr[i];
        }
        double ans=1e9;
        ans=min(ans,op1());
        ans=min(ans,op2());
        ans=min(ans,op3());
        printf("Case #%d: %lf\n",j,ans);
    }
}
