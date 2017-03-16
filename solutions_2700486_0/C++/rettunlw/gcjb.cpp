#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n,x,y,T,z,z0,a,b,ll,pp;
double p,g;
int main(){
        freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&T);
    for (int rc=1;rc<=T;rc++){
        scanf("%d%d%d",&n,&x,&y);
        if (x<0) x=-x;
        if (y<0) y=-y;
        z=x+y;
        ll=z;
        z/=2;
        z0=(z)*(z*2-1);
        z=(z+1)*(z*2+1);
        if (z<=n){
            p=1;      
        }
        else if (z0>=n){
            p=0;     
        }
        else{
          
            b=n-z0;
           // cout<<b<<endl;
            a=y+1;
            if (y+1+ll<=b){
               p=1;                 
            }
            else if (y==ll){
               p=0;
            }
            else{
              pp=1;
              p=0;
              for (int i=1;i<=a;i++){
                  p+=pp;
                  pp=pp*(b-i+1)/i;    
              }       
              for (int i=0;i<b;i++)
                  p/=2.0;
               p=1-p;
            }
        }
        printf("Case #%d: %.7lf\n",rc,p);
    }
    return 0;   
}
