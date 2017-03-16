#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
      unsigned long long num;
			int id;
			void read(){scanf("%lld%d",&num,&id);} 			 
}A[5],B[105];
unsigned long long dp[105][105];
int main()
{
      freopen("a.in","r",stdin);
      freopen("a.out","w",stdout);
      int T,n,m;
      scanf("%d",&T);
      for(int cas=1;cas<=T;cas++)
      {
			 	   scanf("%d%d",&n,&m);
			 	   printf("Case #%d: ",cas);
					 for(int i=1;i<=n;i++)A[i].read();	
					 for(int j=1;j<=m;j++)B[j].read();
					 memset(dp,0,sizeof(dp));
					 for(int i=1;i<=m;i++)			
					 { 
					     for(int j=1;j<=100;j++)dp[i][j]=dp[i-1][j];
							 dp[i][B[i].id]+=B[i].num;				 
           }
           if(n==2)
           {
					 	   if(A[1].id==A[2].id){A[1].num+=A[2].num	;n=1;}		 
 					 }
 					 else if(n==3)
 					 {
					     if(A[1].id==A[2].id&&A[2].id==A[3].id)
							 {
							     n=1;
									 A[1].num+=A[2].num+A[3].num;															
						   }			
						   else if(A[1].id==A[2].id)
						   {
							     n=2;A[1].num+=A[2].num;A[2]=A[3];			
							 }
							 else if(A[2].id==A[3].id) 
							 {
 		               n=2;A[2].num+=A[3].num;
							 }
					 }
           unsigned long long res=0;
           if(n==1)
           {
					 	   res=min(dp[m][A[1].id],A[1].num);			 
           }
           else if(n==2)
           {
					     unsigned long  long t;
							 for(int i=0;i<=m;i++)  			
					     {
							 		t=min(A[1].num,dp[i][A[1].id])+min(A[2].num,dp[m][A[2].id]-dp[i][A[2].id]);		 
								  res=max(res,t);
								}
					 }
					 else
					 {
					     if(A[1].id==A[3].id)res=max(res,min(dp[m][A[1].id],A[1].num+A[3].num))	; 		 
					     unsigned long long t1,t2,t3;
							 for(int i=0;i<=m;i++)		 
					     for(int j=i;j<=m;j++)
					     {
							 			t1=min(dp[i][A[1].id],A[1].num);
										t2=min(A[2].num,dp[j][A[2].id]-dp[i][A[2].id]);		  	 
										t3=min(A[3].num,dp[m][A[3].id]-dp[j][A[3].id]);		  	 
										res=max(res,t1+t2+t3)		;
						   }
							 
           }
					 cout<<res<<endl;		 
			 				 
      }


      return 0;
}
