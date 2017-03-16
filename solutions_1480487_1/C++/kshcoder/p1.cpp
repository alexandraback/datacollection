#include<iostream>
#include<cstdio>
#include<conio.h>
using namespace std;
#define MAX(a,b)  a<b?b:a

int main()
{
     int t,n,i,j,x;
     float total=0,score[200],perc[200],reqd=0,max=100,sum=0;;
     cin>>t;    
     for(i=1;i<=t;i++)
     {
            total=0;          
            cin>>n;
            for(j=0;j<n;j++)          
            {
                  cin>>score[j];
                  total+=score[j];
                  max=MAX(max,score[j]);
                  perc[j]=-1;
            }
            sum=2*total;
            reqd=sum/n;
            if(max>reqd)
            {
                x=n;        
                for(j=0;j<n;j++)
                {
                      if(score[j]>reqd)
                      {
                          sum=sum-score[j];
                          x--;
                          perc[j]=0;                 
                      }
                }      
                reqd=sum/x;  
            }
            for(j=0;j<n;j++)
            {
                if(perc[j]==-1)            
                  perc[j]=(100*(reqd-score[j]))/total;          
            }
            cout<<"Case #"<<i<<": ";
          /*  cout<<"\ninput ";
            for(j=0;j<n;j++)
            {
                 cout<<score[j]<<" ";                
            }
           */ for(j=0;j<n;j++)
            {
                    //cout<<perc[j]<<" ";        
                    if(j==(n-1))
                         printf("%.6f\n",perc[j]);
                    else     
                        printf("%.6f ",perc[j]);
            }
     }
    // getch();
}

