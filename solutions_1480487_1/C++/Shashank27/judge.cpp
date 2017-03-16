#include<iostream>

using namespace std;
int main()
{
    int t,n,A[300],sum=0,nsum=0;
    
    double res[300];
    cin>>t;
    int ct=0;
    while(ct++<t)
    {
                 int chk[300]={0};
                 sum=0;
                 nsum=0;
                 cin>>n;
                 for(int i=0;i<n;i++)
                 {
                         cin>>A[i];
                         sum+=A[i];
                 }
                 nsum=sum;
                 int num=n;
                 double ns=(sum+nsum)/n;
                 for(int i=0;i<n;i++)
                 {
                         if(A[i]>ns)
                         {
                                    num--;
                                    chk[i]=1;
                                    nsum-=A[i];
                         }
                 }
                 ns=(double)(sum+nsum)/num;
                 for(int i=0;i<n;i++)
                 {
                         if(chk[i]==1)
                                      res[i]=0;
                         else
                         {
                         res[i]=ns-A[i];
                         res[i]/=sum;
                         res[i]=res[i]*100;
                         } 
                 }
                 cout<<"Case #"<<ct<<": ";
                 for(int i=0;i<n;i++)
                 {
                         if(i==n-1)
                                printf("%f",res[i]);
                         else   
                        printf("%f ",res[i]);
                 }
                 cout<<endl;
    }
     
    return 0;
}
                 
