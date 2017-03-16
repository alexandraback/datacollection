#include<iostream>			
#include<cstdio>
using namespace std;
int e,r,n,answer;
int v[50];
void funct(int index,int energy,int gain)
{
       if(index==n)
       {
              answer=max(answer,gain);
              return ;          
       }
       for(int i=0;i<=energy;i++)
       {
              if((energy-i+r)<=e)
              funct(index+1,(energy-i)+r,gain+v[index]*i);        
              else
              funct(index+1,e,gain+v[index	]*i);
       }       
       return ;
}

int main()
{
       int t,p;
       scanf("%d",&t);
       for(p=1;p<=t;p++)
       {   
          scanf("%d %d %d ",&e,&r,&n);
          for(int i=0;i<n;i++)
              scanf("%d",&v[i]);
          answer=0;   
          funct(0,e,0);    
         // scanf("Case ")
          cout<<"Case #"<<p<<": "<<answer<<"\n";
        }
        return 0;    
}
