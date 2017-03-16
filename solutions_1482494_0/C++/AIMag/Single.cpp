#include <iostream>
#include <algorithm>
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

PII a[1<<10];
int n;

int Calc()
{
	int curr[1<<10], ind=0, res=0;
	bool fl[1<<10];
	FOR(i, 0, n) fl[i] = false, curr[i] = 0;

	while (ind < n)
	{
		if (curr[ind] >= a[ind].first) {
			curr[ind+1] = curr[ind]+2; if (fl[ind]) curr[ind+1]++; res++;
			ind++; continue;
		}

		int nom = -1;
		FOR(i, 0, ind)
			if (!fl[i])
				if (curr[i]>=a[i].second && (nom==-1 || a[i].second<a[nom].second)) {
					nom = i;
				}
		if (nom==-1)
		{
			FOR(i, ind, n)
				if (!fl[i])
					if (curr[ind] >= a[i].second) {
						nom = i; break;
					}
		}
		if (nom == -1) return nom;

		if (curr[ind] >= a[nom].second) {
			fl[nom] = true; res++;
			if (nom < ind) {
				FOR(i, 0, nom)
					if (curr[i] >= a[nom].second)
						curr[i]++;
				FOR(i, nom, ind+1) curr[i] += 2;
			}
			else
			{
				FOR(i, 0, ind+1)
					if (curr[i] >= a[nom].second)
						curr[i]++;
			}
		}
		else
			return -1;
	}

	return res;
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
		scanf("%d", &n);
		FOR(i, 0, n) scanf("%d %d", &a[i].second, &a[i].first);

		sort(a, a+n);

		printf("Case #%d: ", ++ind);
		int res = Calc();
		if (res == -1) {
			printf("Too Bad\n");
		}
		else
			printf("%d\n", res);
	}

    return 0;
}
