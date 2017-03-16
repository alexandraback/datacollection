#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t,z=1;
    cin>>t;
    while(t--)
    {
        int n,a;
        double d;
        double t[100],x[100];
        double temp,v=0;
        cin>>d;
        cin>>n>>a;
        for(int i=0;i<n;i++)
          cin>>t[i]>>x[i];
        if(n==1)
        {      
               printf("Case #%d:\n",z++);
               for(int i=0;i<a;i++) 
               {
                    cin>>temp;                  
                    double t1=(sqrt)(d*2.0/a);
                    printf("%.9f\n",t1);
               }
               continue;
        }
        
        if(n==2)
        {
           v=(x[1]-x[0])/(double)(t[1]-t[0]);     
        }  
               printf("Case #%d:\n",z++);        
        for(int i=0;i<a;i++) 
        {
             cin>>temp;   
             double dis=2.0*2.0*v*v+8.0*temp*x[0];
             dis=sqrt(dis);
             double t1=(2.0*v+dis)/(2.0*temp);
             
             double mid=(temp*t1*t1)/2.0;             
             double rem=d-mid;
             double t2=(rem/v);
             if(t2<0) 
             {
               t2=0;
               t1=sqrt((d*2.0)/temp);
             }             
            // cout<<v<<" "<<dis<<" "<<t1<<" "<<t2<<" "<<mid<<" "<<rem<<" ";
             printf("%.9f\n",t1+t2);
        }
              
    }
}
