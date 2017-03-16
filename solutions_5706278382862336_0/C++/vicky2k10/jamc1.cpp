#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long int gcd ( long long int a, long long int b )
{
  long long int c;
  while ( a != 0 ) {
     c = a;
	 a = b%a;
	 b = c;
  }
  return b;
}

int main()
{       char arr[26];
	    long long int a,b,x;
    int t,i,j;
    cin>>t;
	for(j=1;j<=t;j++)
	{   
		scanf("%s",arr);
        for(i=0;i<strlen(arr);i++)
        if(arr[i]=='/')
        break;
        a=atoll(arr);
        b=atoll(arr+i+1);
    int ans=0,y=0;
    while(1)
    {    
         if(a==1 && b==1)
         break;
		 x=gcd(a,b);
	     if(x!=1)
	     {
	     	a=a/x;
	     	b=b/x;
	     }
		 if(b%2==0)
         {
             b=b/2;             
			 if(y==false)
             ans++;
             if(a==1 && b==1)
             break;
             else if(a>b)
             {
             	y=1;
             	a=a-b;
             }
         }
         else {ans=-1;break;
         }
    if(a==b)
    {a=1;b=1;
    }
    }
	if(ans!=-1)
	printf("Case #%d: %d\n",j,ans);
	else
	printf("Case #%d: impossible\n",j);
	}
	return 0;
}


