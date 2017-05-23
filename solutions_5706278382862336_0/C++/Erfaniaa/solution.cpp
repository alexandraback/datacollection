#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 100010


const long long maxOnes = (1ll << 40);
int t;
long long p, q;

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

inline long double abs2(long double x)
{
	if (x > 0)
		return x;
	return -x;
}

bool isInt(long double x)
{
	long long y = (long long)x;
	return (abs2(x - y) < 1e-13);
}

int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		int ans = 0;
		scanf("%lld/%lld", &p, &q);
		long long g = gcd(p, q);
		p /= g;
		q /= g;
		printf("Case #%d: ", tt);
		long double ones = (maxOnes * (p + 0.0)) / (q + 0.0);
		if (ones > maxOnes || !isInt(ones))
			printf("impossible\n");
		else
		{
			long long x = (long long)ones;
			for (int k = 0; k <= 40; k++)
				if (x >= (1ll << (40 - k)))
				{
					printf("%d\n", k);
					break;
				}
		}
	}
	return 0;
}