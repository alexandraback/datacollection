#include<iostream>
#include<cstdio>
#include<conio.h>
using namespace std;
#define MAX(a,b)  a<b?b:a

long int *t;
long int *t1;
long int *r,*r1;

int checksubset(long int arr[],int s,int k,long int rr[],int ind[],int index)
{
     if(s<=0||s>k)
           return 1;
     else if(t[s])
     {
         // printf("%d ",arr[rr[s]]);
          for(int i=0;i<index;i++)
              if(ind[i]==arr[rr[s]])
                   return 0;
          ind[index]=arr[rr[s]];         
          return checksubset(arr,s-arr[rr[s]],k,rr,ind,index+1);
     }          
     return 0; 
}

int printsubset(long int arr[],int s,int k,long int rr[])
{
     if(s<=0||s>k)
           return 1;
     else if(t[s])
     {
          printsubset(arr,s-arr[rr[s]],k,rr);
          printf("%d ",arr[rr[s]]);     
     }           
}

int getsubsets(long int arr[],int n,int sum)
{
      t[0]=1;
      for(int i=0;i<n;i++)
      {
            for(int j=0;j<=sum-arr[i];j++)
            {
                  if(t[j]&&j!=arr[i])
                  {
                       if(r[j+arr[i]]==-1)
                       {
                            r[j+arr[i]]=i;             
                       }        
                       r1[j+arr[i]]=i;
                       t[j+arr[i]]=1;
                  }       
            }              
      }     
      int index[20];
      for(int i=0;i<=20;i++)
         index[i]=-1;
      for(int i=1;i<=sum;i++)
      {
          //cout<<"\nhere"<<i<<" "<<t[i]<<" "<<r[i]<<" "<<r1[i];    
          if(t[i])
          {
                 // cout<<"\nhere"<<i<<" "<<r[i]<<" "<<r1[i];
              if(r[i]!=r1[i])
              { 
                  int t=checksubset(arr,i,sum,r,index,0);     
                  if(t==0) continue;
                  t=checksubset(arr,i,sum,r1,index,0);     
                  if(t==0) continue;
                  printf("\n");
                  printsubset(arr,i,sum,r);     
                  printf("\n");
                  printsubset(arr,i,sum,r1);     
                  printf("\n");
                  return 1;
              }   
          }                
      }
      return 0;
}

int main()
{
     int test,n,i,j,x;
     long int num[20],total=0;
     cin>>test;    
     for(i=1;i<=test;i++)
     {
            total=0;          
            cin>>n;
            for(j=0;j<n;j++)          
            {
                  cin>>num[j];
                  total+=num[j];
            }
            t=(long int *)malloc((total+1)*sizeof(long int));
            r=(long int *)malloc((total+1)*sizeof(long int));
            t1=(long int *)malloc((total+1)*sizeof(long int));
            r1=(long int *)malloc((total+1)*sizeof(long int));
            for(j=0;j<total+1;j++)
            {
                  t[j]=0;
                  r[j]=-1;
                  r1[j]=-1;                
            }
            cout<<"Case #"<<i<<": ";
            int t=getsubsets(num,n,total);
            if(t==0)
                 cout<<"Impossible\n";
     }
     getch();
}
