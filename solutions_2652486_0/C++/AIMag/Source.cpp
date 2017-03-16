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

int a[10], k, n, m, r;

bool Can(int i1, int i2, int i3)
{
	FOR(i, 0, k)
	{
		bool res = false;
		res |= a[i]==1;
		res |= a[i]==i1;
		res |= a[i]==i2;
		res |= a[i]==i3;
		res |= a[i]==i1*i2;
		res |= a[i]==i2*i3;
		res |= a[i]==i1*i3;
		res |= a[i]==i1*i2*i3;

		if (!res) return false;
	}
	return true;
}

int main()
{
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	int tc, ind=0; scanf("%d", &tc);

	while (tc --> 0)
	{
		ind++;

		scanf("%d %d %d %d", &r, &n, &m, &k);

		printf("Case #%d:\n", ind);

		FOR(i, 0, r)
		{
			FOR(j, 0, k) scanf("%d", a+j);

			VI res;
			res.push_back(rand()%(m-1)+2);
			res.push_back(rand()%(m-1)+2);
			res.push_back(rand()%(m-1)+2);

			FOR(i1, 2, m+1)
				FOR(i2, 2, m+1)
					FOR(i3, 2, m+1)
						if (Can(i1, i2, i3))
						{
							res.clear();
							res.push_back(i1);
							res.push_back(i2);
							res.push_back(i3);
							goto ans;
						}

ans:
			printf("%d%d%d\n", res[0], res[1], res[2]);
		}
	}

	return 0;
}