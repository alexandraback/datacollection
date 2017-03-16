//#pragma comment(linker, "/STACK:134217728")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

vector<Int> check(string s)
{
	int n = SIZE(s);
	int i, j;
	Int limit = 10LL << 50;
	Int primeLimit = 1LL << 10;
	vector<Int> res;
	FOR(i, 2, 11)
	{
		Int a = 0;
		Int b = 0;
		FOR(j, 0, n)
		{
			a *= i;
			b *= i;
			if (s[j] == '1') a++;
			if (a >= limit)
			{
				b += a / limit;
				a %= limit;
			}
		}

		Int d = 0;
		bool found = false;
		for (d = 2; d * d <= a && d < primeLimit; ++d)
			if ((a % d + (b % d) * (limit % d)) % d == 0)
			{
				res.push_back(d);
				found = true;
				break;
			}

		if (!found) return vector<Int>();
	}

	return res;
}

int SolveTest(int test)
{
	int N, J;
	scanf("%d%d", &N, &J);

	vector<pair<string, vector<Int>>> res;
	for (Int i = 0; i < (1LL << (N - 2)); ++i)
	{
		string s(N, '1');
		for (auto j = 0; j < N - 2; ++j)
			if ((i & (1LL << j)) == 0)
				s[N - 2 - j] = '0';

		auto r = check(s);
		if (SIZE(r) != 0)
		{
			res.push_back(MP(s, r));
			if (SIZE(res) == J)
				break;
		}
	}

	printf("Case #%d:\n", test + 1);
	for_each(res.begin(), res.end(), [](auto val) 
	{
		printf("%s", val.first.c_str()); 
		for_each(val.second.begin(), val.second.end(), [](auto val) { printf(" %lld", val); });
		printf("\n");
	});

	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	fgets(buf, 1 << 7, stdin);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
