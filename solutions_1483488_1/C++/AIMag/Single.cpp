#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <vector>
#include <ctime>
#include <map>
#include <memory.h>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; i++)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; i--)
#define HAS(a, b) ((a).find(b) != (a).end())
#define SZ(a) (int)(a).size()
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

int Check(int A, int B)
{
	int ten = 1, k = 0, tmp = A;
	while (ten<=B) ten *= 10, k++; ten /= 10, k--;

	set<int> s;
	while (k --> 0)
	{
		tmp = tmp/10 + (tmp%10)*ten;
		if (A<tmp && tmp<=B)
			s.insert(tmp);
	}

	return SZ(s);
}

int main()
{
#ifdef ALMAG_LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc, ind=0; scanf("%d", &tc);

	while (tc --> 0)
	{
		int a, b; scanf("%d %d", &a, &b);

		int res = 0;
		FOR(i, a, b+1)
			res += Check(i, b);

		printf("Case #%d: %d\n", ++ind, res);
	}

    return 0;
}
