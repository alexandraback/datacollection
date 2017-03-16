#include <cstdio>

const int P_COUNT = 100;
const int MAX_N = 32;
const int MAX_BASE = 10;
int p[P_COUNT];

int mods[P_COUNT][MAX_BASE+1][MAX_N];
int max_conv[MAX_BASE+1];

int convert(unsigned int mask, int base);

void init()
{
	p[0] = 2;
	int c = 1;
	for (int n = 3; c < P_COUNT; n += 2)
	{
		bool prime = true;
		for (int i = 0; prime && i < c; ++i)
			if ((n % p[i]) == 0)
				prime = false;
		if (prime)
			p[c++] = n;
	}
	//for (int i = 0; i < P_COUNT; ++i)
	//	printf("%d\n", p[i]);

	for (int n = 0; n < P_COUNT; ++n)
	{
		for (int j = 2; j <= MAX_BASE; ++j)
		{
			int r = 1;
			for (int i = 0; i < MAX_N; ++i)
			{
				mods[n][j][i] = r;
				r = ((r * j) % p[n]);
			}
		}
	}
	for (int j = 2; j<= MAX_BASE; ++j)
		for (int mask = 1; ; mask += 2)
			if (convert(mask, j) > p[P_COUNT-1])
			{
				max_conv[j] = mask;
				break;
			}
}

bool check(unsigned int mask, int base, int n)
{
	int r = 0;
	//printf("%d %d %d\n", mask, base, n);
	for (int i=0, j=1; ; ++i, j<<=1)
	{
		//printf(" %d", mods[n][base][i]);
		if (j & mask)
			r += mods[n][base][i];
		if (j == (1<<31))
			break;
	}
	//printf(" = %d\n", r);
	return ((r % p[n]) == 0);
}

int convert(unsigned int mask, int base)
{
	int r = 0;
	for (int i=1, j=1; ; j<<= 1)
	{
		if (j & mask)
			r += i;
		i *= base;
		if (j == (1<<31))
			break;
	}
	return r;
}

int div[10];

bool check(unsigned int mask)
{
	for (int i=2; i<=10; ++i)
	{
		int j;
		if (mask >= max_conv[i])
		{
			for (j=0; j<P_COUNT; ++j)
				if (check(mask, i, j))
					break;
		}
		else
		{
			int v = convert(mask, i);
			for (j=0; j<P_COUNT; ++j)
				if ((v % p[j]) == 0)
					break;
		}
		if (j == P_COUNT)
			return false;
		div[i] = p[j];
	}
	return true;
}

int main()
{
	int T, N, J;
	init();
	scanf("%d", &T);
	for (int t=0; t<T; ++t)
	{
		unsigned int mask;
		scanf("%d %d", &N, &J);
		printf("Case #%d:\n", t+1);
		int c = 0;
		int maxm = (1<<(N-1))|((1<<(N-1))-1);
		for (mask = 1|(1<<(N-1)); c < J; mask+=2)
		{
			if (check(mask))
			{
				for (unsigned int i = 1<<(N-1); i; i>>=1)
					printf("%c", ((i&mask)?'1':'0'));
				for (int i = 2; i <= MAX_BASE; ++i)
					printf(" %d", div[i]);
				printf("\n");
				++c;
			}
			if (mask == maxm)
			{
				printf("FAILED");
				break;
			}
		}
	}
	return 0;
}