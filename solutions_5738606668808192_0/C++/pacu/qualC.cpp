#include <iostream>
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
		val[i] = 0;
		for(int j=N-1;j>=0;j--)
		{
			val[i] *= i;
			if(coin&(1<<j)) val[i]++;
		}
		long long div = 0;
		for(int j=0;j<L && primes[j]*primes[j]<=val[i];j++)
		{
			if(val[i]%primes[j]==0)
			{
				div = primes[j];
				break;
			}
		}
		if(div==0) return;
		ans[K][i] = div;
	}
	aval[K] = val[10];
	cout << aval[K];
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
	N = 16;
	cout << "Case #1:\n";
	for(int i=32769;i<65536;i+=2)
	{
		check(i);
		if(K==50) break;
	}
}