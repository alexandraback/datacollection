#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
#include<math.h>
using namespace std;

long long gcd(long long a,long long b)
{
     if(b==0)
     return a;
     return gcd(b,a%b);
}

int main()
{
	long long T,cases =0 ;
	long long a,b,n;
	char c;
	double result;
	int i;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%lld",&T);
	while(1)
	{
		if(cases==T)
			break;
		cases++;
		printf("Case #%lld: ",cases);
		scanf("%lld",&a);
		scanf("%c",&c);
		scanf("%lld",&b);
//		printf("a = %lld\tb = %lld\n",a,b);
		n = gcd(a,b);
		a = a/n;
		b = b/n;
		if ( log2(b)!=(int)log2(b)|| a>b)
		{	
			printf("impossible\n");
			continue;
		}
		result=log2(b);
		if(result != (int)result)
		{
			printf("impossible\n");
			continue;
		}
		if(a==1)
          printf("%d\n",(int)result);
        else{
              for(i=0;i<result;i++)
              {
                  if(a >= (b/2))
                  break;
                  b= b/2;
              }
              printf("%d\n",i+1);
              }
          
	}
	return 0;
}
