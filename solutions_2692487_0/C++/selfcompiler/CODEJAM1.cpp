#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<algorithm>
using namespace std;
int array[103][6];//sum,add,del,flag,ans
int arr[103];
int a,n;
int main()
{
  int tc,_min,t=1;
  scanf("%d",&tc);
  while(tc--)
  {
	  scanf("%d%d",&a,&n);
	  memset(array,0,sizeof array);
	  for(int i=1;i<=n;i++)
		  scanf("%d",&arr[i]);
	  sort(arr+1,arr+n+1);
	  array[0][0]=a;
	  _min=1000000;
	  if(a==1)
	  {
		  printf("Case #%d: %d\n",t,n);
		  t++;
		  continue;
	  }
	  for(int i=1;i<=n;i++)
	  {
               array[i][0]+=array[i-1][0];
	       array[i][1]+=array[i-1][1];
	       array[i][2]+=array[i-1][2];
	//       printf("%d %d %d\n",array[i][0],array[i][1],array[i][2]);
	       if(array[i][0]>arr[i])
	       {
		       array[i][0]+=arr[i];
		       continue;
	       }
	       else 
	       {
		   array[i][3]=1;
		   array[i][4]=n-i+1+array[i-1][1]+array[i-1][2];//add+del=sum;
		   _min=min(_min,array[i][4]);
                   while(arr[i]>=array[i][0])
		   {
			   array[i][0]=2*array[i][0]-1;
			   array[i][1]++;
		   }
		   array[i][0]+=arr[i];
	       }
	  }
	  _min=min(_min,array[n][1]+array[n][2]);
	  printf("Case #%d: %d\n",t,_min);
	  t++;

  }
}
