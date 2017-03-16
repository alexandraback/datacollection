#include <iostream>
#include <cstdio>
using namespace std;
int arr[50]={1000000};

void dfs(int x,int y,int n,int m, int st,int res)
{
// 	 arr[res]=min(arr[res],st);
 	 for(int i=0;i<=res;i++)
 	 arr[i]=min(arr[i],st);
 	 if(x<n)
 	 {
	  		dfs(x+1,y,n,m,st+2,res+y);
	 }
	 if(y<m)
	 dfs(x,y+1,n,m,st+2,res+x);
}

int main()
{
 	 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);

 	int tc;
 	int co=1;
 	scanf("%d",&tc);
 	while(tc--)
 	{
	 		   int n,m,k;
	 		   scanf("%d%d%d",&n,&m,&k);
	 		   if(n<=2||m<=2)
	 		   {
			   				 printf("Case #%d: %d\n",co++,k);
			   				 continue;
	 		   }
	 		   else if(k==n*m)
	 		   {
 			   				  printf("Case #%d: %d\n",co++,2*(n+m)-4);
 			   				  continue;
 			   }
 			   else
 			   {
			   	   for(int i=0;i<50;i++)arr[i]=100000;
					  arr[0]=0;
					  arr[1]=1;
					  arr[2]=2;
					  arr[3]=3;
					  arr[4]=4;
					  arr[5]=4;
					  dfs(3,3,n,m,4,5);
					  for(int i=6;i<=k;i++)
					  {
					   		  for(int j=0;j<=i;j++)
					   		  arr[i]=min(arr[i],arr[j]+i-j);
   		  			  }
   		  			  printf("Case #%d: %d\n",co++,arr[k]);
			   }
  	}
}
