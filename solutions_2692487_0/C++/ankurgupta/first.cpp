#include<iostream>
using namespace std;
int arr[110],cum[110],needed[110];
int a,n;
int findnonzero(int start)
{
   for(int i=start;i<n;i++) if(needed[i]!=0) return i;
   return n;    
}

int main()
{
    int t;
    cin>>t;
    int x=1;
    while(t--)
    {
                cin>>a>>n;
         for(int i=0;i<n;i++) cin>>arr[i];
         sort(arr,arr+n);
         cum[0]=arr[0];
         for(int i=1;i<n;i++) 
             cum[i]=cum[i-1]+arr[i];
         
         int curmote=a;
         int tempadd=0;
         int ans=10000000;
         int prev=0;
         while(true)         
         {
             if(curmote==1)  { ans=n;     break;           }
             int tempcurmote=curmote;
             //cout<<curmote<<"\n";
             //for(int i=0;i<n;i++) cout<<arr[i]<<" ";
             //cout<<"\n";
             
             int start=prev;
             for(int i=start;i<n;i++) 
                     if(arr[i]<curmote) 
                     {
                        curmote+=arr[i];
                        start=i+1;
                     }
             int tempmote=curmote;
             for(int i=start;i<n;i++)
             {                                      
                needed[i]= (arr[i]+1-tempmote)>0?(arr[i]+1-tempmote):0; 
                if(needed[i]<=0) { 
                                needed[i]=0;
                                tempmote+=arr[i];
                }
                if(needed[i]>0)
                {
                  tempmote=tempmote+tempmote-1+arr[i];
                }              
                //cout<<arr[i]<<" "<<tempmote<<"\n";
             }
             
             int idx=findnonzero(start);                             
             int tempremove = n-idx;
             //cout<<idx<<" "<<tempremove<<"\n";
             
             int notoadd=0;
             
             for(int i=start;i<n;i++) 
             {
                   if(needed[i]!=0) 
                   {
                     notoadd=needed[i];
                     break;  
                   } 
             }
             if(notoadd==0)  {
                             ans=min(ans,tempremove+tempadd); break; }
             tempmote=curmote;
             for(int i=start;i<n;i++)
             {
                // tempmote = curmote ;   
                 if(tempmote>arr[i])
                 {
                     tempmote+=arr[i];            
                 }    
             }             
             if(notoadd>=curmote) notoadd=0;
             curmote+=max(tempmote-1,notoadd);             
             //cout<<notoadd<<" "<<curmote<<" "<<tempadd<<"\n";
             //for(int i=start;i<n;i++) cout<<needed[i]<<" ";
             //cout<<"\n";
             ans=min(ans,tempremove+tempadd);
             tempadd++;
             prev=start;
             //system("pause");
         }     
         if(ans==10000000) ans=tempadd;
         printf("Case #%d: %d\n",x++,ans);
//         cout<<"Case "<<x++<<": "<<ans<<"\n";
    }
}
