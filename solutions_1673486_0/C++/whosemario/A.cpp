#include<iostream>
using namespace std;

double p[10005];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.data","w",stdout);
    int t;
    cin>>t;
    int ca;
    for(ca=1;ca<=t;ca++){
        int a,b;
        cin>>a>>b;
        int i;
        for(i=0;i<a;i++)
          scanf("%lf",&p[i]);
        double res=2+b;
        double tmp=0.0;
        // one
        double sumP=1.0;
        for(i=0;i<a;i++)
           sumP*=p[i];
        tmp=sumP*(b-a+1)+(1.0-sumP)*(b-a+1+b+1);
        if(tmp<res) res=tmp;
        // two
        sumP=1.0;
        tmp=sumP*(a+b+1);
        if(tmp<res) res=tmp;
        for(i=0;i<a;i++){
           sumP*=p[i];
           tmp=sumP*(a-(i+1)+b-(i+1)+1)+(1-sumP)*(a-(i+1)+b-(i+1)+1+b+1);
           if(tmp<res) res=tmp;
        }
        printf("Case #%d: %.6lf\n",ca,res);
    }
}
