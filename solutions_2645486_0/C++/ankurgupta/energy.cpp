#include<iostream>
using namespace std;
int arr[70000000];
int main()
{
    int t,x=1;
    cin>>t;
    while(t--)
    {
       int e,r,n;
       int a[100];
       cin>>e>>r>>n;
       for(int i=0;i<n;i++) cin>>a[i];       
       
       int lim=1;
       for(int i=0;i<n;i++) lim=lim*(e+1);
       int ans=0;
     
       for(int i=0;i<lim;i++)
       {
            int temp=i,tempans=0,oldenergy=e,j=0;   
            while(temp>0)
            {
                arr[j++]=temp%(e+1);
                temp/=(e+1);         
            }   
            for(int k=j;k<n;k++) arr[k]=0;
            //cout<<i<<"\n";
            for(int k=0;k<n;k++)
            {                 
                 int temptempans = min(oldenergy,arr[k])*a[k];                                  
                 tempans=tempans+temptempans;  
                 int newenergy = oldenergy-min(oldenergy,arr[k]);
                 newenergy  = min(e,newenergy + r);
                 oldenergy = newenergy;
                 
                 //cout<<k<<" "<<newenergy<<" "<<arr[k]<<" "<<tempans<<" "<<temptempans<<"\n";
            }       
            //cout<<tempans<<"\n\n";
            ans=max(ans,tempans);
       }
       printf("Case #%d: %d\n",x++,ans);
//       cout<<ans<<"\n\n\n";
    }
}
