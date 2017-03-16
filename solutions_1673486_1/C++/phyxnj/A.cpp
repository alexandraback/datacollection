/***
3
2 5
0.6 0.6
1 20
1
3 4
1 0.9 0.1
Case #1: 7.000000
Case #2: 20.000000
Case #3: 4.500000
***/
#include <cstdio>
double p[110000];
double v[110000];
double x[110000];
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int T,ca=0;
    scanf("%d",&T);
    while(T--){
        int A,B;
        scanf("%d%d",&A,&B);
        for(int i=1;i<=A;i++){
            scanf("%lf",&p[i]);
        }
        double ans=-2;
        x[0]=1;
        for(int i=1;i<=A;i++){
            x[i]=x[i-1]*p[i];
        }
        v[0]=0;
        for(int i=1;i<=A;i++){
            v[i]=x[i-1]*(1-p[i]);
            v[i]+=v[i-1];
        }
        for(int i=0;i<=A;i++){
            double cal;
            cal=i+(1-v[A-i])*(B-A+1+i)+(B-A+1+i+B+1)*v[A-i];
            if(ans<-1||cal<ans) ans=cal;
        }
        if(ans>B+2) ans=B+2;
        printf("Case #%d: %.7f\n",++ca,ans);
    }
}
