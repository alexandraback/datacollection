#include<stdio.h>
#include<math.h>
#include<string.h>

int isPalindrome(unsigned long long val)
{
	char s[20];
	int l,i;
	sprintf(s,"%llu",val);
	l=strlen(s);
	for(i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-1-i])
			return 0;
	}	
	return 1;
}

int main()
{
	int t,cases;
	unsigned long long a,b,val,res,sq;
	scanf("%d",&t);
	for(cases=1;cases<=t;cases++)
	{
		scanf("%llu %llu",&a,&b);
		val=sqrt(a);
		res=0;
		while(1)
		{
			if(isPalindrome(val))
			{
				sq=val*val;
				if(sq>b)
					break;
				if(sq>=a && sq<=b && isPalindrome(sq))
					res++;	
			}
			val++;
		}
		printf("Case #%d: %llu\n",cases,res);
	}
	return 0;
}
