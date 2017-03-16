#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>


const int N = 128;
int n;
char a[N], b[N];
long long powers[N];


bool fineA(int val, char c, int state)
{
	if(c != '?')
		return val == (c - '0');
	else
	{
		switch(state)
		{
		case 1: return val == 9;
		case 2: return val == 0;
		default: return true;
		}
	}
}

bool fineB(int val, char c, int state)
{
	if(c != '?')
		return val == (c - '0');
	else
	{
		switch(state)
		{
		case 1: return val == 0;
		case 2: return val == 9;
		default: return true;
		}
	}
}

int nextState(int ap, int bp, int s)
{
	if(s == 0 && ap < bp)
		return 1;
	if(s == 0 && ap > bp)
		return 2;

	return s;
}


long long labs(long long x)
{
	if(x < 0)
		return -x;
	else
		return x;
}


bool ok[N][4];
long long dp[N][4];
int turn_a[N][4];
int turn_b[N][4];

long long f(int p, int state)
{
	if(p >= n)
		return 0;

	if(ok[p][state])
		return dp[p][state];

	long long r = 0x7FFFFFFFFFFFFFFFLL;
	for(int ap = 0; ap < 10; ap++)
	{
		if(!fineA(ap, a[p], state))
			continue;
			
		for(int bp = 0; bp < 10; bp++)
		{
			if(!fineB(bp, b[p], state))
				continue;

			long long cur = (ap - bp) * powers[p] + f(p + 1, nextState(ap, bp, state));
			if(labs(cur) < labs(r))
			{
				r = cur;
				turn_a[p][state] = ap;
				turn_b[p][state] = bp;
			}
		}
	}
	
	
	dp[p][state] = r;
	ok[p][state] = true;

	return r;
}


void solve()
{
	n = strlen(a);
	assert(n == strlen(b));
	
	powers[n - 1] = 1;
	for(int i = n - 2; i >= 0; i--)
		powers[i] = 10LL * powers[i + 1];

	memset(ok, 0, sizeof(ok));
	f(0, 0);
	
	int state = 0;
	for(int p = 0; p < n; p++)
	{
		int ap = turn_a[p][state];
		int bp = turn_b[p][state];

		assert(a[p] == '?' || a[p] == '0' + ap);
		a[p] = '0' + ap;

		assert(b[p] == '?' || b[p] == '0' + bp);
		b[p] = '0' + bp;

		state = nextState(ap, bp, state);
	}

	printf("%s %s", a, b);
}

int main()
{
	int tests;
	scanf("%i\n", &tests);
	
	for(int test = 1; test <= tests; test++)
	{
		printf("Case #%i: ", test);
		scanf("%s %s\n", a, b);
		solve();
		printf("\n");
	}

	return 0;
}

