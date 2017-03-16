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

bool Enough(LL& t, LL r)
{
	LL need = 2LL*r+1;
	t -= need;

	return t>=0;
}

int main()
{
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	int tc, ind=0; scanf("%d", &tc);

	while (tc --> 0)
	{
		ind++;
		
		LL r, t, res;
		scanf("%lld %lld", &r, &t);

		for(res=0; Enough(t, r); r+=2, res++);

		printf("Case #%d: %lld\n", ind, res);
	}

	return 0;
}