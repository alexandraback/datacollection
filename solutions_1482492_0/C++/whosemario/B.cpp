#include<iostream>
#include<cmath>
using namespace std;

double a[12];
double res[12];
double x[2][2];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("data.out","w",stdout);
    
    int t;
    cin>>t;
    int ca;
    for(ca=1;ca<=t;ca++){
        double d;
        int n,A;
        scanf("%lf%d%d",&d,&n,&A);
        int i;
        for(i=0;i<n;i++)
          scanf("%lf%lf",&x[i][0],&x[i][1]);
        for(i=0;i<A;i++)
          scanf("%lf",&a[i]);
        if(n==1){
           for(i=0;i<A;i++){
               res[i]=sqrt(d*2.0/a[i]);
           }
           
        }
        else{
             double v=(x[1][1]-x[0][1])/(x[1][0]);
             for(i=0;i<A;i++){
                double ti=(2.0*v+sqrt(4.0*v*v+8.0*a[i]*x[0][1]))/(a[i]*2.0);
//                cout<<ti<<endl;
                if(a[i]*ti*ti/2.0>=d) res[i]=sqrt(d*2.0/a[i]);
                else res[i]=ti+((d-a[i]*ti*ti/2)/v);
             }
        }
        printf("Case #%d:\n",ca);
           printf("%.6lf\n",res[0]);
           for(i=1;i<A;i++)
              printf("%.6lf\n",res[i]);
    }
}
