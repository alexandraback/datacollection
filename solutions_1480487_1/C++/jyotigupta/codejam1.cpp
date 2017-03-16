#include<iostream>
#define size1 300
#define eps 0.0000001
using namespace std;
int main()
{
    int t;
    cin>>t;
    int a;
    a=t;
    while(t--)
    {
              
              int n;
              cin>>n;
              int arr[size1];
              double sum=0;
              for(int i=0;i<n;i++)
              {cin>>arr[i];
             sum+=arr[i];
              }
              cout<<"Case #"<<a-t<<": ";
             for(int i=0;i<n;i++)
             {
                     //run bs
                     double start=0.0,end=100.0,mid,ansmod=100.0;
                     while(start <end )
                      {
                       mid=(start+end)/2;
                       
                       double score=arr[i]+((sum)*(mid))/100;
                       double add=mid;
                       for(int j=0;j<n;j++)
                       {
                       if(j !=i)
                       {
                       
                        double score1=((score-arr[j])*100)/(sum);
                           if(score1 > 0.0)
                            add+=score1;
                            
                            
                            
                       }     
                          
                       //cout<<start<<" "<<mid<<" "<<end<<" "<<score<<" "<<add<<"\n";
                         //   system("pause");
                       
                       }//end j
                       if(add>=100.0)
                       {
                       ansmod=mid;
                       end=mid-eps;
                       
                       }
                       else
                       start=mid+eps;
                                  
                                 
                      }//end bs
                     
                     printf("%.6lf ",ansmod);
                     //cout<<mid<<" ";
                     
                     }
                     cout<<"\n";
              }
    //system("pause");
    
    }
