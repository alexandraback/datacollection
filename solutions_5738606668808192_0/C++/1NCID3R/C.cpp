#include <bits/stdc++.h>
using namespace std;

#define N 16
#define J 50

const int lim = 1<<(N/2);

int sieve[lim];
deque<int> primes;
int equiv[N];
int divisor[11];

int getval(int base, int mod)
{
	int total = 0;
	for(int i=N-1; i>=0; i--)
	{
		total = total*base + equiv[i];
		total %= mod;
	}

	return total;
}

int getdiv(int base)
{
	for(int i=0; i<primes.size(); i++)
	{
		int p = primes[i];
		if(getval(base,p)==0)
			return p;
	}

	return -1;
}

int main()
{
	//cout << lim << endl;
	for(int i=0; i<lim; i++)
		sieve[i] = i;

	for(int i=2; i<lim; i++)
	{
		//printf("%d %d\n",i,sieve[i]);
		if(sieve[i]==i)
		{
			primes.push_back(i);
			for(long long j=(long long)i*i; j<lim; j+=i)
				sieve[j] = i;
		}
	}

	//cout << primes.size() << endl;
	//return 0;

	printf("Case #1:\n");
	int cnt = 0;
	for(long long i=0; cnt<J; i++)
	{
		//printf("%d: ",i);
		long long curr = i;
		equiv[0] = equiv[N-1] = 1;
		for(int j=1; j<N-1; j++)
		{
			equiv[j] = curr&1;
			curr >>= 1;
		}
		/*
		for(int j=N-1; j>=0; j--)
			printf("%d",equiv[j]);
		printf(" ");
		*/

		int valid = 1;
		int p;
		for(int j=2; j<=10; j++)
		{
			if((p=getdiv(j))==-1)
			{
				//printf("Break at base %d\n",j);
				valid = 0;
				break;
			}

			divisor[j] = p;
		}

		if(valid)
		{
			cnt++;
			for(int j=N-1; j>=0; j--)
				printf("%d",equiv[j]);
			for(int j=2; j<=10; j++)
				printf(" %d",divisor[j]);
			puts("");
		}
	}
}