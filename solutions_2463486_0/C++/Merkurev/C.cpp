#include <iostream>
#include <vector>
using namespace std;



const int N = 1e7 + 1;
bool good[N];


int v[15];


bool sym(long long x)
{
	int l = 0;
	while (x)
	{
		v[l++] = x % 10;
		x /= 10;
	}
	for (int i = 0; i < l; i++)
		if (v[i] != v[l - i - 1] )
			return false;
	return true;
}

bool gd(long long x)
{
	if (!sym(x) )
		return false;
	return sym(x * x);
}


int summLessOrEqual[N];

void precalc() 
{
	for (int i = 1; i < N; i++)
	{
		good[i] = gd(i);
		summLessOrEqual[i] = summLessOrEqual[i - 1] + (good[i] ? 1 : 0);
	}
}


int solve(long long x)
{
	long long l = 0, r = N;
	while (r - l > 1)
	{
		long long m = (l + r) / 2;
		if (m * m > x)
			r = m;
		else
			l = m;
	}
	return summLessOrEqual[l];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	precalc();


	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		long long a, b;
		scanf("%lld%lld", &a, &b);
		int ans = solve(b) - solve(a - 1);
		printf("Case #%d: %d\n", t + 1, ans);
	}


	return 0;
}