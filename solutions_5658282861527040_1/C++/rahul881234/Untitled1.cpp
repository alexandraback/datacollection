#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
char *decimal_to_binary(int);
int main()
{
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
      int t,tt,a,b,k,v,count1,count2,count3,i,j,m,p;
      char *pa,*pb,*pc,*pk;
      pc=decimal_to_binary(0);
      cin>>t;
      int n=1;
      for(tt=1;tt<=t;tt++)
      {
            cin>>a>>b>>k;
            count2=0;
            for(i=0;i<a;i++)
            {
                   pa=decimal_to_binary(i);
                 
                   for(j=0;j<b;j++)
                   {
                          pb=decimal_to_binary(j);
                          
                          for(m=0;m<9;m++)
                          {
                                  if(pa[m]=='1'&&pb[m]=='1')
                                  pc[m]='1';
                                  else
                                  pc[m]='0';
                          }
                      
                          
                          for(p=0;p<k;p++)
                          {
                                 pk=decimal_to_binary(p);
                                
                                 count1=0; 
                                       
                                 count1=strcmp(pk,pc);
                                 
                                 if(count1==1)
                                 count2++;
                                 
                          }
                   }
            }
            cout<<"Case#"<<tt<<": "<<count2<<endl;
            
      }
      return 0;
}
char *decimal_to_binary(int n)
{
   int c, d, count;
   char *pointer;
 
   count = 0;
   pointer = (char*)malloc(10+1);
 
   if ( pointer == NULL )
      return NULL;
 
   for ( c = 9 ; c >= 0 ; c-- )
   {
      d = n >> c;
 
      if ( d & 1 )
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';
 
      count++;
   }
   *(pointer+count) = '\0';
 
   return  pointer;
}
