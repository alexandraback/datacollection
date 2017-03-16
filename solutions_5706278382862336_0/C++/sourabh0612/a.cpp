#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int t,kase=1;
	scanf("%d",&t);
	while(t--)
	{
		int num, den;
		char ch;
		scanf("%d",&num);
		scanf("%c",&ch);
		scanf("%d",&den);
		
		if((den != 1) && (den & (den - 1)))
		{
			printf("Case #%d: impossible\n",kase);
			kase++;
			continue;
		}
		if(den%num == 0)
		{
			den = den/num;
			num = 1;
		}
		int count = 0;
		int div = den/num;
		if(num == 1)
		{
			while(den != 1)
			{
				den/=2;
				count++;
			}
			printf("Case #%d: %d\n", kase,count);
			kase++;
			continue;
		}
		while(div != 0)
		{
			div/=2;
			count++;
		}
		printf("Case #%d: %d\n", kase,count);
		kase++;
	}
	return 0;
}