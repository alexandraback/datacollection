#include<stdio.h>
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
	int t,cases,i;
	unsigned long long a,b,val,res,sq;
	unsigned long long list[50];
	int count=0;
	val=1;
	a=1;
	b=100000000000000;
	while(1)
	{
		if(isPalindrome(val))
		{
			sq=val*val;
			if(sq>b)
				break;
			if(sq>=a && sq<=b && isPalindrome(sq))
				list[count++]=sq;
		}
		val++;
	}
	scanf("%d",&t);
	for(cases=1;cases<=t;cases++)
	{
		scanf("%llu %llu",&a,&b);
		res=0;
		for(i=0;i<count;i++)
		{
			if(list[i]>=a && list[i]<=b)
				res++;
		}
		printf("Case #%d: %llu\n",cases,res);
	}
	return 0;
}
