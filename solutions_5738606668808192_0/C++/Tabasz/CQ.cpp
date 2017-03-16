#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

LL P[15][20];
vector<int> V[101], R;
vector<LL> pr;
bool B[110000005];
int tmp;

void sieve()
{
	for(int i=2; i<=110000000; i++)
	{
		if(!B[i])
		{
			pr.PB(i);
			for(int j=i+i; j<=110000000; j+=i)
				B[j]=1;
		}
	}
}

LL getnum(int x, int y)
{
	LL r=0;
	for(int i=0; i<17; i++)
		if((x>>i)%2)
			r+=P[y][i];
	return r;
}

LL isprime(LL x)
{
	for(int i=0; pr[i]*pr[i]<=x; i++)
		if(x%pr[i]==0)
			return pr[i];
	return 0;
}

int main()
{
	sieve();
	//printf("%d %lld %lld\n", (int)pr.size(), pr[0], pr[1]);
	//ios_base::sync_with_stdio(0);
	for(LL j=2; j<=10; j++)
	{
		P[j][0]=1;
		for(int i=1; i<19; i++)
			P[j][i]=P[j][i-1]*j;
	}
	for(int i=P[2][15]; i<P[2][16]; i++)
	{
		if(i%2==0)
			continue;
		bool boo=1;
		for(int j=2; j<=10; j++)
		{
			LL x=getnum(i, j);
			//printf("%d %lld %d\n", i, x, j);
			if(isprime(x)==0)
			{
				boo=0;
				break;
			}
		}
		if(boo)
		{
			tmp++;
			R.PB(i);
		}
		if(tmp==50)
			break;
	}
	printf("Case #1:\n");
	for(int i=0; i<50; i++)
	{
		printf("%lld ", getnum(R[i], 10));
		for(int j=2; j<=10; j++)
			printf("%lld ", isprime(getnum(R[i], j)));
		printf("\n");
	}
	return 0;
}
