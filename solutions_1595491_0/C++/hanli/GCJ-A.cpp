#include<iostream>
#include<stdio.h>
int sum[105];
using namespace std;
int numUp[50],supriseUp[50];
void init()
{
 	 int i,temp;
 	 numUp[0]=0,supriseUp[0]=-1;
 	 numUp[1]=1,supriseUp[1]=-1;
 	 for(i=2;i<=30;i++)
 	 {
          temp=i/3;
          if(i%3==0)
          {
			  numUp[i]=temp;//1 1 1
			  supriseUp[i]=temp+1;//0 1 2
          }else if(i%3==1)
          {
   		      numUp[i]=temp+1;// 9 9 10
   		      supriseUp[i]=temp+1;//8 10 10
   		  }else
   		  {
		   	   numUp[i]=temp+1;//9 10 10
		   	   supriseUp[i]=temp+2;//9 9 11
          }
     }
}

int main()
{
 	int t;
 	int i,j,len,casenum;
 	int n,num,up;
 	int cnt;
 	init();
 	
 	freopen("B-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);
 	scanf("%d",&t);
 	for(casenum=1;casenum<=t;casenum++)
 	{
        cnt=0;
        scanf("%d%d%d",&n,&num,&up);
        for(i=0;i<n;i++)
        {
		     scanf("%d",&sum[i]);
		     if(sum[i]<=1)
		     {
  			     if(numUp[sum[i]]>=up) cnt++;
  			  }else
  			  {
   	              if(numUp[sum[i]]>=up) cnt++;
				  else 
				  {
				   	   if(supriseUp[sum[i]]>=up&&num>0)
				   	   {
			               cnt++;
			               num--;
			           }
  	              } 
		      }
        }
        printf("Case #%d: %d\n",casenum,cnt);
        
        
    }
    return 0;
}
