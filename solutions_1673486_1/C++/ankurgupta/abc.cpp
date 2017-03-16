#include<iostream>
using namespace std;
double p[110000],pow2[110000],cum[110000];
int main()
{
    int t,l=1;
    cin>>t;
    while(t--)
    {
        double ans=0,typing=0,e=0,backmin=0,temp1=0;   
        int flag=1;   
        int a,b;
        cin>>a>>b;        
        //pow2[0]=1.0;
        //for(int i=1;i<110000;i++) pow2[i]=pow2[i-1]*2;
        for(int i=0;i<a;i++) cin>>p[i];
        
        cum[0]=p[0];  
        for(int i=1;i<a;i++)   
          cum[i]=cum[i-1]*p[i];      
        
       // cout<<cum[a-1]<<" "<<pow2[b]<<"\n";
        typing=typing+(cum[a-1]*(double)(b-a+1));
        
        typing=typing+((1.0-cum[a-1])*(double)(2*b-a+2));
        
        e=e+(b+2);
        
        for(int i=1;i<a;i++)
        {
           temp1=cum[a-1-i]*(b-a+2*i+1);     
           
           temp1=temp1+(1-cum[a-1-i])*(2*b-a+2*i+2);
           if(flag==1)
           {
             backmin=temp1;flag=0;
           }
           else 
              backmin=min(backmin,temp1);
           //cout<<temp1<<"\n";
        }
        //cout<<typing<<" "<<e<<"\n";
        ans=min(typing,e);
        if(flag==0)
        ans=min(ans,backmin);
        printf("Case #%d: %.9f\n",l++,ans);
//        cout<<ans<<"\n";
    }
}


   
