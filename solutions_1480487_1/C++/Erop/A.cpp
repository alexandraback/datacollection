#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const double EPS = 1e-9;

int N;
double S[200];
double sum;
bool can(int num, double p)
{
	double val = S[num] + sum*p;
	for (int i = 0; i < N; ++i)
	{
		if (S[i] >= val || i == num) continue;
		p += (val - S[i]) / sum;
	}
	return p >= 1;
}
double solve(int num)
{
	double l = 0, r = 1;
	for (int i = 0; i < 50; ++i)
	{
		double m = (l + r)/2;
		if (can(num, m))
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	return l;
}
void solve()
{	
	scanf ("%d", &N);
	sum = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf ("%lf", &S[i]);
		sum += S[i];
	}
	for (int i = 0; i < N; ++i)
	{
		printf("%.9lf ", solve(i)*100);
	}
	puts("");
}
int main()
{
#ifdef _DEBUG
	freopen("Atest.txt", "r", stdin);
	freopen("Aout.txt", "w", stdout);
#endif
	int T;
	scanf ("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}