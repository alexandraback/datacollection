#include<iostream>
using namespace std;
typedef long long LL;
int arr[300],hash[5000000];
int main()
{
    int t,z=1;
    cin>>t;
    while(t--)
    {
        int n;
        for(int i=0;i<5000*1000;i++) hash[i]=-1;
        cin>>n;
        for(int i=0;i<n;i++)         
            cin>>arr[i]; 
                                   
        int lim=(1<<n),ans1=-1,ans2=-1;
        
        for(int i=1;i<lim;i++)
        {
            int temp=i,sum=0,j=0;
            while(temp>0)
            {
               if(temp%2==1)
                 sum+=arr[j];          
               temp/=2;
               j++;  
            }    
            if(hash[sum]==-1)
              hash[sum]=i;
            else
            {
              ans1=i;
              ans2=hash[sum];  
              break;  
            }
        }
        
        
        printf("Case #%d:\n",z++);      
        if(ans1!=-1 && ans2!=-1)
        {
        int temp=ans1,j=0;
        while(temp>0)
        {
               if(temp%2==1)
                 cout<<arr[j]<<" ";
               temp/=2;
               j++;  
        }    
        cout<<"\n";
        temp=ans2;j=0;        
        while(temp>0)
        {
               if(temp%2==1)
                 cout<<arr[j]<<" ";
               temp/=2;
               j++;  
        }
        }
        else
         cout<<"Impossible";          
        cout<<"\n";  
    }
    //system("pause");
}
