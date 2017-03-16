#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int getans(char *str,int n)
{
      int lastpos=-1;
      int currlen=0;
      int ans=0,left,right,i;
      int len=strlen(str);
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
                                i=lastpos;
                                currlen=0;
                        }                             
             }
             else currlen=0;
      }
      return ans;
}

int main()
{
     char str[200];
     int t;
     int n,ans;
     scanf("%d",&t);
     for(int i=1;i<=t;i++)    
     {
             scanf("%s %d",str,&n);
             ans=getans(str,n);
             printf("Case #%d: %d\n",i,ans);        
     }
}
