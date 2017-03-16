#include<cstdio>
#include<math.h>
using namespace std;
int cas,n,a;
double d;
double ti[2005],xi[2005];
int main(){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("out2.txt","w",stdout);
    scanf("%d",&cas);
    int ca=1;
    while(cas--)
    {
        scanf("%lf%d%d",&d,&n,&a);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&ti[i],&xi[i]);    
        }   
        double ai;
        printf("Case #%d:\n",ca++);
        for(int i=0;i<a;i++)
        {
            scanf("%lf",&ai);
            if(n==1)
            {
                printf("%.8lf\n",sqrt(2*d/ai));    
            }
            else
            {
                double dis=xi[1]-xi[0],det=ti[1]-ti[0];
                double vvv=dis/det; 
                if(xi[0]>=d){
                    printf("%.8lf\n",sqrt(2*d/ai));    
                }else{
                    double ttt=(d-xi[0])/vvv;
                    
                    if(0.5*ai*ttt*ttt<=d){
                        printf("%.8lf\n",sqrt(2*d/ai));    
                    }else{
                        printf("%.8lf\n",(d-xi[0])/vvv);   
                    } 
                    
                    //printf("aaa\n");   
                }
            }
        }
    }
    return 0;    
}
