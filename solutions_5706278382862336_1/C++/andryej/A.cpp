#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
char buff[100];
bool fail;

void parse(long long & a,long long & b)
{
	int i=0;
	while(buff[i]!='/')
		a=10*a + buff[i++]-'0';
	++i;
	while(buff[i])
		b=10*b + buff[i++]-'0';
}

long long gcd(long long a,long long b)
{
	while(b!=0){a%=b;swap(a,b);}
	return a;
}

int pow2(long long x)
{
	int k=0;
	while(x%2==0 and x)
	{
		++k;
		x>>=1;
	}
	return (x==1)?k:-1;
}

long long chck(long long a,long long b)
{
	int k = pow2(b);
	if (k==-1){ fail=true;return -1; }
	int m=0;
	while(a)
	{
		++m;
		a>>=1;
	}
	--m;
	return k-m;
}

int main()
{
	int cases;
	long long a,b;
	scanf("%d",&cases);
	for(int c=1;c<=cases;++c)
	{
		scanf("%s",buff);
		a=b=0;
		parse(a,b);
		long long d =gcd(a,b);
		fail = false;
		long long k = chck(a/d,b/d);
		printf("Case #%d: ",c);
		if (!fail)
			printf("%lld\n",k);
		else 
			puts("impossible");
	}	
}
