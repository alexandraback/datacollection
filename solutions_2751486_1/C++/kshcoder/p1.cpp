#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

long long int getans(char *str,long int n)
{
      long int lastpos=-1;
      long int currlen=0;
      long long int ans=0,left,right,i;
      long int len=strlen(str);
      for(i=0;i<len;i++)    
      {
             if(str[i]!='a'&&str[i]!='e'&&str[i]!='o'&&str[i]!='u'&&str[i]!='i')
             {          
                        currlen++;
                        if(currlen==n)
                        {
                                if(lastpos==-1)      
                                       left=i-n+1;
                                else left=i-n+1-lastpos-1;
                                right=len-i-1;
                                lastpos=i-n+1;
                                ans+=(left+1)*(right+1);           
                             //   i=lastpos;
                             //   currlen=0;
                                  currlen=currlen-1; 
                        }                             
             }
             else currlen=0;
      }
      return ans;
}

int main()
{
     char str[1000008];
     int t;
     long int n;
     long long int ans;
     scanf("%d",&t);
     for(int i=1;i<=t;i++)    
     {
             scanf("%s %ld",str,&n);
             ans=getans(str,n);
             printf("Case #%d: %lld\n",i,ans);        
     }
}
