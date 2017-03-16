#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define SZ(a) (int)(a).size()
#define FILL(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; i++)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; i--)

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

int main()
{
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	int tc, ind=0; scanf("%d", &tc);

	while (tc --> 0)
	{
		ind++;
		
		LL r, t, res, ln, rn;
		scanf("%lld %lld", &r, &t);

		res = 0; ln = 1; rn = 2000000000000000000LL;
		while (ln<=rn)
		{
			LL m = (ln+rn)/2ll;
			if (2LL*r+1+2LL*(m-1)<=t/m)
			{
				res = m; ln = m+1;
			}
			else
				rn = m-1;
		}

		printf("Case #%d: %lld\n", ind, res);
	}

	return 0;
}