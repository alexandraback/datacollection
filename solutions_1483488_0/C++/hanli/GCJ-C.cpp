#include<iostream>
#include<stdio.h>
typedef __int64 i64;
using namespace std;
int shuwei[10]={0,10,100,1000,10000,100000,1000000,10000000};
int used[20];
int usednum;
int main()
{
 	int t;
 	freopen("C-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);
 	scanf("%d",&t);
 	int caseNum;
 	int x,y;
 	int i,j,k;
 	i64 cnt;
 	int digit,temp,tempnum;
 	for(caseNum=1;caseNum<=t;caseNum++)
 	{
       cnt=0;
       scanf("%d%d",&x,&y);
       
       for(i=x;i<=y;i++)
       {
		   digit=0,temp=i;
		   usednum=0;
		   while(temp)
		   {
			  temp/=10;
			  digit++;
           }
           for(j=1;j<digit;j++)
           {
		       tempnum=i/shuwei[j]+(i%shuwei[j])*shuwei[digit-j];
		       
			   if(tempnum<=y&&tempnum>i)//1212 2121
			   {	 
			   		 for(k=0;k<usednum;k++)
			   		     if(used[k]==tempnum) break;
  		             if(k==usednum)
					 {
			            cnt++;
			            used[usednum++]=tempnum;
					 }
		       }
		   }
       }
       printf("Case #%d: %I64d\n",caseNum,cnt);
    }
 	return 0;
}
