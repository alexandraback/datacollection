#include <stdio.h>
#include <string.h>
#define clr(a,b) memset(a,b,sizeof(a))
const int N = 100000;
long long prime[N];
bool check[N];
int totp; // totp = 9592
void Eular()
{
	clr(check,false);
    totp = 0;
	for (int i = 2; i < N; i++)
	{
		if (!check[i]) prime[totp++] = i;
		for (int j = 0; j < totp; j++)
		{
			if (i * prime[j] >= N) break;
			check[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
const int bit = 16; // SMALL
long long b[11][bit];
void init()
{
	for(int base = 2; base <= 10; base++)
	{
		b[base][0] = 1;
		for(int i = 1; i < bit; i++)
			b[base][i] = b[base][i - 1] * base;
	}
}
int totans = 0;
int a[40];
int chk(long long x)
{
	for(int i = 0; i < totp; i++)
	{
		if(prime[i] >= x)
			return 0;
		if(x % prime[i] == 0)
			return prime[i];
	}
	return 0;
}
long long ans[11];
void tryto(long long x)
{
	long long tmp = x;
	for(int i = 0; i < bit; i++)
	{
		a[i] = tmp & 1LL;
		tmp >>= 1LL;
	}
	/*printf("TRY ");
	for(int i = bit - 1; i >= 0; i--)
		printf("%d", a[i]);
	puts("");*/
	for(int base = 2; base <=10; base++)
	{
		tmp = 0;
		for(int i = 0; i < bit; i++)
			tmp += b[base][i] * a[i];
		ans[base] = chk(tmp);
		//ans[base] = tmp;
		if(ans[base] == 0) return;
	}
	//totans++;
	for(int i = bit - 1; i >= 0; i--)
		printf("%d", a[i]);
	for(int base = 2; base <= 10; base++)
		printf(" %lld", ans[base]);
	puts("");
}

int main()
{
	Eular();
	init();
	//printf("%d\n", totp);
	// SMALL
	long long st = 1LL << 15LL;
	st += 1LL;
	long long ed = 1LL << 16LL;
	totans = 0;
	puts("Case #1:");
	for(long long i = st; i < ed; i += 2)
	{
		if(totans < 50) 
			tryto(i);
	} 
}