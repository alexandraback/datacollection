#include <iostream>
#include <string>
using namespace std;

int N,J;

long long ans[500][11];
long long aval[500];
int K;

int ps[120000001];
int primes[10000000];
int L;

void check(long long coin)
{
	long long val[11];
	for(int i=2;i<=10;i++)
	{
		long long div = 0;
		for(int j=0;j<100;j++)
		{
			val[i] = 0;
			for(int k=N-1;k>=0;k--)
			{
				val[i] = (val[i]*i)%primes[j];
				if(coin&(1LL<<k)) val[i] = (val[i]+1)%primes[j];
			}
			if(val[i]==0)
			{
				div = primes[j];
				break;
			}
		}
		if(div==0) return;
		ans[K][i] = div;
	}
	for(int j=N-1;j>=0;j--)
		cout << ((coin&(1LL<<j))>0);
	for(int i=2;i<=10;i++)
		cout << ' ' << ans[K][i];
	cout << '\n';
	K++;
}

int main()
{
	for(int i=2;i<=120000000;i++)
	{
		if(ps[i]==1) continue;
		for(int j=i+i;j<=120000000;j+=i)
			ps[j] = 1;
		primes[L++] = i;
	}
	N = 32;
	cout << "Case #1:\n";
	for(int i=(1LL<<31)+1;i<(1LL<<32);i+=2)
	{
		check(i);
		if(K==500) break;
	}
}