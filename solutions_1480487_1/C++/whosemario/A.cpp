#include<iostream>
using namespace std;

double res[205];
int p[205];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.data","w",stdout);
    
    int t;
    cin>>t;
    int ca;
    for(ca=1;ca<=t;ca++){
        int n;
        cin>>n;
        int sum=0;
        int i;
        int s;
        for(i=0;i<n;i++){
           cin>>s;
           sum+=s;
           p[i]=s;
           res[i]=-1.0;
        }
        double tmpsum=sum*1.0;
        int m=0;
        double dsum=sum*2.0/(n*1.0);
        sum=0;
        for(i=0;i<n;i++){
           if(p[i]*1.0<dsum){
              m++;
              sum+=p[i];
           }
           else
              res[i]=0.0;
        }
        dsum=(sum*1.0+tmpsum)/(m*1.0);
        for(i=0;i<n;i++)
           if(res[i]<0){
               res[i]=(dsum-p[i]*1.0)/tmpsum;
           }
        printf("Case #%d:",ca);
        for(i=0;i<n;i++)
           printf(" %.6lf",res[i]*100.0);
//             cout<<" "<<res[i]*100.0;
        printf("\n");
    }
}
