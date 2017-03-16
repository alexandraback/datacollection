#include<iostream>
#define eps 0.0000001
using namespace std;
typedef long long LL;
double arr[300],ans[300];
int main()
{
    int t,z=1;
    cin>>t;
    while(t--)
    {
        int n;
        double x=0;
        cin>>n;
        for(int i=0;i<n;i++) 
        {
            cin>>arr[i];                
            x=x+arr[i];
        }      
        
        for(int i=0;i<n;i++)
        {
           double start=0.0;
           double end=100.0,tempans=100.0;
           //cout<<"person "<<i<<"\n";
           while(start<=end)
           {
              double mid=(start+end)/2;
              double y=mid;
              double score=arr[i]+x*(mid/100.0);
              for(int j=0;j<n;j++)
              {
                  if(j!=i)
                  {
                      double req=(score-arr[j])/(double)x;    
                      if(req>=0)
                      y+=(req*100);
                  }    
              }             
              //cout<<start<<" "<<end<<" "<<mid<<" "<<y<<"\n";              
              if(y>(double)100.0) 
              {                 
                  tempans=mid;
                  end=mid-eps;                                
              }
              else if(y<=(double)100.0)
              {
                  start=mid+eps;                                           
              }
           }   
//           if(tempans<(double)0.000001) tempans=0.0;
           ans[i]=tempans;             
        }
        printf("Case #%d: ",z++);      
        for(int i=0;i<n;i++) printf("%.9f ",ans[i]);
        cout<<"\n";
    }
    //system("pause");
}
