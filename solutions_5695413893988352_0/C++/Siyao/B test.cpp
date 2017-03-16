#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;


char tmp1[100],tmp2[100];
int ans1[100],ans2[100];
int tans1[100],tans2[100];
int len;
long long minv=-1;
void dfs(long long  value, int i)
{
  if(i==len)
  {
    if(value<0) value = -value;
    if(minv==-1||value<minv)
    {
      minv=value;
      for(int j=0;j<len;++j)
	{
	  ans1[j]=tans1[j];
	  ans2[j]=tans2[j];
	}
    }
    return;
  }
  value*=10;
  
  if(tmp1[i]=='?')
   {
      for(int j=0;j<10;++j)
      {
	  tans1[i]=j;
	  if(tmp2[i]=='?')
	  {
	    for(int k=0;k<10;++k) {tans2[i]=k;  dfs(value+tans1[i]-tans2[i],i+1);}
	   }
	

     }
  }
  else 
   {
   	  tans1[i]=tmp1[i]-'0';
	  if(tmp2[i]=='?')
	  {
	    for(int k=0;k<10;++k) {tans2[i]=k;  dfs(value+tans1[i]-tans2[i],i+1);}
	   }
	  else
	  {
	     tans2[i]=tmp2[i]-'0';
	     dfs(value+tans1[i]-tans2[i],i+1);
	  }
	
  }
  
}
Int main()
{
  int  T;
  scanf("%d",&T);
  for(int i=1;i<=T;++i)
  {
    printf("Case #%d: ", i);
    scanf("%s%s",tmp1,tmp2);
    minv=-1;
    len=strlen(tmp1);
    dfs(0,0);
    for(int j=0;j<len;++j) printf("%d",ans1[j]);
    printf(" ");
    for(int j=0;j<len;++j) printf("%d",ans2[j]);
    printf("\n");
    // deal 
  }
  //printf("%d\n",maxt);
  return 0;
}
