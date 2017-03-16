#include<cstdio>
#include<set>
using namespace std;

int A,B,digit;

int countdigit(int n)
{
	int ret=0;
	while(n) { n/=10; ret++; }
	return ret;
}

void init()
{
	scanf("%d%d",&A,&B);
	digit=countdigit(A);
}

int cycle(int x)
{
	int ret=x%10;
	for(int i=1;i<digit;i++) ret*=10;
	return ret+x/10;
}

int count(int x)
{
	int ret=0;
	set<int> s;
	s.insert(x);
	for(int i=1;i<digit;i++)
	{
		x=cycle(x);
		if(x>=A && x<=B && s.find(x)==s.end())
		{
			ret++;
			s.insert(x);
		}
	}
	return ret;
}

int work()
{
	int ret=0;
	for(int i=A;i<=B;i++)
		ret+=count(i);
	return ret/2;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		init();
		printf("Case #%d: %d\n",i,work());
	}
	return 0;
}

