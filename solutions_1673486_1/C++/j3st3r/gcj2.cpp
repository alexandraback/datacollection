#include <iostream>
#include <cstdio>
using namespace std;
double ar1[100003],ar2[100003],ar3[100003];
int main(){
        int num,ii;
        scanf("%d",&num);
        for(ii=1;ii<=num;ii++){
                int a,b,i;
                double c,d,a1,a2,ans=99999999,a3;
                scanf("\n%d %d",&a,&b);
                ar2[0]=1;
                ar1[0]=0;
                for(i=a;i>=1;i--){
                        scanf("%lf",&ar1[i]);
                        ar2[0]*=ar1[i];
                }
                ar3[0]=ar2[0];
                for(i=1;i<=a;i++){
                        ar2[i]=((ar2[i-1]/(1-ar1[i-1]))*(1-ar1[i]))/ar1[i];
                        ar3[i]=ar3[i-1]+ar2[i];
                }
                
                a1=ar2[0]*(b-a+1)+(1-ar2[0])*(2*b-a+2);
                if(a1<ans){ans=a1;}
                a2=b+2;
                if(a2<ans){ans=a2;}
                for(i=1;i<=a;i++){
                        a3=(b-a+2*i+1)*(ar2[0]+ar3[i]-ar3[0])+(b-a+2*i+1+b+1)*(1-ar2[0]-ar3[i]+ar3[0]);
                        if(a3<ans){ans=a3;}
                }
                printf("Case #%d: %.6lf\n",ii,ans);
        }
        return 0;
}
                        
               
