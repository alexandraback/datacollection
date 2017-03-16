#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll Max = 33333335;
bool notPrime[Max + 1000];
int Primes[Max];
int nPrime;
int T, N, J;

int Div[11];

int findDivisor(ll x)
{
	int i = 0;
	for( ;Primes[i]*Primes[i] <= x && x % Primes[i] != 0 ; ++i);
	if(x % Primes[i] == 0) return Primes[i];
	else return -1;
}
ll transform(ll base, ll n)
{
	if(base == 2) return n;
	ll resoult = 0;
	ll x = 1;
	for(int i = 0; i < 16; ++i)
	{
		if( (1 << i) & n)
			resoult += x;
		x *= base;
	}
	return resoult;
}
int main()
{
	scanf("%d%d%d", &T, &N, &J);
	for(ll i = 2; i < Max; ++i)
		if(notPrime[i] == false)
		{
			Primes[nPrime++] = i;
			for(ll j = i*i; j < Max; j += i)
				notPrime[j] = true;
		}
	puts("Case #1:");
	//printf("Znaleziono %d l pierwszych\n", nPrime+1);
	int found = 0;
	//int r = 0;
	for(int i = 32769; found < J && i < 2*32769; i += 2)
	{
		ll t;
		ll j;
		for(j = 2; j <= 10; ++j)
		{
			t = transform(j, i);
			Div[j] = findDivisor(t);
			if(Div[j] == -1) break;
		}
		if(Div[j] != -1)
		{
			printf("%lld ", transform(10, i));
			for(int i = 2; i <= 10; ++i)
				printf("%d ", Div[i]);
			puts("");
			++found;
		}
		//printf("i = %d\n", i);
	}
	
	return 0;
}
