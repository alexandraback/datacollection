#include<bits/stdc++.h>

using namespace std;

const int n=16,r=50;
unsigned int a;

int checkmod6()
{
	return __builtin_popcount(a)%6==0;
}

int check28()
{
	int ret=0;
	for(int i=0;i<n;i++)
		if ((a>>i)&1)
			ret+=i%2+1;
	return ret%3==0;
}

int check6()
{
	int ret=0;
	for(int i=0;i<n;i++)
		if ((a>>i)&1)
			if (i%2==0) ret++;
			else ret--;
	return ret%7==0;
}

long long powe(long long x,int y)
{
	long long ret=1;
	for(;y;y>>=1, x*=x) if (y&1) ret=ret*x;
	return ret;
}

const int check[9]={3, 2, 3, 2, 7, 2, 3, 2, 3};

void checkanswer()
{
	for(int i=2;i<=10;i++)
	{
		long long tmp=0;	
		for(int j=n-1;j>=0;j--)
			if ((a>>j)&1)
			{
				tmp+=powe(i, j);
			}
		if (tmp%check[i-2]!=0)
			printf("!!! error %u %d %lld\n", a, i, tmp);
	}
}

int main()
{
	//freopen("C.in","r",stdin);
	
	printf("Case #1:\n");
	a=1+(1u<<(n-1));
	int cnt=0;
	for(;;a+=2)
	{
		if (!checkmod6()) continue;
		if (!check28()) continue;
		if (!check6()) continue;
		for(int i=n-1;i>=0;i--)
			printf("%d",(a>>i)&1);
		for(int i=0;i<9;i++) printf(" %d", check[i]);
		printf("\n");
		//checkanswer();
		cnt++;
		if (cnt>=50) break;
		//printf("%u\n",a);
	}
	
	return 0;
}

