#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a, b;

double vet[100010];
double dp[100010][2];
int z[100010][2];
double mul[100010];

double solve1(int p, bool f)
{
	if (z[p][f] != -1) return dp[p][f];
	
	if (p == a)
	{
		if (!f) return 1+(b-a);
		return 1+(b-a)+b+1;
	}
	else
	{
		z[p][f] = 0;
		double& res = dp[p][f];
		res = 0;
		res += vet[p]*(solve1(p+1, f)); // pertou certo
		res += (1-vet[p])*(solve1(p+1, 1)); // pertou errado
		return res;
	}
}

double solve2(int p)
{
	double res = 1/0.0;
	for (int i = 0; i < a; ++i)
	{
		double ret = 0;
		// ok
		double tmp = mul[a-i-1];
		tmp *= (i+1)*2+(b-a)+1;
		ret += tmp;
		
		// fucked
		tmp = 1-mul[a-i-1];
		tmp *= (i+1)*2+(b-a)+1+b+1;
		ret += tmp;
		
		res = min(res, ret);
	}
	return res;
}

int main()
{
	int t;
	scanf("%d", &t);
	
	for (int q = 1; q <= t; ++q)
	{
		printf("Case #%d: ", q);
		scanf("%d%d", &a, &b);
		for (int i = 0; i < a; ++i)
			scanf("%lf", &vet[i]);
		mul[0] = 1;
		for (int i = 1; i <= a; ++i)
			mul[i] = vet[i-1]*mul[i-1];
		memset(z, -1, sizeof z);
		double res1 = solve1(0, 0);
		double res2 = solve2(0);
		double res3 = b+2;
		
		double res = min(res1, min(res2, res3));
		printf("%.6lf\n", res);
	}
	
	return 0;
}

