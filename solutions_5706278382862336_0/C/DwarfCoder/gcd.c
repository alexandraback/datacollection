#include <stdio.h>
#include <math.h>
int findgcd(int x,int y){
     while(x!=y){
          if(x>y)
              return findgcd(x-y,y);
          else
             return findgcd(x,y-x);
     }
     return x;
}
int main(void) {
	long test,count=1,ans,gcd;
	float temp,p,q;
	scanf("%ld",&test);
	while(test--)
	{
		ans=0;
		scanf("%f/%f",&p,&q);
		temp=log(q)/log(2);
		if(floor(temp)!=temp)
			printf("Case #%ld: impossible\n",count++);
		else
		{
			gcd=findgcd(p,q);
			p/=gcd;
			q/=gcd;
			temp=(p/q)*2;
			ans++;
			if(floor(temp)>=1)
				ans=1;
			else
			{
				while(floor(temp)!=1)
				{
					temp=temp*2;
					ans++;
				}
			}
			printf("Case #%ld: %ld\n",count++,ans);
		}
	}
	return 0;
}
