#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long int

LL to_size (LL inp)
{
	if(inp < 1)
		return 0;
	if(inp < 10)
		return 1;
	if(inp < 100)
		return 2;
	if(inp < 1000)
		return 3;
	if(inp < 10000)
		return 4;
	if(inp < 100000)
		return 5;
	if(inp < 1000000)
		return 6;
	if(inp < 10000000)
		return 7;
	if(inp < 100000000)
		return 8;
	if(inp < 1000000000)
		return 9;
	if(inp < 10000000000)
		return 10;
	return -1;
}

LL to_pow(LL inp)
{
	if(inp == 0)
		return 0;
	if(inp == 1)
		return 1;
	if(inp == 2)
		return 10;
	if(inp == 3)
		return 100;
	if(inp == 4)
		return 1000;
	if(inp == 5)
		return 10000;
	if(inp == 6)
		return 100000;
	if(inp == 7)
		return 1000000;
	if(inp == 8)
		return 10000000;
	if(inp == 9)
		return 100000000;
		
}

#define SZ 20

LL prevs[SZ];
LL loc = 0;
void clear()
{
	memset(prevs, 0 , sizeof(LL) * SZ);
	loc = 0;
}

LL check(LL no)
{
	int l=0;
	while(l<loc)
	{
		if(prevs[l] == no)
			return 1;
		l++;
	}
	return 0;
}

void check_insert(LL no)
{
	if(!check(no))
	{
		prevs[loc++]=no;
	}
}

LL find_all(LL inp, LL b)
{
	LL sz = to_size(inp);
	LL l,tmp,rem;
	tmp = inp;
	clear();
	for(l=0;l<sz;l++)
	{
		rem = tmp%10;
		tmp/=10;
		tmp = tmp + (rem * to_pow(sz));
		if (tmp > inp && tmp <= b)
			check_insert (tmp);
	}
	return loc;
}

int main()
{
	LL t,l,a,b,i,ans;
	scanf("%lld",&t);
	for(l=0;l<t;l++)
	{
		ans=0;
		scanf("%lld %lld",&a,&b);
		for (i=a;i<=b;i++)
		{
			ans+=find_all(i,b);
		}
		printf("Case #%lld: %lld\n",l+1,ans);
	}
	return 0;
}
