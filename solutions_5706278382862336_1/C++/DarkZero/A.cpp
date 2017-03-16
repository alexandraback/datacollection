#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b)
{
	if(a<b)
		swap(a,b);
	if(b==0)
		return a;
	if(a%b==0)
		return b;
	return gcd(b, a%b);
}

LL lcm(LL a, LL b)
{
	int factor = gcd(a,b);
	return a/factor * b;
}

struct ftype
{
	LL high, low;
	
	void cut()
	{
		LL factor = gcd(high, low);
		high/=factor;
		low/=factor;
		return;
	}
};

bool operator >= (const ftype &a, const ftype &b)
{
	LL com_low = lcm(a.low, b.low);
	LL factor_a = com_low / a.low;
	LL factor_b = com_low / b.low;
	
	LL tmp_a = a.high * factor_a;
	LL tmp_b = b.high * factor_b;
	return tmp_a >= tmp_b;
}

bool check(LL x)
{
	while(x!=1)
	{
		if(x%2!=0)
			return false;
		x/=2;
	}
	return true;
}

int t;

int main()
{
	freopen("A.txt", "r", stdin);
	freopen("A1.txt" , "w", stdout);
	scanf("%d", &t);
	int files;
	for(files=1; files<=t; files++)
	{
		long long h, l;
		scanf("%I64d/%I64d", &h, &l);
		
		ftype now;
		now.high = h;
		now.low = l;
		now.cut();
		
		printf("Case #%d: ", files);
		if( !check(now.low) )
		{
			printf("impossible\n");
			continue;
		}
		
		ftype compare;
		compare.high = 1;
		compare.low =1;
		bool found = false;
		int i;
		for(i=0;i<=40;i++)
		{
			if(now >= compare)
			{
				printf("%d\n", i);
				found = true;
				break;
			}
			compare.low *=2;
		}
		if(!found)
			printf("impossible\n");
	}
	//system("pause");
	return 0;
}














